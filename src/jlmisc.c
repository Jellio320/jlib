#include <stdlib.h>
#include <stdbool.h>

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


