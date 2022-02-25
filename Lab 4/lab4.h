#if !defined(LINKEDLIST_H)
#define LINKEDLIST_H

struct node{
    int data;
    struct node *next;
};

void insert_value(struct node *head, int value);
void free_list(struct node *head);
void delete_node(struct node *head, int value);
void print_linked_list(struct node *head);

#endif