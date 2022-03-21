#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

uint32_t jlstrislower(char *str) {
	if(str == NULL)
		return 0;

	uint32_t count = 0;
	for(; *str != 0; str++) {
		if(!islower(*str))
			return 0;

		count++;
	}

	return count;
}

uint32_t jlstrisupper(char *str) {
	if(str == NULL)
		return 0;

	uint32_t count = 0;
	for(; *str != 0; str++) {
		if(!isupper(*str))
			return 0;

		count++;
	}

	return count;
}

uint32_t jlstrisnumeric(char *str) {
	if(str == NULL)
		return 0;

	uint32_t count = 0;
	for(; *str != 0; str++) {
		if(!isdigit(*str))
			return 0;

		count++;
	}

	return count;
}

uint32_t jlstrtolower(char *str) {
	if(str == NULL)
		return 0;

	uint32_t count = 0;
	for(; *str != 0; str++) {
		if(isupper(*str))
			*str = tolower(*str);

		count++;
	}

	return count;
}

uint32_t jlstrtoupper(char *str) {
	if(str == NULL)
		return 0;

	uint32_t count = 0;
	for (; *str != 0; str++) {
		if(islower(*str))
			*str = toupper(*str);

		count++;
	}

	return count;
}

void jlstrinv(char *src, char *dest) {
	size_t offset;
	if(src == NULL || dest == NULL || ((offset = strlen(src)) == 0)) {
		*dest = 0;
		return;
	}

	if(src == dest) {
		for(dest += --offset; src < dest; src++, dest--) {
			char buf = *src;
			*src = *dest;
			*dest = buf;
		}
		return;
	} else {
		while(offset != 0) {
			*dest++ = *(src + --offset);
		}
		// set the last byte of destination to be NULL
		*dest = 0;
		return;
	}
}

