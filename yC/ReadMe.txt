--------------------------------------------------------------------------------------------

				-=[ yoda's Crypter ]=-

Version: 1.3
Release date:    July 2004
Based on yoda crypter version: 1.2

Now yoda's Crypter was made with Visual C++ 7.0 After 3 years of released 1.2 Version.
The last version was created by using Masm32. But Now every thing was built by last 
version of Visual C++ and 90 per cent of codes was translate to C++. This Software was
modified to support C++ builder and Delphi PE header. Moreover The Encryption and 
Decryption methods were improved by the aided C code.

Thanks:
-------
Yoda	          - for a original program
bitshape          - for good ideas in BitShape PE Crypt 1.5


For any comments/bugreports/suggestions contact me: ashkbiz@yahoo.com

Ashkbiz Danehkar

Visit: http://yodap.cjb.net/

--------------------------------------------------------------------------------------------

				-=[ yoda's Crypter ]=-

version: 1.2

Intro:
------
This is a small PE crypter with some nice protection options.
Send me a mail if u want 2 have the full MASM source code.
(I'll release the source if there's an unpacker for yC 1.2)

Protection features:
--------------------
- Polymorphic encryption
- Softice detection
- Anti Debug API's
- Erase PE Header
- Anti Dumping
- CRC checking
- Import Table encryption/destruction
- API Redirection

"Polymorphic encryption"
 Each file is en-/decrypted in a different way. Additionally the generated decryption
 routines contain ~50% junk code 2 make reversing a bit more difficult.

"Softice detection"-
 If the Softice will b detected then the protected exe will refuse 2 run.

"Anti Debug API's"-
 Protected files will refuse 2 run if it is debugged by the Debug API's
 ("WaitForDebugEvent" and "ContinueDebugEvent").

"Erase PE Header"-
 If u enable this option then the loader will destroy the whole PE Header
 on startup.
 B careful with this option !!! Test ur progs carefully after crypting a file
 with this option. There're especially on NT-based OS's probs.
 Generally it won't work correctly with bigger programs.

"Anti Process Dumping"-
 This will prevent lame dump engines like the ones of Procdump and PEditor
 (based on ReadProcessMemory) from dumping the whole process memory of the protected exe.
 yC uses the same method as PEShield 2 prevent a full dump. Much thx goes 2
 ANAKiN 4 releasing the source of it.

"CRC checking"-
 With this option enabled the loader will calculate a CRC 4 the encrypted file
 which will b compared with the original 1. If the protected file has been modified
 then the exe will refuse 2 run.

"Delete Import Information"-
 With this option enabled there won't b any Dll/Api names left in the file memory
 after startup.
 (All ImageImportDescripters are alread on disk not present.)
 
"API Redirection"-
 This will place the Api address in some allocated memory and not in the Import Table.

End of yC :(
-----------
If I don't find much bugs and don't have any very good ideas 4 sth 2 add then I won't 
code any new versions. So this is maybe the last version.
I though about Anti Loader and Anti API breakpoint stuff. Both wouldn't be hard
to realize but I want to keep the loader code small.

Known bugs/limitations:
-----------------------
- API's of MFC dlls won't be directed
- Maximum number of sections: 20
- Maximum number of ImageImportDescriptors: 29

Thanks:
-------
Henrik Nordhaus   - 4 a very nice piece of code and good ideas
Jeremy Collake    - 4 good ideas 2 handle TLS tables correct
M.o.D.            - 4 BETA testing and good ideas
DYCUS/Daedalus    - 4 pointing out the Softice detection bug
night             - 4 reporting that AVP decides yC protected files are virii's (fixed)


4 any comments/bugreports/suggestions contact me @ yoda_f2f@gmx.net

HaVe PhUn !!!

yoda/FReAK2FReAK

Visit: y0da.cjb.net
--------------------------------------------------------------------------------------------


