// LAB 2

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data; 
    struct node *next;
};

// Problem 1 - printing without recursion
void print_list1(struct node *head){
    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
}

// Problem 2 - printing using recursion
void print_list2(struct node *head){
    if(head != NULL) {
        printf("%d\n", head->data);
        print_list2(head->next);
    }
    
}
// used to check if list printing worked
void append(struct node *head, int value){
    struct node *cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = value;
    node->next = NULL;
    cur->next = node;
}

int main(){
    
    struct node *node0 = (struct node *)malloc(sizeof(struct node));
    node0->data = 3;
    node0->next = NULL;
    append(node0, 10);
    append(node0, 20);
    print_list2(node0);

    return 0;
}