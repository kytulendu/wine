/*
 * Thai KEYBOARD driver
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
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "windef.h"
#include "winbase.h"
#include "wingdi.h"
#include "winuser.h"
#include "winerror.h"
#include "wine/winuser16.h"
#include "wine/debug.h"

WINE_DEFAULT_DEBUG_CHANNEL(keyboard);

/**********************************************************************
 *      SetThaiKbdLayout (KEYBOARD.15)
 */
VOID WINAPI SetThaiKbdLayout16(INT16 nThaiKbd)
{
    FIXME("(%04x) stub\n", nThaiKbd);
}

/**********************************************************************
 *      GetThaiKbdLayout (KEYBOARD.16)
 */
INT16 WINAPI GetThaiKbdLayout16(void)
{
    FIXME("stub\n");
    /* Return Kedmanee keyboard layout */
    return 0;
}

/**********************************************************************
 *      lstrKbdThaiToEng (KEYBOARD.17)
 */
VOID WINAPI lstrKbdThaiToEng16(SEGPTR lpSrc, SEGPTR lpDest, WORD nCount, INT16 nThaiKbd)
{
    FIXME("(%p, %p, %04x, %04x) stub\n", (void*)&lpSrc, (void*)&lpDest, nCount, nThaiKbd);
}

/**********************************************************************
 *      lstrKbdEngToThai (KEYBOARD.18)
 */
VOID WINAPI lstrKbdEngToThai16(SEGPTR lpSrc, SEGPTR lpDest, WORD nCount, INT16 nThaiKbd)
{
    FIXME("(%p, %p, %04x, %04x) stub\n", (void*)&lpSrc, (void*)&lpDest, nCount, nThaiKbd);
}

/**********************************************************************
 *      lstrNumThaiToArabic (KEYBOARD.19)
 */
VOID WINAPI lstrNumThaiToArabic16(SEGPTR lpSrc, SEGPTR lpDest, WORD nCount)
{
    FIXME("(%p, %p, %04x) stub\n", (void*)&lpSrc, (void*)&lpDest, nCount);
}

/**********************************************************************
 *      lstrNumArabicToThai (KEYBOARD.20)
 */
VOID WINAPI lstrNumArabicToThai16(SEGPTR lpSrc, SEGPTR lpDest, WORD nCount)
{
    FIXME("(%p, %p, %04x) stub\n", (void*)&lpSrc, (void*)&lpDest, nCount);
}

/**********************************************************************
 *      SetBahtKey (KEYBOARD.21)
 */
VOID WINAPI SetBahtKey16(BOOL16 fBaht)
{
    FIXME("(%04x) stub\n", fBaht);
}

/**********************************************************************
 *      SetThaiCapsLockEffect (KEYBOARD.23)
 */
VOID WINAPI SetThaiCapsLockEffect16(BOOL16 fCaps)
{
    FIXME("(%04x) stub\n", fCaps);
}
