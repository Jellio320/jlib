#ifndef JLIB_H
#define JLIB_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef UNUSED
#define UNUSED(x) ((void) (x))
#endif

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long long ullong;

typedef char byte;
typedef long long llong;

// jlstr

int jlstrislower(char *str);
int jlstrisupper(char *str);
int jlstrtolower(char *str);
int jlstrtoupper(char *str);
int jlstrinv(char *str, char *dest);

#ifdef __cplusplus
}
#endif

#endif // JLIB_H
