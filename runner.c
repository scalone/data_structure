/* runner.c */

#include <stdio.h>

#include "sut.h"

int tests_run = 0;

#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!(test)) { FAIL(); return 1; } } while(0)
#define _verify(test) do { int r=test(); tests_run++; if(r) return r; } while(0)

int test_square() {
	int x=5;
	_assert(square(x) == 25);
	return 0;
}

int test_square_fail() {
	int x=6;
	_assert(square(x) != 25);
	return 0;
}

int all_tests() {
	_verify(test_square);
	_verify(test_square_fail);
	return 0;
}

int main(int argc, char **argv) {
	int result = all_tests();
	if (result == 0)
		printf("PASSED\n");
	printf("Tests run: %d\n", tests_run);

	return result != 0;
}
