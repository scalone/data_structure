#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "menu.h"

#define MAX_STRING_LEN 25

typedef struct NODE {
  int gender;
  char name[MAX_STRING_LEN];
  char id[MAX_STRING_LEN];
  struct NODE *next;
  struct NODE *previous;
} Node;

typedef struct LIST {
  Node *last;
  Node *first;
  int top;
} List;

char getGender(int gender)
{
  if (gender == 1)
    return 'M';
  else
    return 'F';
}

void EX4_display(List *list)
{
  Node *p;
  int index;

  printf("N - Gender - ID - Name\n");
  for (index=0,p=list->first->next; p != NULL;index++,p=p->next) {
    printf("%d - %c - %s - %s\n", index, getGender(p->gender), p->id, p->name);
  }
}

Node *EX4_find(List *list, int x)
{
  Node *p;
  int index;

  for (index=0,p=list->first; p != NULL;index++,p=p->next) {
    if(index==x) return p;
  }

	return NULL;
}

void EX4_insert(List *list, char *name, char *id, int gender)
{
  Node *p;
  Node *old;
  Node *aux;

  if ((p = malloc(sizeof(Node))) == NULL)
    printf("Memory allocation error");
  else {
    p->gender = gender;
    strcpy((char *)&p->name, name);
    strcpy((char *)&p->id, id);

    old = EX4_find(list, list->top);
    aux = old->next;
    p->next = aux;
    old->next = p;
    p->previous = old;
    list->top++;
    if (aux == NULL)
      list->last = p;
    else
      aux->previous = p;
  }
}

void EX4_change(Node *node, char *name, char *id, int gender)
{
  if (node != NULL) {
    strcpy((char *)&node->name, name);
    strcpy((char *)&node->id, id);
    node->gender = gender;
  }
}

bool EX4_isEmpty(List *list)
{
  return (list->first == list->last);
}

void EX4_delete(List *list, Node *p)
{
  Node *pdel;

  if (EX4_isEmpty(list) || p == NULL || (pdel = p->next) == NULL) return;

  p->next = p->next->next;
  p->previous = p->previous->previous;

  if (p->next == NULL) list->last = p;
  if (p->previous == NULL) list->first = p;
  list->top--;
  free(pdel);
}

void EX4_initialize(List *list)
{
	if ((list->first = malloc(sizeof(Node))) == NULL)
		printf("Memory allocation error");
	else {
    list->last = list->first;
    list->last->next = NULL;
    list->last->previous = NULL;
    list->top = 0;
	}
}

void EX4_destroy(List *list)
{
  while(! EX4_isEmpty(list)) EX4_delete(list, list->first);
}

void getParameters(char *name, char *id, int *gender)
{
  /*char *sName = malloc(MAX_STRING_LEN);*/
  /*char *sId = malloc(MAX_STRING_LEN);*/

  getchar();

  printf("Name: ");
  fgets(name, MAX_STRING_LEN - 1, stdin);
  if ((strlen(name)>0) && (name[strlen (name) - 1] == '\n')) name[strlen (name) - 1] = '\0';

  printf("Id: ");
  fgets(id, MAX_STRING_LEN - 1, stdin);
  if ((strlen(id)>0) && (id[strlen (id) - 1] == '\n')) id[strlen (id) - 1] = '\0';

  printf("Sexo(1 - Masculino, 2 - Feminino): ");
  scanf("%d", gender);
  /*free(sName);*/
  /*free(sId);*/
}

int ex4(void)
{
  List list;
  int loop, value;
  char *options="\n 1 - Display \n 2 - insert \n 3 - Change \n 4 - Find \n 5 - Remove \n 6 - Destroy \n 0 - Exit\0";


  loop = 1;

  printf("\n Exercise 2\n");

  EX4_initialize(&list);

  while (loop) {
    char name[MAX_STRING_LEN];
    char id[MAX_STRING_LEN];
    int gender=0;

    memset(&name, 0, sizeof(name));
    memset(&id, 0, sizeof(id));

    switch(menu(options)) {
      case 1:
        EX4_display(&list);
        break;

      case 2:
        getParameters((char *)&name, (char *)&id, &gender);
        EX4_insert(&list, (char *)&name, (char *)&id, gender);
        break;

      case 3:
        printf("Element to Change: ");
        scanf("%d", &value);
        getParameters((char *)&name, (char *)&id, &gender);
        EX4_change(EX4_find(&list, value+1), name, id, gender);
        printf("Element Changed");
        break;

      case 4:
        printf("Element index: ");
        scanf("%d", &value);
        printf("Element Value is: %s ", (EX4_find(&list, value))->name);
        break;

      case 5:
        printf("Element index: ");
        scanf("%d", &value);
        EX4_delete(&list, EX4_find(&list, value));
        printf("Element Removed");
        break;

      case 6:
        EX4_destroy(&list);
        printf("Destroyed");
        break;

      case 0:
        loop=0;
        break;
    }
  }
  return 0;
}
