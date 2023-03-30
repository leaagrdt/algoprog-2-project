#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "proto.h"

void main(void)
{
    head_node liste;
    liste.head = NULL;

    stack_node(&liste, 3);
    stack_node(&liste, 9);
    queue_node(&liste, 1);
    print_node(liste);
}