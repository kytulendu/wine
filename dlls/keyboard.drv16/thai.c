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
        if ( nThaiKbd != KL_CURRENT )
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
 *
 * Converts English keyboard input to the same keystroke
 * in Thai keyboard input.
 *
 * PARAMS
 *    lpSrc   [I]  English null-terminated string that was typed while
 *                 keyboard language was in English but the user think
 *                 it was Thai
 *    lpDest  [O]  Converted null-terminated string
 *    nCount  [I]  Specifies number of characters in lpSrc to process
 *    nThaiKbd[I]  Specifies Thai keyboard layout
 *
 * NOTE
 *    This function doesn't affect any Thai character in lpSrc
 *
 */
VOID WINAPI lstrKbdEngToThai16(SEGPTR lpSrc, SEGPTR lpDest, WORD nCount, INT16 nThaiKbd)
{
    static const char kbdEngToThai[2][128] =
    {
        /* 0 = Kedmanee */
        {
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
            0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
            0x20, 0x2B, 0x2E, 0xF2, 0xF3, 0xF4, 0xDF, 0xA7, 0xF6, 0xF7, 0xF5, 0xF9, 0xC1, 0xA2, 0xE3, 0xBD,
            0xA8, 0xE5, 0x2F, 0x2D, 0xC0, 0xB6, 0xD8, 0xD6, 0xA4, 0xB5, 0xAB, 0xC7, 0xB2, 0xAA, 0xCC, 0xC6,
            0xF1, 0xC4, 0xDA, 0xA9, 0xAF, 0xAE, 0xE2, 0xAC, 0xE7, 0xB3, 0xEB, 0xC9, 0xC8, 0x3F, 0xEC, 0xCF,
            0xAD, 0xF0, 0xB1, 0xA6, 0xB8, 0xEA, 0xCE, 0x22, 0x29, 0xED, 0x28, 0xBA, 0xA3, 0xC5, 0xD9, 0xF8,
            0x5F, 0xBF, 0xD4, 0xE1, 0xA1, 0xD3, 0xB4, 0xE0, 0xE9, 0xC3, 0xE8, 0xD2, 0xCA, 0xB7, 0xD7, 0xB9,
            0xC2, 0xE6, 0xBE, 0xCB, 0xD0, 0xD5, 0xCD, 0xE4, 0xBB, 0xD1, 0xBC, 0xB0, 0xA5, 0x2C, 0x25, 0x7F
        },
        /* 1 = Pattachote */
        {
            0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
            0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,
            0x20, 0x2B, 0xB1, 0x2F, 0x2C, 0x3F, 0x5F, 0xA2, 0x28, 0x29, 0x2E, 0x25, 0xD0, 0xF1, 0xA8, 0xBE,
            0xF0, 0x3D, 0xF2, 0xF3, 0xF4, 0xF5, 0xD9, 0xF7, 0xF8, 0xF9, 0xA6, 0xE4, 0xBF, 0xF6, 0xA9, 0xCC,
            0x22, 0xEB, 0xD1, 0xB0, 0xD3, 0xE6, 0xB3, 0xEC, 0xD7, 0xAB, 0xBC, 0xAA, 0xE2, 0xCE, 0xC8, 0xB6,
            0xB2, 0xEA, 0xAD, 0xB8, 0xC9, 0xBD, 0xC0, 0xC4, 0xAF, 0xD6, 0xAE, 0xE3, 0xDA, 0xAC, 0xD8, 0x2D,
            0x5F, 0xE9, 0xD4, 0xC5, 0xA7, 0xC2, 0xA1, 0xD1, 0xD5, 0xC1, 0xD2, 0xB9, 0xE0, 0xCA, 0xA4, 0xC7,
            0xE1, 0xE7, 0xCD, 0xB7, 0xC3, 0xB4, 0xCB, 0xB5, 0xBB, 0xE8, 0xBA, 0xCF, 0xED, 0xC6, 0xDF, 0x7F
        }
    };

    int i = 0;
    int kbd = KL_KESMANEE;
    BOOL samePtr;
    char temp;
    char *src = MapSL(lpSrc);
    char *dest = MapSL(lpDest);

    TRACE("in \"%s\", %u\n", src, nCount);

    /* Just in case some program use same pointer for source and destination */
    if (src == dest)
        samePtr = TRUE;
    else
        samePtr = FALSE;

    if(nThaiKbd == KL_CURRENT)
        kbd = THAI_KbdLayout;
    else
        kbd = nThaiKbd;

    while ( (*src != '\0') && (i < nCount) )
    {
        if ((unsigned char)*src > 0x80)
        {
            if (!samePtr)
                *dest = *src;
        }
        else
        {
            temp = kbdEngToThai[kbd][(unsigned int)*src];

            if (samePtr)
                *src = temp;
            else
                *dest = temp;
        }

        src++;
        if (!samePtr)
            dest++;

        i++;
    }
    TRACE("out \"%s\"\n", dest);
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
