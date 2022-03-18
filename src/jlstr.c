#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <assert.h>

int32_t jlstrislower(char *str) {
	if(str == NULL)
		return 0;

	int32_t	count = 0;
	for(char *c = str; *c != 0; c++) {
		if(!islower(*c))
			return 0;

		count++;
	}

	return count;
}

int32_t jlstrtolower(char *str) {
	if(str == NULL)
		return 0;

	int32_t	count = 0;
	for(char *c = str; *c != 0; c++) {
		if(isupper(*c))
			*c = tolower(*c);

		count++;
	}

	return count;
}

int32_t jlstrisupper(char *str) {
	if(str == NULL)
		return 0;

	int32_t count = 0;
	for(char *c = str; *c != 0; c++) {
		if(!isupper(*c))
			return 0;

		count++;
	}

	return count;
}

int32_t jlstrtoupper(char *str) {
	if(str == NULL)
		return 0;

	int32_t count = 0;
	for (char *c = str; *c != 0; c++) {
		if(islower(*c))
			*c = toupper(*c);

		count++;
	}

	return count;
}

int32_t jlstrisnumeric(char* str) {
	if(str == NULL)
		return 0;

	int32_t count = 0;
	for(char *c = str; *c != 0; c++) {
		if(!isdigit(*c))
			return 0;

		count++;
	}

	return count;
}

void jlstrinv(char *src, char* dest) {
	size_t offset = strlen(src) - 1;
	if(src == dest) {
		for(dest += offset; src < dest; src++) {
			char buf = *src;
			*src = *dest;
			*dest-- = buf;
		}
	} else {
		for(int32_t i = offset; i > -1; i--) {
			*dest++ = *(src + i);
		}
		// set the last byte of destination to be NULL
		*dest = 0;
	}
}

