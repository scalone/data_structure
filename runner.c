/* runner.c */

#include <stdio.h>

#include "menu.h"
#include "ex1.h"
#include "ex2.h"
#include "ex3.h"
#include "ex4.h"

int tests_run = 0;

#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!(test)) { FAIL(); return 1; } } while(0)
#define _verify(test) do { int r=test(); tests_run++; if(r) return r; } while(0)

int test_sample() {
	_assert(true);
	return 0;
}

int all_tests() {
	_verify(test_sample);
	return 0;
}

int main(int argc, char **argv) {
	int result = all_tests();
	if (result == 0)
		printf("PASSED\n");
	printf("Tests run: %d\n", tests_run);

	return result != 0;
}
