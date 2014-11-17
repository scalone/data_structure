#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "menu.h"

#define LIST_MAX_LEN 10


typedef struct _Node {
  int value;
  struct _Node *next;
};

typedef struct _Node Node;

void inserti(Node **node, int x)
{
	struct node *new;

	if ((p = malloc(sizeof(struct node))) == NULL)
		printf("Memory allocation error");
	else{
		p->left  = NULL;
		p->info  = x;
		p->right = *list;

		if(*list != NULL)
			(*list)->left = p;

		*list = p;
	}
}

/*void init(Node *node)*/
/*{*/
  /*Node p;*/
  /*p.next = NULL;*/
  /*return &p;:*/
/*}*/

void display(Node *list)
{
  Node *p;
  for (p = list->prox, index=0; p != NULL; index++, p = p->prox) 
    printf("%d - %d\n", index, p->value);
}

void insert(Node **list, int x)
{
	Node *p;

	if ((p = malloc(sizeof(Node))) == NULL)
		printf("Memory allocation error");
	else{
		p->value  = x;
		p->next = *list;

		*list = p;
	}
}

Node *find(Node *list, int x)
{
	while(list!=NULL){
		if (list->info == x)
			return list;

		list=list->next;
	}
	return NULL;
}

int ex1(void)
{
  Node first, *list;
  int loop;
  int value;
  char options="\n 1 - Display \n 2 - Insert \n 3 - Change \n 4 - Find \n 5 - Remove \n 0 - Exit";

  first.next = NULL;
  list = &first;

  loop = 1;

  while (loop) {
    switch(menu(options)) {
      case 1:
        display(list);
        break;

      case 2:
        printf("Number to insert: ");
        scanf("%d", &value);
        insert(&list, value);
        break;

      case 3:
        printf("Number to find: ");
        scanf("%d", &value);
        printf("Element is: %d ", find(list, value));
        break;

      /*case 5:*/
        /*printf("Number to Remove: ");*/
        /*scanf("%d", &value);*/
        /*remove_element(&list, find(list, value));*/
        /*printf("Element Removed");*/
        /*break;*/

      /*case 6:*/
        /*printf("Number to insert end: ");*/
        /*scanf("%d", &value);*/
        /*insert_end(&list, value);*/
        /*break;*/

      /*case 7:*/
        /*printf("Number to insert middle: ");*/
        /*scanf("%d", &value);*/
        /*insert_middle(&list, value);*/
        /*break;*/

      case 0:
        loop=0;
        break;
    }
  }
  return 0;
}
