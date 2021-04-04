/*Copyright (C) 2020-2021 AlanCui*/
#ifndef _STRING_H_
#define _STRING_H_
//计算字符串的长度
extern size_t strlen(const char *s);
//在给定最大区间内计算字符串的长度
extern size_t strnlen(const char *s, size_t maxlen);
//拷贝指定字符串
extern char *strcpy(char *restrict s1, const char *restrict s2);
//拷贝指定长度字符串
extern char *strncpy(char *restrict s1, const char *restrict s2, size_t n);
//拼接指定字符串
extern char *strcat(char *restrict s1, const char *restrict s2);
//拼接指定长度字符串
extern char *strncat(char *restrict s1, const char *restrict s2, size_t n);
//比较指定字符串,若s1较小则返回-1,反之1,若完全相等则返回0
extern int strcmp(const char *s1, const char *s2);
//比较指定长度字符串,若s1较小则返回-1,反之1,若完全相等则返回0
extern int strncmp(const char *s1, const char *s2, size_t n);
//在字符串内搜索值c首次出现的位置
extern char *strchr(const char *s, int c);
//在字符串内搜索值c最后一次出现的位置
extern char *strrchr(const char *s, int c);

//在给定内存区间内搜索值c首次出现的位置
extern void *memchr(const void *s, int c, size_t n);
//在给定内存区间内搜索值c最后一次出现的位置
extern void *memrchr(const void *s, int c, size_t n);
//将指定内存空间填充为c
extern void *memset(void *s, int c, size_t n);
//拷贝指定内存空间
extern void *memcpy(void *restrict s1, const void *restrict s2, size_t n);

#include <acuinx/string.h>
#endif