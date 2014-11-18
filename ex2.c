#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "menu.h"

typedef struct NODE {
  int value;
  struct NODE *next;
  struct NODE *previous;
} Node;

typedef struct LIST {
  Node *last;
  Node *first;
  int top;
} List;

void EX2_display(List *list)
{
  Node *p;
  int index;

  for (index=0,p=list->first->next; p != NULL;index++,p=p->next) {
    printf("%d - %d\n", index, p->value);
  }
}

Node *EX2_find(List *list, int x)
{
  Node *p;
  int index;

  for (index=0,p=list->first; p != NULL;index++,p=p->next) {
    if(index==x) return p;
  }

	return NULL;
}

void EX2_insert(List *list, int value, int position)
{
  Node *p;
  Node *old;
  Node *aux;

  if ((p = malloc(sizeof(Node))) == NULL)
    printf("Memory allocation error");
  else {
    p->value = value;
    old = (position == -1) ? EX2_find(list, list->top) : EX2_find(list, position);
    aux = old->next;

    p->next = aux;
    aux->previous = p;
    old->next = p;
    p->previous = old;

    list->top++;
    if (aux == NULL) list->last = p;
  }
}

void EX2_change(Node *node, int new)
{
  if (node != NULL) node->value = new;
}

bool EX2_isEmpty(List *list)
{
  return (list->first == list->last);
}

bool EX2_delete(List *list, Node *p)
{
  Node *pdel;
  int value;

  if (EX2_isEmpty(list) || p == NULL || (pdel = p->next) == NULL) return false;

  p->next = p->next->next;
  p->previous = p->previous->previous;
  value   = pdel->value;

  if (p->next == NULL) list->last = p;
  if (p->previous == NULL) list->first = p;
  list->top--;
  free(pdel);

  return value;
}

void EX2_initialize(List *list)
{
	if ((list->first = malloc(sizeof(Node))) == NULL)
		printf("Memory allocation error");
	else {
    list->last = list->first;
    list->last->value = 0;
    list->last->next = NULL;
    list->last->previous = NULL;
    list->top = 0;
	}
}

void EX2_destroy(List *list)
{
  while(! EX2_isEmpty(list)) EX2_delete(list, list->first);
}

int ex2(void)
{
  List list;
  int loop, value, valueNew;
  char *options="\n 1 - Display \n 2 - insert \n 3 - insert in position \n 4 - Change \n 5 - Find \n 6 - Remove \n 7 - Destroy \n 0 - Exit\0";

  loop = 1;

  printf("\n Exercise 2\n");

  EX2_initialize(&list);

  while (loop) {
    switch(menu(options)) {
      case 1:
        EX2_display(&list);
        break;

      case 2:
        printf("Number to insert: ");
        scanf("%d", &value);
        EX2_insert(&list, value, -1);
        break;

      case 3:
        printf("Number to insert: ");
        scanf("%d", &value);
        printf("Index to insert: ");
        scanf("%d", &valueNew);
        EX2_insert(&list, value, valueNew);
        break;

      case 4:
        printf("Element to Change: ");
        scanf("%d", &value);
        printf("New number: ");
        scanf("%d", &valueNew);
        EX2_change(EX2_find(&list, value), valueNew);
        printf("Element Changed");
        break;

      case 5:
        printf("Element index: ");
        scanf("%d", &value);
        printf("Element Value is: %d ", (EX2_find(&list, value))->value);
        break;

      case 6:
        printf("Element index: ");
        scanf("%d", &value);
        EX2_delete(&list, EX2_find(&list, value));
        printf("Element Removed");
        break;

      case 7:
        EX2_destroy(&list);
        printf("Destroyed");
        break;

      case 0:
        loop=0;
        break;
    }
  }
  return 0;
}
