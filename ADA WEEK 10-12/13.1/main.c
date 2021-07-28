#include <stdio.h>

#define ARRAY_MAX 10

int values[ARRAY_MAX] = {              
	4, 56, 2, 8, 78, -44, -41, -98, 76, 21
};

int i;                      

int *values_ptr;           

int main() {

	for (i = 0; i < ARRAY_MAX; ++i) {
		printf("values[%d] = %d\n", i, values[i]);
	}

	values_ptr = &values[0];

	for (i = 0; i < ARRAY_MAX; ++i) {
		*values_ptr = 0;
		++values_ptr;
	}

	printf("--------------------\n");
	for (i = 0; i < ARRAY_MAX; ++i) {
		printf("values[%d] = %d\n", i, values[i]);
	}

	return(0);
}
