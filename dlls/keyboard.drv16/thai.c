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

#include "windef.h"
#include "winbase.h"
#include "winuser.h"
#include "wine/winuser16.h"
#include "wine/debug.h"

WINE_DEFAULT_DEBUG_CHANNEL(keyboard);

/* Thai API */
static INT16 THAI_KbdLayout = KL_KESMANEE;  /* Thai keyboard layout flags */

/**********************************************************************
 *      SetThaiKbdLayout (KEYBOARD.15)
 */
VOID WINAPI SetThaiKbdLayout16(INT16 nThaiKbd)
{
    TRACE("(%04x)\n", nThaiKbd);
    if ( (nThaiKbd == KL_KESMANEE) || (nThaiKbd == KL_PATTACHOTE) )
        THAI_KbdLayout = nThaiKbd;
    else
        FIXME("invaliad parameter! (%04x)\n", nThaiKbd);
}

/**********************************************************************
 *      GetThaiKbdLayout (KEYBOARD.16)
 */
INT16 WINAPI GetThaiKbdLayout16(void)
{
    TRACE("return (%04x)\n", THAI_KbdLayout);
    return THAI_KbdLayout;
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
    int i = 0;
    BOOL samePtr;
    char *src = MapSL(lpSrc);
    char *dest = MapSL(lpDest);

    TRACE("in (\"%s\", %u)\n", src, nCount);

    /* Have to check for same pointer usage
     * since some program use same pointer to do this */
    if (src == dest)
        samePtr = TRUE;
    else
        samePtr = FALSE;

    while ( (*src != '\0') && (i < nCount) )
    {
        /* If the character is Thai number */
        if ( ((unsigned char)*src >= THAIZERO) && ((unsigned char)*src <= THAININE) )
        {
            /* Convert it to Arabic number */
            if (samePtr)
                *src -= 0xC0;
            else
                *dest = (unsigned char)*src - 0xC0;
        }
        else
            if (!samePtr)
                *dest = *src;

        src++;
        if (!samePtr)
            dest++;
        i++;
    }
    TRACE("out (\"%s\", %d)\n", dest, i);
}

/**********************************************************************
 *      lstrNumArabicToThai (KEYBOARD.20)
 */
VOID WINAPI lstrNumArabicToThai16(SEGPTR lpSrc, SEGPTR lpDest, WORD nCount)
{
    int i = 0;
    BOOL samePtr;
    char *src = MapSL(lpSrc);
    char *dest = MapSL(lpDest);

    TRACE("in (\"%s\", %u)\n", src, nCount);

    /* Have to check for same pointer usage
     * since some program use same pointer to do this */
    if (src == dest)
        samePtr = TRUE;
    else
        samePtr = FALSE;

    while ( (*src != '\0') && (i < nCount) )
    {
        /* If the character is Arabic number */
        if ( ((unsigned char)*src >= 0x30) && ((unsigned char)*src <= 0x39) )
        {
            /* Convert it to Thai number */
            if (samePtr)
                *src += 0xC0;
            else
                *dest = (unsigned char)*src + 0xC0;
        }
        else
            if (!samePtr)
                *dest = *src;

        src++;
        if (!samePtr)
            dest++;
        i++;
    }
    TRACE("out (\"%s\", %d)\n", dest, i);
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
