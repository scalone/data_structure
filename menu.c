#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int menu(char *options)
{
  printf("\n Menu");
  printf(options);
  printf("\n Option: ");

  scanf("%d", &option);
  return option;
}
