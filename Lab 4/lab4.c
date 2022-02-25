#include <stdlib.h>
#include <stdio.h>
#include "lab4.h"

int main(void)
{
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data = 3;
    head->next = NULL;
    insert_value(head, 5);
    insert_value(head, 7);
    insert_value(head, 9);
    print_linked_list(head);

    delete_node(head, 9);
    printf("\n");
    print_linked_list(head);

    free_list(head);

    return 0;
}