/* yC.cpp : Defines the entry point for the application.

   This file is part of the "yoda Crypter v1.3".

   Copyright (C) 2004-2005 Ashkbiz Danehkar
   Copyright (C) 2000-2001 yoda/FReAK2FReAK
   All Rights Reserved.

   yoda Crypter v1.3 library are free software; you can redistribute them
   and/or modify them under the terms of the GNU General Public License as
   published by the Free Software Foundation.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYRIGHT.TXT.
   If not, write to the Free Software Foundation, Inc.,
   59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

   Ashkbiz Danehkar
   <ashkbiz@yahoo.com>
*/

#include "stdafx.h"
#include "yC.h"
#include "commdlg.h"
#include "commctrl.h"
#include "shellapi.h"
#include "PER.h"
#include "CryptStuff.h"

// Global Variables:
HINSTANCE hInst;		// current instance
OPENFILENAME ofn;
DWORD CryptFlags;
BOOL fStatus;
char cFname[256];
HDROP hDrop;
HICON hIcon;
char szCurDir[]=".";
char szFilter[]="ExE files (*.exe)|*.exe|All files (*.*)|*.*||";

// Forward declarations of functions included in this code module:
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
LRESULT DlgProc(HWND hDlg,UINT uMsg,WPARAM wParam,LPARAM lParam);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	MSG msg;
	hInst=GetModuleHandle(0);
	DialogBoxParam(hInst,MAKEINTRESOURCE(IDD_MAINDLG),0,(DLGPROC)DlgProc,0);
	ExitProcess(0);
	return (int) msg.wParam;
}

//  FUNCTION: DlgProc(HWND, unsigned, WORD, LONG)
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
LRESULT DlgProc(HWND hDlg,UINT uMsg,WPARAM wParam,LPARAM lParam)
{
	UINT wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	if(uMsg==WM_PROGRESS_MSG)
	{
		switch (wParam)
		{
		case SETSTEP_MSG:
			//m_cProgress.SetStep(lParam);
			break;
  
		case SETRANGE_MSG:
			//m_cProgress.SetRange(0,lParam);
			break;

		case SETPOS_MSG:
			//SetDlgItemInt(hDlg,IDC_PROGRESS1,lParam,TRUE);
			//m_cProgress.SetPos(lParam);
			break;
		}
	}
	switch (uMsg) 
	{
	case WM_INITDIALOG:
		hIcon=LoadIcon(hInst,MAKEINTRESOURCE(IDI_ICON));
		SendMessage(hDlg,WM_SETICON,TRUE,(WPARAM)hIcon);
		// check the checkboxes :)
		CheckDlgButton(hDlg,IDC_CHECKHEADERCRC,TRUE);
		CheckDlgButton(hDlg,IDC_DESTROYIMPORT,TRUE);
		CheckDlgButton(hDlg,IDC_ANTIDUMP,TRUE);
		CheckDlgButton(hDlg,IDC_APIREDIRECT,TRUE);
		DragAcceptFiles(hDlg,TRUE);
		break;   

	case WM_DROPFILES:
		hDrop=HDROP(wParam);
		DragQueryFile(hDrop,0,cFname,sizeof(cFname));
		DragFinish(hDrop);
		SetDlgItemText(hDlg,IDC_TARGETFILE,cFname);
		break;
	   
	case WM_COMMAND:
		wmId    = LOWORD(wParam); 
		wmEvent = HIWORD(wParam); 
		// Parse the menu selections:
		switch (wmId)
		{
		case IDCLOSE:
			SendMessage(hDlg,WM_CLOSE,NULL,NULL);
			break;
              
		case IDC_CHOOSEFILE:
			// get a file path
			cFname[0]=0x00;
			ZeroMemory(&ofn, sizeof(ofn));
			ofn.hwndOwner=GetActiveWindow();
			ofn.lpstrFile=cFname;
			ofn.nMaxFile=sizeof(cFname);
			ofn.lStructSize=sizeof(ofn);
			ofn.lpstrFilter=TEXT("ExE files (*.exe)\0*.exe;All files (*.*)\0*.*\0\0");
			ofn.nFilterIndex = 1; 
			//ofn.lpstrInitialDir=szCurDir;
			ofn.Flags=OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_LONGNAMES | OFN_HIDEREADONLY;
			fStatus =GetOpenFileName(&ofn);//(LPOPENFILENAME
			if(!fStatus)
			{
				return 0;
			}
			SetDlgItemText(hDlg,IDC_TARGETFILE,cFname);
			break;
	                  
		case IDC_CRYPT:
			// ----- was a file selected ? -----
			if(cFname==NULL)
			{
				MessageBox(hDlg,"No file selected up to now !","ERROR",MB_ICONERROR);
				return 0;
			}
			// ---- build the protection flag -----
			CryptFlags=0;
			if(IsDlgButtonChecked(hDlg,IDC_SICHECK)== BST_CHECKED)
			{
				CryptFlags=CryptFlags|CHECK_SI_FLAG;
			}
			if(IsDlgButtonChecked(hDlg,IDC_ERASEPEHEADER)== BST_CHECKED)
			{
				CryptFlags=CryptFlags|ERASE_HEADER_FLAG;
			}
			if(IsDlgButtonChecked(hDlg,IDC_DESTROYIMPORT)== BST_CHECKED)
			{
				CryptFlags=CryptFlags|DESTROY_IMPORT_FLAG;
			}
			if(IsDlgButtonChecked(hDlg,IDC_CHECKHEADERCRC)== BST_CHECKED)
			{
				CryptFlags=CryptFlags|CHECK_HEADER_CRC;
			}
			if(IsDlgButtonChecked(hDlg,IDC_ANTIDUMP)== BST_CHECKED)
			{
				CryptFlags=CryptFlags|ANTI_DUMP_FLAG;
			}
			if(IsDlgButtonChecked(hDlg,IDC_APIREDIRECT)== BST_CHECKED)
			{
				CryptFlags=CryptFlags|API_REDIRECT_FLAG;
			}
			CryptFile(cFname,CryptFlags);
			break;

		case IDOK:
			EndDialog(hDlg,0);
			break;

		case IDC_ABOUT:
			DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hDlg, (DLGPROC)About);
			break;
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hDlg, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_CLOSE:
		EndDialog(hDlg,0);
		break;
	}
	return 0;
}

LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
		{
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		break;
	}
	return FALSE;
}
