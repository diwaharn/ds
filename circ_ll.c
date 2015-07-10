/* circ_ll.c */
#include <stdio.h>
#include <stdlib.h>

typedef struct clist {
    int value;
    struct clist *next;
}CIRC_LL;

int insert (CIRC_LL **head, int value)
{
    CIRC_LL *tmp;

    tmp = (CIRC_LL*) malloc (sizeof (CIRC_LL));
    if (tmp == NULL){
        fprintf (stderr, "Error in malloc\n");
    }

    tmp->value = value;
    if (*head == NULL){
        *head = tmp;
    }
    else {
        tmp->next = *head;
        *head = tmp;
    }

}

void print (CIRC_LL *start)
{
    CIRC_LL *tmp;
    tmp = start;
    printf ("Printing CIRC_LL:\n");
    while (tmp){
        printf ("\t -> %d \n", tmp->value); 
        tmp = tmp->next;
    }
}

int delete (CIRC_LL **head, int value)
{
    CIRC_LL *tmp;
    CIRC_LL *prev;

    tmp = *head;
    prev = NULL;

    while (tmp){
        if (tmp->value == value){
            if (prev == NULL){
                /* first element */
                *head = tmp->next;
            }
            else {
                prev->next = tmp->next;
            }
            free (tmp);
        }
        prev = tmp;
        tmp = tmp->next;
    }
}

int main(int argc, char *argv[])
{
    CIRC_LL *head;

    insert (&head, 5);
    print (head);
    insert (&head, 6);
    insert (&head, 7);
    insert (&head, 8);
    print (head);
    delete (&head, 7);
    print (head);
    delete (&head, 8);
    print (head);

}
/* end of circ_ll.c */
