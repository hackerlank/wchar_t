#include "wchar_opp.h"
#include <stdlib.h>
#include <assert.h>
#include <wchar.h>
#include <string.h>
#include <stdio.h>

/**
 * @brief wchar转换为char
 */
char * wchartochar(wchar_t wchar)
{
    char * p = NULL;
    int len = sizeof(wchar);
    if (wchar < 128) //一个字节
    {
        p = (char *)malloc(2 * sizeof(char));
        if (!p)
            return NULL;
        //size_t wcstombs(char *dest, const wchar_t *src, size_t n);
        wcstombs(p, &wchar, len); 
        p[1] = '\0';        
    }
    else    //大于一个字节
    {
        p = (char *)malloc(3 * sizeof(char));
        if (!p)
            return NULL;
        //size_t wcstombs(char *dest, const wchar_t *src, size_t n);
        wcstombs(p, &wchar, len); 
        p[2] = '\0';
    }
    return p;
}

/**
 * @brief wchar * 转换为char *
 */
char * wcharstochar(const wchar_t * pWchar)
{
    assert (pWchar != NULL); 
    size_t len = wcslen(pWchar);
    char * pCh = NULL; 
    if (0 == len)
        return NULL;
    pCh = (char *)malloc(3 * (len + 1));    // 防止存储空间不够，所以乘以3而不是2
    if (!pCh)
        return NULL;
    memset(pCh, 0, 3 * (len + 1));
    wcstombs(pCh, pWchar, len * 3 + 3);

    return pCh;
}


/**
* @brief char 转换为 wchar
*/
wchar_t chartowchar(const char ch)
{
    //size_t mbstowcs(wchar_t *dest, const char *src, size_t n);     
    wchar_t wch = 0;
    mbstowcs(&wch, &ch, sizeof(char));

    return wch;
}

/**
* @brief char * 转换为wchar *
*/
wchar_t * charstowchar(const char * pChar)
{
    int len = 0;
    if (!pChar)
        return NULL;
    len = strlen(pChar);
    if (0 == len)
        return NULL;
    wchar_t * pWch = (wchar_t *)malloc((len + 1) * sizeof(wchar_t));
    if (!pWch)
        return NULL;
    memset(pWch, 0, (len + 1) * sizeof(wchar_t));
    mbstowcs(pWch, pChar, len);

    return pWch;
}

