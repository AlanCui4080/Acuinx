#ifndef _KSTRING_H_
#define _KSTRING_H_

#ifndef _STRING_H_
#warning "do not include this file"
#endif
//插入字符串
extern char *strins(char *restrict s1, const char *restrict s2,size_t n);
//删除字符串
extern char *strdel(char *restrict s, int p, size_t n);
//将long long
转换为十六进制字符串
extern char *num2str64(char *tmp,  uint32_t n);
//将long转换为十六进制字符串
extern char *num2str32(char *tmp,  uint32_t n);
//将short转换为十六进制字符串
extern char *num2str16(char *tmp,  uint16_t n);
#endif
