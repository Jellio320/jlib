#define _POSIX_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/mman.h>

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

int jlfparse(char *dest, FILE *file) {
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

int jlfnparse(char *dest, size_t n, FILE *file) {
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

int64_t jlfgetline(char *restrict dest, FILE *restrict file) {
	int64_t count = 0;
	int c;

	while((c = fgetc(file))) {
		if(c == EOF || c == '\n')
			break;

		*dest++ = c;
		count++;
	}
	*dest = 0;

	if(errno) {
		return -1;
	}

	return count;
}

int64_t jlfgetnline(char *restrict dest, size_t n, FILE *restrict file) {
	if(!n) return 0;
	else n--;

	int64_t count = 0;
	int c;

	while((c = fgetc(file))) {
		if(c == EOF || c == '\n')
			break;

		if(n) {
			*dest++ = c;
			count++;
			n--;
		}
	}
	*dest = 0;

	if(errno) {
		return -1;
	}

	return count;
}

int64_t jlfseekline(size_t line, FILE *file) {
	rewind(file);

	int64_t breakline = 0;
	for(size_t i = 1; i < line; i++) {
		char c;	
		while((c = fgetc(file))) {
			if(c == '\n') {
				breakline++;
				break;
			} else if(c == EOF)
				goto breakFor;
		}
	}

breakFor:
	return breakline;
}

uint64_t jlfcharcount(const char c, FILE *file) {
	fpos_t pos;
	fgetpos(file, &pos);
	rewind(file);

	uint64_t count = 0;
	char in;

	while((in = fgetc(file)) != EOF) {
		if(in == c) {
			count++;
		}
	}

	fsetpos(file, &pos);
	if(errno)
		return 0;
	
	return count;
}

