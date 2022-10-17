#include <stdio.h>
#include <stdlib.h>

#include "dlist.h"

/*
   Print List
*/

static void print_dlist (const DList *dlist) {
    DListNode *node;
    int *data, i;

    fprintf(stdout, "List size is %d\n", dlist_size(dlist));

    i = 0;
    node = dlist_head(dlist);

    while (1) {
        data = dlist_data(node);
        fprintf(stdout, "list.node[%03d]=%03d, %p <-, %p -> %p \n", i, *data, node->prev, node, node->next);

        i++;

        if (dlist_is_tail(node))
            break;
        else
            node = dlist_next(node);
    }

   return;
}

int main (int argc, char **argv) {
    DList dlist;
    DListNode *node;

    int *data, i;

    // Initialize the linked list
    dlist_init(&dlist, free);

    // Fill the linked list
    node = dlist_head(&dlist);
    for (i = 10; i > 0; i--) {
		
		printf("\n %p", node);
		
        if ((data = (int *)malloc(sizeof(int))) == NULL)
            return 1;

        *data = i;
		
        if (dlist_ins_next(&dlist, node, data) != 0)
            return 1;
            
        node = dlist_tail(&dlist); //esto hace que nos ubiquemos a la cola de la lista
        
    }

    print_dlist(&dlist);

    node = dlist_head(&dlist);

    for (i = 0; i < 7; ++i)
        node = dlist_next(node);

    data = dlist_data(node);
    fprintf(stdout, "\nRemoving a node after the one containing %03d\n", *data);

    if (dlist_remove(&dlist, node, (void**)&data) != 0)
        return 1;

    print_dlist(&dlist);

    fprintf(stdout, "\nInserting 187 at the tail of the list\n");
    *data = 187;
    if (dlist_ins_next(&dlist, dlist_tail(&dlist), data) != 0) //solo se requiere esto para añadir el nodo hacia "adelante"
        return 1;

    print_dlist(&dlist);
    
    node= dlist_head(&dlist); //ubicamos el nodo en la cabeza de la lista
    node= node->next; //ubicamos el nodo un nodo despues de la cabeza

    fprintf(stdout, "\nRemoving a node after the first node\n");
    if (dlist_remove(&dlist, node, (void**)&data) != 0)
        return 1;
    print_dlist(&dlist);

    fprintf(stdout, "\nRemoving a node at the head of the list\n");
    
    node = dlist_head(&dlist); //ubicamos el nodo en la cabeza de la lista
    
    if (dlist_remove(&dlist, node, (void**)&data) != 0)
        return 1;
    print_dlist(&dlist);    
    
    fprintf(stdout, "\nInsert 975 at the head of the list\n");
    *data = 975;
    
    node = dlist_head(&dlist); //ubicamos el nodo en la cabeza de la lista
        
    if (dlist_ins_prev(&dlist, node, data) != 0) //requiere esto para añadir el nodo "atras" de la cabeza
        return 1;
        
    print_dlist(&dlist);    

    fprintf(stdout, "\nIterating and removing the fourth node\n");

    node = dlist_head(&dlist);
    node = dlist_next(node);
    node = dlist_next(node);
    node = dlist_next(node);

    if (dlist_remove(&dlist, node, (void **)&data) != 0)
        return 1;

    print_dlist(&dlist);

    fprintf(stdout, "\nInserting 607 after the first node\n");
    *data = 607;
    
    node= dlist_head(&dlist); //ubicamos el nodo en la cabeza de la lista
    
    if (dlist_ins_next(&dlist, node, data) != 0)
        return 1;
    
    print_dlist(&dlist);

    i = dlist_is_head(dlist_head(&dlist));
    fprintf(stdout, "\nTesting list_is_head... value=%d (1=OK)\n", i);
    i = dlist_is_head(dlist_tail(&dlist));
    fprintf(stdout, "Testing list_is_head... value=%d (1=OK)\n", i);
    i = dlist_is_tail(dlist_tail(&dlist));
    fprintf(stdout, "Testing list_is_tail... value=%d (1=OK)\n", i);
    i = dlist_is_tail(dlist_head(&dlist));
    fprintf(stdout, "Testing list_is_tail... value=%d (1=OK)\n", i);
    

    // Destroying the list
    fprintf(stdout, "\nDestroying the list\n");
    dlist_destroy(&dlist);

    return 0;
}
