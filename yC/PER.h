/* PER.h --

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
#pragma once

#define PROGRESS_MSG	"LWIDMsg"
#define SETSTEP_MSG		0x01
#define SETRANGE_MSG	0x02
#define SETPOS_MSG		0x03

extern UINT WM_PROGRESS_MSG;

void InitRandom();
void EncryptBuff(char* Base,DWORD dwRV,DWORD Size);
void DecryptBuff(char* Base,DWORD dwRV,DWORD Size);
void MakePER(char* pEncryptBuff,char* pDecryptBuff,DWORD dwSize);
