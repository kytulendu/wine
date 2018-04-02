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

/* Thai API */
static WORD THAI_Interface = 0;         /* Thai API interface flags */
static BOOL16 THAI_KbdSeqCheck = TRUE;  /* Thai API keyboard sequence check flags */

/***********************************************************************
 *           GetTaskInterface (USER.474)
 */
WORD WINAPI GetTaskInterface16( HTASK16 hTask )
{
    FIXME("(%p) semi-stub\n", (void*)&hTask);
    return THAI_Interface;
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
    /* TC_CONTROL 0x00-0x1F, 0x7F-0x84, 0x86-0x90, 0x98-0x9F, 0xFF */
    if (( cCh <= 0x1F ) ||
        (( cCh >= 0x7F ) && ( cCh <= 0x84 )) ||
        (( cCh >= 0x86 ) && ( cCh <= 0x90 )) ||
        ( cCh == 0xFF ))
        return TC_CONTROL;

    /* TC_SYMBOL 0x20-0x2F, 0x3A-0x40, 0x5B-0x60, 0x7B-0x7E, 0x85, 0x91-0x97 */
    if ((( cCh >= 0x20 ) && ( cCh <= 0x2F )) ||
        (( cCh >= 0x3A ) && ( cCh <= 0x40 )) ||
        (( cCh >= 0x5B ) && ( cCh <= 0x60 )) ||
        (( cCh >= 0x7B ) && ( cCh <= 0x7E )) ||
        ( cCh == 0x85 ) ||
        (( cCh >= 0x91 ) && ( cCh <= 0x97 )))
        return TC_SYMBOL;

    if (isdigit(cCh))
        return TC_NUMERAL;

    if (isupper(cCh))
        return TC_UPPERCASE;

    if (islower(cCh))
        return TC_LOWERCASE;

    /* Test for Thai character */
    switch (cCh)
    {
        /* 0xA1-0xC3, 0xC5, 0xC7-0xCE */
        case KOKAI:         case KHOKHAI:       case KHOKHUAT:  case KHOKHWAI:
        case KHOKHON:       case KHORAKHANG:    case NGONGU:    case CHOCHAN:
        case CHOCHING:      case CHOCHANG:      case SOSO:      case CHOCHOE:
        case YOYING:        case DOCHADA:       case TOPATAK:   case THOTHAN:
        case THONANGMONTHO: case THOPHUTHAO:    case NONEN:     case DODEK:
        case TOTAO:         case THOTHUNG:      case THOTHAHAN: case THOTHONG:
        case NONU:          case BOBAIMAI:      case POPLA:     case PHOPHUNG:
        case FOFA:          case PHOPHAN:       case FOFAN:     case PHOSAMPHAO:
        case MOMA:          case YOYAK:         case RORUA:
        case LOLING:
        case WOWAEN:        case SOSALA:        case SORUSI:    case SOSUA:
        case HOHIP:         case LOCHULA:       case OANG:      case HONOKHUK:
            return TC_CONSONANT;

        /* 0xCF, 0xDB-0xDF, 0xEF, 0xFA-0xFE */
        case PAIYANNOI:     case 0xDB:          case 0xDE:      case BAHT:
        case MAIYAMOK:      case FONGMAN:       case ANGKHANKHU:case KHOMUT:
        case 0xFC:          case 0xFE:
            return TC_THAISYMBOL;

        /* 0xE0-0xE4 */
        case SARA_E:        case SARA_AE:       case SARA_O:    case MAIMUAN:
        case MAIMALAI:
            return TC_LEADVOWEL;

        /* 0xC4, 0xC6, 0xD0, 0xD2, 0xE5 */
        case RU:            case LU:            case SARA_A:    case SARA_AA:
        case LAKKHANGYAO:
            return TC_FOLLOWVOWEL;

        /* 0xD1, 0xD4-0xD7 */
        case MAIHUNAKAT:    case SARA_I:        case SARA_II:   case SARA_UE:
        case SARA_UEE:
            return TC_ABOVEVOWEL;

        /* 0xD8, 0xD9 */
        case SARA_U:        case SARA_UU:
            return TC_BELOWVOWEL;

        /* 0xD3, 0xE7, 0xED, 0xEE */
        case MAITAIKHU:     case NIKHAHIT:      case YAMAKKAN:
            return TC_ABOVEDIACRITIC1;

        /* 0xEC */
        case THANTHAKHAT:
            return TC_ABOVEDIACRITIC2;

        /* 0xDA */
        case PHINTHU:
            return TC_BELOWDIACRITIC;

        /* 0xE7, 0xED, 0xEE */
        case MAIEK:         case MAITHO:        case MAITRI:    case MAICHATTAWA:
            return TC_TONEMARK;

        /* 0xF0-0xF9 */
        case THAIZERO:
        case THAIONE:
        case THAITWO:
        case THAITHREE:
        case THAIFOUR:
        case THAIFIVE:
        case THAISIX:
        case THAISEVEN:
        case THAIEIGHT:
        case THAININE:
            return TC_THAINUMERAL;

        /* According to the Windows 3.1 Thai Edition SDK document.
         * Sara Am is TC_FOLLOWVOWEL, but on Windows 3.1 Thai Edition it also TC_ABOVEDIACRITIC1 */
        case SARA_AM:
            return TC_FOLLOWVOWEL | TC_ABOVEDIACRITIC1;

        /* On Windows 3.1 Thai Edition, These character are TC_THAISYMBOL */
        case 0xA0:
        case 0xDC:
        case 0xDD:
        case 0xFD:
            return TC_THAISYMBOL;
    }

    return 1;
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
    int i;
    WORD count = 0;
    char *ptr = MapSL(lpString);
    int lenght = strlen(ptr);

    TRACE("(\"%s\", %u, %04x)\n", ptr, nCount, Ntype);

    for(i = 0; i < nCount; i++)
    {
        if( ( nCount > lenght ) && ( *ptr == '\0' ) )
            break;

        if( ThaiCharType16( *ptr ) & Ntype )
        {
            count++;
        }

        ptr++;
    }

    TRACE("count %d\n", count);

    return count;
}


/***********************************************************************
 *           lstrDayName (USER.493)
 */
SEGPTR WINAPI lstrDayName16( WORD nDay, SEGPTR lpDest, WORD nFormat )
{
    static const char *engLongDay[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
    };
    static const char *engShortDay[] =  {
        "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
    };
    static const char *thaiLongDay[] = {
        "\xC7\xD1\xB9\xCD\xD2\xB7\xD4\xB5\xC2\xEC",     /* วันอาทิตย์ */
        "\xC7\xD1\xB9\xA8\xD1\xB9\xB7\xC3\xEC",         /* วันจันทร์ */
        "\xC7\xD1\xB9\xCD\xD1\xA7\xA4\xD2\xC3",         /* วันอังคาร */
        "\xC7\xD1\xB9\xBE\xD8\xB7\xB8",                 /* วันพุทธ */
        "\xC7\xD1\xB9\xBE\xC4\xCB\xD1\xCA\xBA\xB4\xD5", /* วันพฤหัสบดี */
        "\xC7\xD1\xB9\xC8\xD8\xA1\xC3\xEC",             /* วันศุกร์ */
        "\xC7\xD1\xB9\xE0\xCA\xD2\xC3\xEC"              /* วันเสาร์ */
    };
    static const char *thaiShortDay[] = {
        "\xCD\xD2",     /* อา */
        "\xA8",         /* จ */
        "\xCD",         /* อ */
        "\xBE",         /* พ */
        "\xBE\xC4",     /* พฤ */
        "\xC8",         /* ศ */
        "\xCA"          /* ส */
    };

    char *dest = MapSL(lpDest);
    char szDateForm[60];
    int i;
    int iLenght = 0;
    int iCounter = 0;
    int iThaiDate = 0;

    TRACE("(%u, %p, %04x)\n", nDay, (void*)&lpDest, nFormat);

    switch ( nFormat )
    {
        case ( TS_ENG | TS_LONG ):
            TRACE("Format: TS_ENG | TS_LONG\n");
            strcpy(dest, engLongDay[nDay]);
            break;
        case ( TS_ENG | TS_SHORT ):
            TRACE("Format: TS_ENG | TS_SHORT\n");
            strcpy(dest, engShortDay[nDay]);
            break;
        case ( TS_THAI | TS_LONG ):
            TRACE("Format: TS_THAI | TS_LONG\n");
            strcpy(dest, thaiLongDay[nDay]);
            break;
        case ( TS_THAI | TS_SHORT ):
            TRACE("Format: TS_THAI | TS_SHORT\n");
            strcpy(dest, thaiShortDay[nDay]);
            break;
        default:
            iThaiDate = GetProfileIntA( "Thai", "iThaiDate", 1 );
            if(iThaiDate)
                /* load setting from WIN.INI
                * Default is "dddd'ที่ 'd' 'MMMM' พ.ศ. 'yyyy" */
                iLenght = GetProfileStringA( "Thai", "sLongDate", "dddd'\xB8\xD5\xE8 'd' 'MMMM' \xBE.\xC8. 'yyyy",
                                            (LPSTR)szDateForm, sizeof(szDateForm) );
            else
                iLenght = GetProfileStringA( "intl", "sLongDate", "dd MMMM yyyy",
                                            (LPSTR)szDateForm, sizeof(szDateForm) );

            for ( i = 0; i < iLenght && szDateForm[i] != '\0'; i++ )
            {
                switch(szDateForm[i])
                {
                    case 'd':
                        iCounter = 1;
                        while( szDateForm[i+1] == 'd' )
                        {
                            iCounter++;
                            i++;
                        }
                        switch(iCounter)
                        {
                            case 1:
                            case 2:
                                break;
                            case 3:
                                if(iThaiDate)
                                    strcpy(dest, thaiShortDay[nDay]);
                                else
                                    strcpy(dest, engShortDay[nDay]);
                                break;
                            case 4:
                            default:
                                if(iThaiDate)
                                    strcpy(dest, thaiLongDay[nDay]);
                                else
                                    strcpy(dest, engLongDay[nDay]);
                                break;
                        }
                    default:
                        break;
                }
            }
    }

    TRACE("%s\n", dest);

    return lpDest;
}


/***********************************************************************
 *           lstrMonthName (USER.494)
 */
SEGPTR WINAPI lstrMonthName16( WORD nMonth, SEGPTR lpDest, WORD nFormat )
{
    static const char *engLongMonth[] = {
        "January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
    };
    static const char *engShortMonth[] =  {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec"
    };
    static const char *thaiLongMonth[] = {
        "\xC1\xA1\xC3\xD2\xA4\xC1",                 /* มกราคม */
        "\xA1\xD8\xC1\xC0\xD2\xBE\xD1\xB9\xB8\xEC", /* กุมภาพันธ์ */
        "\xC1\xD5\xB9\xD2\xA4\xC1",                 /* มีนาคม */
        "\xE0\xC1\xC9\xD2\xC2\xB9",                 /* เมษายน */
        "\xBE\xC4\xC9\xC0\xD2\xA4\xC1",             /* พฤษภาคม */
        "\xC1\xD4\xB6\xD8\xB9\xD2\xC2\xB9",         /* มิถุนายน */
        "\xA1\xC3\xA1\xAE\xD2\xA4\xC1",             /* กรกฏาคม */
        "\xCA\xD4\xA7\xCB\xD2\xA4\xC1",             /* สิงหาคม */
        "\xA1\xD1\xB9\xC2\xD2\xC2\xB9",             /* กันยายน */
        "\xB5\xD8\xC5\xD2\xA4\xC1",                 /* ตุลาคม */
        "\xBE\xC4\xC8\xA8\xD4\xA1\xD2\xC2\xB9",     /* พฤศจิกายน */
        "\xB8\xD1\xB9\xC7\xD2\xA4\xC1",             /* ธันวาคม */
    };
    static const char *thaiShortMonth[] = {
        "\xC1\x2E\xA4\x2E",     /* ม.ค. */
        "\xA1\x2E\xBE\x2E",     /* ก.พ. */
        "\xC1\xD5\x2E\xA4\x2E", /* มี.ค. */
        "\xE0\xC1\x2E\xC2\x2E", /* เม.ย. */
        "\xBE\x2E\xA4\x2E",     /* พ.ค. */
        "\xC1\xD4\x2E\xC2\x2E", /* มิ.ย. */
        "\xA1\x2E\xA4\x2E",     /* ก.ค. */
        "\xCA\x2E\xA4\x2E",     /* ส.ค. */
        "\xA1\x2E\xC2\x2E",     /* ก.ย. */
        "\xB5\x2E\xA4\x2E",     /* ต.ค. */
        "\xBE\x2E\xC2\x2E",     /* พ.ย. */
        "\xB8\x2E\xA4\x2E",     /* ธ.ค. */
    };

    char *dest = MapSL(lpDest);
    char szDateForm[60];
    int i;
    int iLenght = 0;
    int iCounter = 0;
    int iThaiDate = 0;

    TRACE("(%u, %p, %04x)\n", nMonth, (void*)&lpDest, nFormat);

    switch ( nFormat )
    {
        case ( TS_ENG | TS_LONG ):
            TRACE("Format: TS_ENG | TS_LONG\n");
            strcpy(dest, engLongMonth[nMonth]);
            break;
        case ( TS_ENG | TS_SHORT ):
            TRACE("Format: TS_ENG | TS_SHORT\n");
            strcpy(dest, engShortMonth[nMonth]);
            break;
        case ( TS_THAI | TS_LONG ):
            TRACE("Format: TS_THAI | TS_LONG\n");
            strcpy(dest, thaiLongMonth[nMonth]);
            break;
        case ( TS_THAI | TS_SHORT ):
            TRACE("Format: TS_THAI | TS_SHORT\n");
            strcpy(dest, thaiShortMonth[nMonth]);
            break;
        default:
            iThaiDate = GetProfileIntA( "Thai", "iThaiDate", 1 );
            if(iThaiDate)
                /* load setting from WIN.INI
                * Default is "dddd'ที่ 'd' 'MMMM' พ.ศ. 'yyyy" */
                iLenght = GetProfileStringA( "Thai", "sLongDate", "dddd'\xB8\xD5\xE8 'd' 'MMMM' \xBE.\xC8. 'yyyy",
                                            (LPSTR)szDateForm, sizeof(szDateForm) );
            else
                iLenght = GetProfileStringA( "intl", "sLongDate", "dd MMMM yyyy",
                                            (LPSTR)szDateForm, sizeof(szDateForm) );

            for ( i = 0; i < iLenght && szDateForm[i] != '\0'; i++ )
            {
                switch(szDateForm[i])
                {
                    case 'M':
                        iCounter = 1;
                        while( szDateForm[i+1] == 'M' )
                        {
                            iCounter++;
                            i++;
                        }
                        if (iCounter > 2)
                            if(iThaiDate)
                                strcpy(dest, thaiLongMonth[nMonth]);
                            else
                                strcpy(dest, engLongMonth[nMonth]);
                        else
                            if(iThaiDate)
                                strcpy(dest, thaiShortMonth[nMonth]);
                            else
                                strcpy(dest, engShortMonth[nMonth]);
                        break;
                    default:
                        break;
                }
            }
    }

    TRACE("%s\n", dest);

    return lpDest;
}


/***********************************************************************
 *           lstrYearNumber (USER.495)
 */
SEGPTR WINAPI lstrYearNumber16( WORD nYear, SEGPTR lpDest, WORD nFormat )
{
    char *dest = MapSL(lpDest);
    char szDateForm[60];
    int i;
    int iLenght = 0;
    int iCounter = 0;
    int iThaiDate = 0;

    TRACE("(%u, %p, %04x), not-complete\n", nYear, (void*)&lpDest, nFormat);

    /* Ignore short (two digits) year format */
    switch ( nFormat )
    {
        case ( TS_ENG | TS_LONG ):
            TRACE("Format: TS_ENG | TS_LONG\n");
            sprintf(dest, "%u", nYear );
            break;
        case ( TS_ENG | TS_SHORT ):
            TRACE("Format: TS_ENG | TS_SHORT\n");
            sprintf(dest, "%u", nYear % 100 );
            break;
        case ( TS_THAI | TS_LONG ):
            TRACE("Format: TS_THAI | TS_LONG\n");
            sprintf(dest, "%u", nYear + 543 );  /* Convert Christian era to Buddhist era */
            break;
        case ( TS_THAI | TS_SHORT ):
            TRACE("Format: TS_THAI | TS_SHORT\n");
            sprintf(dest, "%2u", ( nYear + 543 ) % 100 );  /* Convert Christian era to Buddhist era, display only 2 digits */
            break;
        default:
            iThaiDate = GetProfileIntA( "Thai", "iThaiDate", 1 );
            if(iThaiDate)
                /* load setting from WIN.INI
                * Default is "dddd'ที่ 'd' 'MMMM' พ.ศ. 'yyyy" */
                iLenght = GetProfileStringA( "Thai", "sLongDate", "dddd'\xB8\xD5\xE8 'd' 'MMMM' \xBE.\xC8. 'yyyy",
                                            (LPSTR)szDateForm, sizeof(szDateForm) );
            else
                iLenght = GetProfileStringA( "intl", "sLongDate", "dd MMMM yyyy",
                                            (LPSTR)szDateForm, sizeof(szDateForm) );

            for ( i = 0; i < iLenght && szDateForm[i] != '\0'; i++ )
            {
                switch(szDateForm[i])
                {
                    case 'y':
                        iCounter = 1;
                        while( szDateForm[i+1] == 'y' )
                        {
                            iCounter++;
                            i++;
                        }
                        if (iCounter > 2)
                            if(iThaiDate)
                                sprintf(dest, "%u", nYear + 543);
                            else
                                sprintf(dest, "%u", nYear);
                        else
                            if(iThaiDate)
                                sprintf(dest, "%2u", ( nYear + 543 ) % 100);
                            else
                                sprintf(dest, "%2u", nYear % 100);
                        break;
                    default:
                        break;
                }
            }
    }

    TRACE("%s\n", dest);

    return lpDest;
}


/***********************************************************************
 *           IsThaiKbdSeqCheck (USER.496)
 */
BOOL16 WINAPI IsThaiKbdSeqCheck16(void)
{
    return THAI_KbdSeqCheck;
}


/***********************************************************************
 *           SetThaiKbdSeqCheck (USER.497)
 */
BOOL16 WINAPI SetThaiKbdSeqCheck16( BOOL16 fCheck )
{
    THAI_KbdSeqCheck = fCheck;
    return TRUE;
}


/***********************************************************************
 *           SetTaskInterface (USER.498)
 */
WORD WINAPI SetTaskInterface16( HTASK16 hTask, WORD dwFlags )
{
    FIXME("(%p, %04x), semi-stub\n", (void*)&hTask, dwFlags);
    THAI_Interface = dwFlags;
    return 1;
}
