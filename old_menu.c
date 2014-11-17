#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

struct node {
	int info;
	struct node *left, *right;
};

//Private

void list_move(struct node **list, int number)
{
	struct node *p=*list;
	int size=1;

	// When list is empty
	if (p==NULL) return;

	while(((p->right) != NULL) && (size != number))
	{
		p=p->right;
		size++;
	}

	// Move to end
	*list=p;
}

int count(struct node *list)
{
	int number=1;
	if (list==NULL) return 0;
	while((list=list->right)!=NULL) number++;
	return number;
}

//Private

void insert(struct node **list, int x)
{
	struct node *p;

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

void insert_end(struct node **list, int x)
{
	struct node *new, *list_aux=*list;

	list_move(&list_aux, NULL);

	if ((new = malloc(sizeof(struct node))) == NULL)
		printf("Memory allocation error");
	else{
		new->left  = list_aux;
		new->info  = x;
		new->right = NULL;

		if(list_aux != NULL)
			list_aux->right = new;
		if(list_aux == NULL) *list = new;
	}
}

void insert_middle(struct node **list, int x)
{
	struct node *new, *aux_right, *list_aux=*list;

	list_move(&list_aux, count(list_aux) / 2);

	if ((new = malloc(sizeof(struct node))) == NULL)
		printf("Memory allocation error");
	else{
		new->info       = x;
		new->left       = list_aux;

		if(list_aux != NULL)
		{
			aux_right       = list_aux->right;
			new->right      = aux_right;
			aux_right->left = new;
			list_aux->right = new;
		}

		if(list_aux == NULL) *list = new;
	}
}

void display(struct node *list)
{
	while(list!=NULL)
	{
		printf("%d ", list->info);
		list=list->right;
	}
	printf("\n");
}

void display_inverse(struct node *list)
{
	if (list != NULL){
		list_move(&list, NULL);

		while(list!=NULL)
		{
			printf("%d ", list->info);
			list=list->left;
		}
	}
	else
		printf("\n Empty list");
	printf("\n");
}

struct node * find(struct node *list, int x)
{
	while(list!=NULL){
		if (list->info == x)
			return list;

		list=list->right;
	}
	return NULL;
}

void remove_element(struct node **list, struct node *removed)
{
	struct node * right, * left;

	right = removed->right;
	left = removed->left;

	if(right!=NULL) right->left = left;
	if(left!=NULL)  left->right = right;

	if(left==NULL) *list = right;

	free(removed);
}

int main (void)
{
	struct node *list, *p;
	int loop;
	int x;

	list = NULL;
	loop = 1;

	while (loop)
	{
		int option;
		printf("\n Menu");
		printf("\n 1 - Display");
		printf("\n 2 - Display inverse");
		printf("\n 3 - Insert");
		printf("\n 4 - Find Element");
		printf("\n 5 - Remove Element");
		printf("\n 6 - Insert end");
		printf("\n 7 - Insert middle");
		printf("\n 0 - Exit");
		printf("\n Option: ");

		scanf("%d", &option);

		switch(option)
		{
			case 1:
				display(list);
				break;

			case 2:
				display_inverse(list);
				break;

			case 3:
				printf("Number to insert: ");
				scanf("%d", &x);
				insert(&list, x);
				break;

			case 4:
				printf("Number to find: ");
				scanf("%d", &x);
				printf("Element is: %d ", find(list, x));
				break;

			case 5:
				printf("Number to Remove: ");
				scanf("%d", &x);
				remove_element(&list, find(list, x));
				printf("Element Removed");
				break;

			case 6:
				printf("Number to insert end: ");
				scanf("%d", &x);
				insert_end(&list, x);
				break;

			case 7:
				printf("Number to insert middle: ");
				scanf("%d", &x);
				insert_middle(&list, x);
				break;

			case 0:
				loop=0;
				break;
		}
	}
	return 0;
}
