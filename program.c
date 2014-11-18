#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ex1.h"
#include "ex2.h"
#include "ex3.h"

int main(int argc, char **argv) {
  if (strcmp("ex1", (const char *)argv[1]) == 0)
    ex1();
  else if (strcmp("ex2", (const char *)argv[1]) == 0)
    ex2();
  else
    ex3();

  return 0;
}
