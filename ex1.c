#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "menu.h"

typedef struct NODE {
  int value;
  struct NODE *next;
} Node;

typedef struct LIST {
  Node *last;
  Node *first;
} List;

void display(List *list)
{
  Node *p;
  int index;

  for (index=0,p=list->first->next; p != NULL;index++,p=p->next) {
    printf("%d - %d\n", index, p->value);
  }
}

Node *insert(List *list, int x)
{
	if ((list->last->next = malloc(sizeof(Node))) == NULL)
		printf("Memory allocation error");
	else {
    list->last = list->last->next;
    list->last->value = x;
    list->last->next = NULL;

    return list->last;
	}

  return NULL;
}

Node *find(List *list, int x)
{
  Node *p;
  int index;

  if (x == -1) return list->first;

  for (index=0,p=list->first; p != NULL;index++,p=p->next) {
    if(index==x) return p;
  }

	return NULL;
}

void change(Node *node, int new)
{
  if (node != NULL) node->value = new;
}

bool isEmpty(List *list)
{
  return (list->first == list->last);
}

bool delete(List *list, Node *p)
{
  Node *pdel;
  int value;

  if (isEmpty(list) || p == NULL || (pdel = p->next) == NULL) return false;

  p->next = p->next->next;
  value   = pdel->value;

  if (p->next == NULL) list->last = p;
  free(pdel);

  return value;
}

void initialize(List *list)
{
	if ((list->first = malloc(sizeof(Node))) == NULL)
		printf("Memory allocation error");
	else {
    list->last = list->first;
    list->last->value = 0;
    list->last->next = NULL;
	}
}

void destroy(List *list)
{
  while(! isEmpty(list)) delete(list, list->first);
}

int ex1(void)
{
  List list;
  int loop, value, valueNew;
  char *options="\n 1 - Display \n 2 - Insert \n 3 - Change \n 4 - Find \n 5 - Remove \n 6 - Destroy \n 0 - Exit\0";

  loop = 1;

  initialize(&list);

  while (loop) {
    switch(menu(options)) {
      case 1:
        display(&list);
        break;

      case 2:
        printf("Number to insert: ");
        scanf("%d", &value);
        insert(&list, value);
        break;

      case 3:
        printf("Element to Change: ");
        scanf("%d", &value);
        printf("New number: ");
        scanf("%d", &valueNew);
        change(find(&list, value), valueNew);
        printf("Element Changed");
        break;

      case 4:
        printf("Element index: ");
        scanf("%d", &value);
        printf("Element Value is: %d ", (find(&list, value))->value);
        break;

      case 5:
        printf("Element index: ");
        scanf("%d", &value);
        delete(&list, find(&list, value));
        printf("Element Removed");
        break;

      case 6:
        destroy(&list);
        printf("Destroyed");
        break;

      case 0:
        loop=0;
        break;
    }
  }
  return 0;
}
