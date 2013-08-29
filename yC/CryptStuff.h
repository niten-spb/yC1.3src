/* CryptStuff.h --

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
//---------- OPTIONS MASK ----------
#define CHECK_SI_FLAG			0x01
#define ERASE_HEADER_FLAG		0x02
#define DESTROY_IMPORT_FLAG		0x04
#define CHECK_HEADER_CRC		0x08
#define ANTI_DUMP_FLAG			0x10
#define API_REDIRECT_FLAG		0x20

void CryptFile(char* szFname,DWORD dwProtFlags);
