#ifndef JLIB_H
#define JLIB_H 1

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>

#ifndef UNUSED
#ifndef NDEBUG
#define UNUSED(x) ((void) (x))
#else
#define UNUSED(x) do { } while(0)
#endif // NDEBUG
#endif

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long long ullong;
typedef long long llong;

// jlstr

extern uint32_t jlstrislower(char *str);
extern uint32_t jlstrisupper(char *str);
extern uint32_t jlstrisnumeric(char *str);

extern uint32_t jlstrtolower(char *str);
extern uint32_t jlstrtoupper(char *str);

extern void jlstrinv(char *str, char *dest);

// jlio

extern int64_t jlgetfilesize(const int fd);
extern int64_t jlfgetfilesize(FILE *file);
extern int64_t jlsgetfilesize(const char *pathname);

extern int jlfparse(char *dest, FILE *file);
extern int jlfnparse(char *dest, size_t n, FILE *file);

extern int64_t jlfgetline(char *restrict dest, FILE *restrict file);
extern int64_t jlfgetnline(char *restrict dest, size_t n, FILE *restrict file);
extern int64_t jlfseekline(size_t line, FILE *file);
extern uint64_t jlfcharcount(const char c, FILE *file);

// jlmisc

extern int jlfliparrayls(void *array, const size_t length, const size_t stride);
#define jlfliparrayl(array, length) jlfliparrayls(array, length, sizeof *array)
#define jlfliparrays(array, stride) jlfliparrayls(array, sizeof(array), stride)
#define jlfliparray(array) jlfliparrayls(array, sizeof(array), sizeof *array)

#ifdef __cplusplus
}
#endif

#endif // JLIB_H
