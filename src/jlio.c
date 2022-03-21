#define _POSIX_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/mman.h>

int jlfliparrayls(void *array, const size_t length, const size_t stride) {
	if(array == NULL || length == 0 || stride == 0)
		return false;

	struct TypeSize {
		unsigned char byte[stride];
	} buffer, *start, *end;

	// Converting void* to TypeSize* to make ++ work
	start = (struct TypeSize*) array;
	for (end = start + ((length / stride) - 1); start < end; start++) {
		buffer = *start;
		*start = *end;
		*end-- = buffer;
	}

	return true;
}

int64_t jlgetfilesize(const int fd) {
	struct stat fs;
	if(fstat(fd, &fs) == -1)
		return -1;

	return fs.st_size;
}

int64_t jlfgetfilesize(FILE *file) {
	int fd = fileno(file);	
	return jlgetfilesize(fd);
}

int64_t jlsgetfilesize(const char *pathname) {
	struct stat fs;
	if(stat(pathname, &fs) == -1)
		return -1;

	return fs.st_size;
}

int jlparsefile(char *dest, FILE *file) {
	long pos;
	if(dest == NULL || (pos = ftell(file)) == -1) {
		*dest = 0;
		return 0;
	}

	rewind(file);

	char c;
	int count = 0;
	while((c = fgetc(file)) != EOF) {
			*dest++ = c;
			count++;
	}
	*dest = 0;

	fseek(file, pos, SEEK_SET);

	return count;
}

int jlparsenfile(char *dest, size_t n, FILE *file) {
	long pos;
	if(dest == NULL || n == 0 || (pos = ftell(file)) == -1) {
		*dest = 0;
		return 0;
	}

	rewind(file);

	char c;
	int count = 0;
	while(((c = fgetc(file)) != EOF) && --n != 0) {
			*dest++ = c;
			count++;
	}
	*dest = 0;

	fseek(file, pos, SEEK_SET);

	return count;
}

