#ifndef _WCHAR_T_
#define _WCHAR_T_

/*#include <stdlib.h>*/

typedef unsigned short wchar_t;

/*/// < 内存释放宏*/
/*#define FREE(p) {   \*/
/*if(p)           \*/
/*{               \*/
/*free(p);    \*/
/*p = NULL;   \*/
/*}*/

/**
* @brief wchar转换为char
* @param[in] wchar - wchar数据.
* @return if success return char *,else return NULL.
*/
char * wchartochar(wchar_t wchar);

/**
* @brief wchar * 转换为char *
* @param[in] pwchar - wchar字符串数据.
* @return if success return char *,else return NULL.
*/
char * wcharstochar(const wchar_t * pWchar);

/**
* @brief char 转换为 wchar
* @param[in] ch - char 数据.
* @return if success return wchar, else return NULL.
*/
wchar_t chartowchar(const char ch);

/**
* @brief char * 转换为wchar *
* @param[in] pChar - char字符串数据.
* @return if success return wchar *,else return NULL.
*/
wchar_t * charstowchar(const char * pChar);

#endif
