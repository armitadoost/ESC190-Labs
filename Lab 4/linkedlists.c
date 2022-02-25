#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

// Inserting value
void insert_value(struct node *head, int value){
    struct node *cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    //cur->next is now equal to null
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = value;
    node->next = NULL;
    cur->next = node;
}


// Deleting a node
void delete_node(struct node *head, int value){
    struct node *cur = head;
    struct node *prev = head;
    struct node *node = (struct node *)malloc(sizeof(struct node));

    while (cur != NULL && cur->data != value){ //find the placement of the value to be deleted
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL){ // value was not in list
        return;
    }
    prev->next = cur->next;
    free(cur);
}

// Freeing linked list
void free_list(struct node *head){
    if(head == NULL){
        return;
    }else{
        free_list(head->next);
        free(head);
    }
}

 //Printing the linked list
void print_linked_list(struct node *head)
{
    while(head){
        printf("%d ", head->data);
        head = head->next;
    }
}