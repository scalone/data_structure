#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int menu(char *options)
{
  int option;

  printf("\n Menu");
  printf("%s", options);
  printf("\n Option: ");

  scanf("%d", &option);
  return option;
}
