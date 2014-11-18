#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ex1.h"
#include "ex2.h"
#include "ex3.h"
#include "ex4.h"

void print_usage(void)
{
    printf("Error: Usage: program <exercise>\n\n");
    printf("\tex1, Simply linked Linear List with dummy head\n");
    printf("\tex2, Doubly linked Linear List with dummy head\n");
    printf("\tex3, Stack in dynamic memory allocation\n");
    printf("\tex4, Queue in dynamic memory allocation to Medical Clinic management\n");
    printf("\t-h, --help, Help\n");
}

int main(int argc, char **argv)
{
  if (argc < 2 || strcmp("-h", (const char *)argv[1]) == 0 || strcmp("--help", (const char *)argv[1]) == 0) {
    print_usage();
    return 1;
  }

  if (strcmp("ex1", (const char *)argv[1]) == 0)
    ex1();
  else if (strcmp("ex2", (const char *)argv[1]) == 0)
    ex2();
  else if (strcmp("ex3", (const char *)argv[1]) == 0)
    ex3();
  else if (strcmp("ex4", (const char *)argv[1]) == 0)
    ex4();
  else
    print_usage();

  return 0;
}
