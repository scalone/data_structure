#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "menu.h"

typedef struct NODE {
  int value;
  struct NODE *previous;
} Node;

typedef struct STACK {
  Node *top;
  int size;
} Stack;

void EX3_display(Stack *stack)
{
  Node *p;
  int index;

  for (index=stack->size,p=stack->top; p != NULL;index--,p=p->previous) {
    printf("%d - %d\n", index, p->value);
  }
}


void EX3_push(Stack *stack, int value)
{
  Node *p;

  if ((p = malloc(sizeof(Node))) == NULL)
    printf("Memory allocation error");
  else {
    p->previous = stack->top;
    p->value = value;
    stack->top = p;
    stack->size++;
  }
}

bool EX3_isEmpty(Stack *stack)
{
  return (stack->size == 0);
}

int EX3_pop(Stack *stack)
{
  Node *p;
  int value;

  if (EX3_isEmpty(stack)) {
    printf("Stack empty");
    return 0;
  }

  p = stack->top;
  stack->top = stack->top->previous;
  stack->size--;
  value = p->value;
  free(p);

  return value;
}

void EX3_initialize(Stack *stack)
{
  stack->top = NULL;
  stack->size = 0;
}

void EX3_destroy(Stack *stack)
{
  while(! EX3_isEmpty(stack)) EX3_pop(stack);
}

int ex3(void)
{
  Stack stack;
  int loop, value;
  char *options="\n 1 - Display \n 2 - Push \n 3 - Pop \n 4 - Destroy \n 0 - Exit\0";

  loop = 1;

  printf("\n Exercise 3\n");

  EX3_initialize(&stack);

  while (loop) {
    switch(menu(options)) {
      case 1:
        EX3_display(&stack);
        break;

      case 2:
        printf("Number to insert: ");
        scanf("%d", &value);
        EX3_push(&stack, value);
        break;

      case 3:
        value = EX3_pop(&stack);
        printf("Pop value: %d", value);
        break;

      case 4:
        EX3_destroy(&stack);
        printf("Destroyed");
        break;

      case 0:
        loop=0;
        break;
    }
  }
  return 0;
}
