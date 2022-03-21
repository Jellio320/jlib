#ifndef JLIB_H
#define JLIB_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>

#ifndef UNUSED
#define UNUSED(x) ((void) (x))
#endif

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long long ullong;
typedef long long llong;

// jlstr

uint32_t jlstrislower(char *str);
uint32_t jlstrisupper(char *str);
uint32_t jlstrisnumeric(char *str);

uint32_t jlstrtolower(char *str);
uint32_t jlstrtoupper(char *str);

void jlstrinv(char *str, char *dest);


// jlio

int jlfliparrayls(void *array, const size_t length, const size_t stride);
#define jlfliparrayl(array, length) jlfliparrayls(array, length, sizeof *array)
#define jlfliparrays(array, stride) jlfliparrayls(array, sizeof(array), stride)
#define jlfliparray(array) jlfliparrayls(array, sizeof(array), sizeof *array)

int64_t jlgetfilesize(const int fd);
int64_t jlfgetfilesize(FILE *file);
int64_t jlsgetfilesize(const char *pathname);

int jlparsefile(char *dest, FILE *file);
int jlparsenfile(char *dest, size_t n, FILE *file);


#ifdef __cplusplus
}
#endif

#endif // JLIB_H
