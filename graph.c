#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "proto.h"



G_al* init_G_al(int N)
{
	G_al* ret = malloc(sizeof(G_al));
	ret->n = N;
	ret->adj_list = malloc(sizeof(head_node*)*N);
	for(int i=0; i<N; i++)
	{
		ret->adj_list[i].head = NULL;
	}
	return ret;
}

G_al* extract_G_al_from_file(char* filename)
{
	FILE* f;
	G_al* ret;
	int a=0, b=0;
	
	f = fopen(filename,"r");
	
	fscanf(f,"%d",&a);
	fscanf(f,"%d",&b);
	
	ret = init_G_al(a);
	
	while(fscanf(f,"%d %d",&a,&b) == 2)
	{
		stack_node(&(ret->adj_list[a-1]),b-1);
	} 
	
	fclose(f);
	return ret;	
}

//===============================================================


G_m* init_G_m(int N)
{
	G_m* ret = malloc(sizeof(G_m));
	ret->n = N;
	ret->matrix = malloc(sizeof(int*)*N);
	for(int i=0; i<N; i++)
	{
		ret->matrix[i] = malloc(sizeof(int)*N);
		for(int j=0; j<N; j++)
		{
			ret->matrix[i][j] = 0;
		}
	}
	return ret;
}


G_m* extract_G_m_from_file(char* filename)
{
	FILE* f;
	G_m* ret;
	int a=0, b=0;
	
	f = fopen(filename,"r");
	
	fscanf(f,"%d",&a);
	fscanf(f,"%d",&b);
	
	ret = init_G_m(a);
	
	while(fscanf(f,"%d %d",&a,&b) == 2)
	{
		ret->matrix[a][b] = 1;
	}
	
	fclose(f);
	return ret;
}
