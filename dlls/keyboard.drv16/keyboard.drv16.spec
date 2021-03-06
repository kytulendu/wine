1   pascal -ret16 Inquire(ptr) Inquire16
2   pascal -ret16 Enable(segptr ptr) Enable16
3   pascal -ret16 Disable() Disable16
4   pascal -ret16 ToAscii(word word ptr ptr word) ToAscii16
5   pascal -ret16 AnsiToOem(str ptr) AnsiToOem16
6   pascal -ret16 OemToAnsi(str ptr) OemToAnsi16
7   pascal -ret16 SetSpeed(word) SetSpeed16
#9   stub INQUIREEX
#10  stub TOASCIIEX
#11  stub VKKEYSCANEX
#12  stub MAPVIRTUALKEYEX
#13  stub NEWTABLEEX
#14  stub __EXPORTEDSTUB

# Thai API
8   pascal -ret16 TkEnable() TkEnable16
9   pascal TkDisable() TkDisable16
10  pascal -ret16 IsThaiExist() IsThaiExist16
11  pascal -ret16 GetThaiStatus() GetThaiStatus16               # Windows 3.0a Thai is GETTHAISTATUS, Windows 3.11 Thai is WEP
12  pascal -ret16 SetThaiStatus(word) SetThaiStatus16           # Windows 3.0a Thai is SETTHAISTATUS
13  pascal -ret16 SetCheckSequence(word) SetCheckSequence16     # Windows 3.0a Thai is SETCHECKSEQUENCE, Windows 3.11 Thai is __EXPORTEDSTUB
#14   stub WEP
15  pascal SetThaiKbdLayout(s_word) SetThaiKbdLayout16
16  pascal -ret16 GetThaiKbdLayout() GetThaiKbdLayout16
17  pascal lstrKbdThaiToEng(segptr segptr word s_word) lstrKbdThaiToEng16
18  pascal lstrKbdEngToThai(segptr segptr word s_word) lstrKbdEngToThai16
19  pascal lstrNumThaiToArabic(segptr segptr word) lstrNumThaiToArabic16
20  pascal lstrNumArabicToThai(segptr segptr word) lstrNumArabicToThai16
21  pascal SetBahtKey(word) SetBahtKey16
23  pascal SetThaiCapsLockEffect(word) SetThaiCapsLockEffect16

100	pascal	ScreenSwitchEnable(word) ScreenSwitchEnable16
#126	pascal	GetTableSeg
#127	pascal	NewTable
128 pascal OemKeyScan(word) OemKeyScan16
129 pascal -ret16 VkKeyScan(word) VkKeyScan16
130 pascal -ret16 GetKeyboardType(word) GetKeyboardType16
131 pascal -ret16 MapVirtualKey(word word) MapVirtualKey16
132 pascal -ret16 GetKBCodePage() GetKBCodePage16
133 pascal -ret16 GetKeyNameText(long ptr word) GetKeyNameText16
134 pascal -ret16 AnsiToOemBuff(ptr ptr word) AnsiToOemBuff16
135 pascal -ret16 OemToAnsiBuff(ptr ptr word) OemToAnsiBuff16
#136	pascal	EnableKbSysReq
#137	pascal	GetBiosKeyProc
