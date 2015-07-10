/*linkedlist */
#include <stdio.h>
#include <stdlib.h> 

typedef struct node {
    int val;
    struct node *next;
}NODE;

NODE *head;

int insert(int value)
{
    NODE* tmp;

    tmp = (NODE*) malloc(sizeof (NODE));
    if (tmp == NULL){
        return -1;
    }

    /* Add the entry first */
    tmp->next = head;
    tmp->val = value;
    head = tmp;
    return 1;
}

int delete(int value)
{
    NODE *tmp;
    NODE *prev;

    tmp = head;
    prev = NULL;
    while (tmp){
        if (tmp->val == value){
            if (prev == NULL){
                /* First Entry , check with head */
                head = tmp->next;
            }
            else {
                /* Not first entry */
                prev->next = tmp->next;
            }
            free (tmp);
            return 1;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return 0;
}

void print()
{
    NODE *tmp;

    printf ("Printing Node:\n");
    tmp = head;
    while (tmp){
        printf ("0x%x:%d\n", (unsigned int)tmp, tmp->val);
        tmp = tmp->next;
    }
}

int main(int argc, char *argv[])
{

    insert (5);
    print();
    insert (6); insert(7); insert(4);
    print();
    delete (7);
    print();
    delete (4);
    print();
    insert(10);
    print();
}

/*end linkedlist */
