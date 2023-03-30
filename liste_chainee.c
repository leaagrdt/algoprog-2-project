#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "proto.h"



node* new_node(int Info)
{
	node* ret = malloc(sizeof(node));
	if(ret!=NULL)
	{
		ret->info = Info;
		ret->next = NULL;
	}
	return ret;
}

void free_node(head_node* head)
{
	node* current1 = head->head;
	node* current2 = current1;
	
	while(current1 != NULL)
	{
		current2 = current1->next;
		free(current1);
		current1 = current2;
	}	
	head->head = NULL;
}

void print_node(head_node head)
{
	node* current = head.head;
	while(current != NULL)
	{
		printf("%d\n",current->info);
		current = current->next;
	}
}


void stack_node(head_node* Head, int Info)
{
	node* new_head = new_node(Info);
	new_head->next = Head->head;
	Head->head = new_head;
	return;
}

void queue_node(head_node* Head, int Info)
{
	node* node = Head->head;
	if(node != NULL)
	{
		while(node->next!=NULL)
		{
			node = node->next;
		}
		node->next = new_node(Info);
	}
	else
	{
		Head->head = new_node(Info);
	}
}

bool supp_node(head_node* Head, int info)
{
	bool trouve = true;
	node *prec = NULL;
	node *node = Head->head;

	while(node != NULL && node->info != info)
	{
		prec = node;
		node = node->next;
	}
	if(node == NULL) //on n'a pas trouver le maillon
	{
		trouve = false;
	}

	else //on retire du chainage 
	{
		if(prec == NULL)
		{
			Head->head = node->next;
		}
		else
		{
			prec->next = node->next;
		}
		free(node);
	}	
	return trouve;
}
