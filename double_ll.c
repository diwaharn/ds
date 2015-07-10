/*double_ll.c*/
#include <stdio.h>
#include <stdlib.h>

typedef struct cnode {
    struct cnode *prev;
    int value;
    struct cnode *next;
} CNODE;

CNODE *head;

int insert(int value)
{
    CNODE *tmp;

    tmp = (CNODE*) malloc (sizeof(CNODE*));
    if (tmp == NULL) {
        fprintf(stderr, "Malloc failed \n");
        return -1;
    }

    tmp->value = value;
    if (head == NULL){
        head = tmp;
        tmp->next = tmp->prev = NULL;
    }
    else {
        tmp->next = head;
        tmp->prev = NULL;
        head->prev = tmp;
        head = tmp;
    }

}

void print ()
{
    CNODE *tmp;
    int idx = 1;
    printf ("Printing Node :\n");

    tmp = head;
    while (tmp){
        printf ("\t%02d:%x:<-%x,(%d),->%x\n", 
                idx++, (unsigned int) tmp, (unsigned int)tmp->prev, tmp->value, (unsigned int)tmp->next);
        tmp = tmp->next;
    }
}

int main(int argc, char *argv[])
{
    head = NULL;

    insert (10);
    insert (11);
    print();
    insert (15);
    insert (16);
    print();
}
/* end double_ll.c*/
