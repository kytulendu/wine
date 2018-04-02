/*
 * Win16 Thai API functions
 *
 * Copyright 2018 Nakarin Khankham
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#include <stdarg.h>
#include <string.h>

#include "windef.h"
#include "winbase.h"
#include "winuser.h"
#include "wine/winuser16.h"

#include "wine/debug.h"

WINE_DEFAULT_DEBUG_CHANNEL(user);

/***********************************************************************
 *           GetTaskInterface (USER.474)
 */
WORD WINAPI GetTaskInterface16( HTASK16 hTask )
{
    FIXME("(%p) stub\n", (void*)&hTask);
    return 0;
}


/***********************************************************************
 *           GetKeyboardLanguage (USER.475)
 */
WORD WINAPI GetKeyboardLanguage16(void)
{
    FIXME("stub\n");
    return 0;
}


/***********************************************************************
 *           SetKeyboardLanguage (USER.476)
 */
INT16 WINAPI SetKeyboardLanguage16( INT16 nKey )
{
    FIXME("(%d) stub\n", nKey);
    return 0;
}


/***********************************************************************
 *           SetLanguageToggleKey (USER.477)
 */
WORD WINAPI SetLanguageToggleKey16( INT16 nScan )
{
    FIXME("(%d) stub\n", nScan);
    return 0;
}


/***********************************************************************
 *           FindThaiWordBreak (USER.485)
 */
void WINAPI FindThaiWordBreak16( SEGPTR lpString, WORD nCount, SEGPTR lpWordBreak, WORD nWordCount )
{
    FIXME("(%p), (%u), (%p), (%u), stub\n",
            (void*)&lpString, nCount, (void*)&lpWordBreak, nWordCount);
}


/***********************************************************************
 *           ThaiCharType (USER.486)
 */
WORD WINAPI ThaiCharType16( BYTE cCh )
{
    FIXME("(%04x), stub\n", cCh);
    return 0;
}


/***********************************************************************
 *           IsInvalidKbdSeqBeep (USER.487)
 */
BOOL16 WINAPI IsInvalidKbdSeqBeep16(void)
{
    FIXME("stub\n");
    return 0;
}


/***********************************************************************
 *           SetInvalidKbdSeqBeep (USER.488)
 */
BOOL16 WINAPI SetInvalidKbdSeqBeep16( BOOL16 fBeep )
{
    FIXME("(%04x), stub\n", fBeep);
    return 0;
}


/***********************************************************************
 *           IsThaiCharCombinable (USER.489)
 */
BOOL WINAPI IsThaiCharCombinable16( BYTE char1, BYTE char2 )
{
    FIXME("(%04x, %04x), stub\n", char1, char2);
    return 0;
}


/***********************************************************************
 *           ThaiStrValid (USER.490)
 */
SEGPTR WINAPI ThaiStrValid16( SEGPTR lpString, WORD nCount )
{
    FIXME("(%p, %d), stub\n", (void*)&lpString, nCount);
    return 0;
}


/***********************************************************************
 *           ValidateThaiStr (USER.492)
 */
WORD WINAPI ValidateThaiStr16( SEGPTR lpSrc, SEGPTR lpDest, WORD nCount, BYTE cCh )
{
    FIXME("(%p, %p, %d, %04x), stub\n", (void*)&lpSrc, (void*)&lpDest, nCount, cCh);
    return 0;
}


/***********************************************************************
 *           CountThaiCharType (USER.492)
 */
WORD WINAPI CountThaiCharType16( SEGPTR lpString, WORD nCount, WORD Ntype )
{
    FIXME("(%p, %u, %04x), stub\n", (void*)&lpString, nCount, Ntype);
    return 0;
}


/***********************************************************************
 *           lstrDayName (USER.493)
 */
SEGPTR WINAPI lstrDayName16( WORD nDay, SEGPTR lpDest, WORD nFormat )
{
    FIXME("(%u, %p, %04x), stub\n", nDay, (void*)&lpDest, nFormat);
    return 0;
}


/***********************************************************************
 *           lstrMonthName (USER.494)
 */
SEGPTR WINAPI lstrMonthName16( WORD nMonth, SEGPTR lpDest, WORD nFormat )
{
    FIXME("(%u, %p, %04x), stub\n", nMonth, (void*)&lpDest, nFormat);
    return 0;
}


/***********************************************************************
 *           lstrYearNumber (USER.495)
 */
SEGPTR WINAPI lstrYearNumber16( WORD nYear, SEGPTR lpDest, WORD nFormat )
{
    FIXME("(%u, %p, %04x), stub\n", nYear, (void*)&lpDest, nFormat);
    return 0;
}


/***********************************************************************
 *           IsThaiKbdSeqCheck (USER.496)
 */
BOOL16 WINAPI IsThaiKbdSeqCheck16(void)
{
    FIXME("stub\n");
    return 0;
}


/***********************************************************************
 *           SetThaiKbdSeqCheck (USER.497)
 */
BOOL16 WINAPI SetThaiKbdSeqCheck16( BOOL16 fCheck )
{
    FIXME("(%04x), stub\n", fCheck);
    return 0;
}


/***********************************************************************
 *           SetTaskInterface (USER.498)
 */
WORD WINAPI SetTaskInterface16( HTASK16 hTask, WORD dwFlags )
{
    FIXME("(%p, %04x), stub\n", (void*)&hTask, dwFlags);
    return 0;
}
