#include <stdio.h>
#include <stdlib.h>

struct node{
    void *p_data;
    int type; // 0 if int, 1 if float, 2 if double
    struct node *next;
};

// Append functions
void printList(struct node *head, int type){
    if(head != NULL) {
        if(type == 0){
            printf("%d\n", *(int *)(head->p_data));
        }
        if(type == 1){
            printf("%f\n", *(float *)(head->p_data));
        }
        if(type == 2){
            printf("%f\n", *(double *)(head->p_data));
        }
        printList(head->next, type);
    }
}

void append_int(struct node *head, int value){
    struct node *cur = head;
    struct node cur1;
    cur1.type = 0;

    struct node *node = (struct node *)malloc(sizeof(struct node));
    void *a = malloc(sizeof(int));
    *(int *)a = value;
    
    node->p_data = a;
    node->next = NULL;
    cur->next = node;
    printList(node, cur1.type);
}

void append_float(struct node *head, float value){
    struct node *cur = head;
    struct node cur1;
    cur1.type = 1;
    
    struct node *node = (struct node *)malloc(sizeof(struct node));
    void *b = malloc(sizeof(float));
    *(float *)b = value;
    
    node->p_data = b;
    node->next = NULL;
    cur->next = node;
    printList(node, cur1.type);
}

void append_double(struct node *head, double value){
    struct node *cur = head;
    struct node cur1;
    cur1.type = 2;

    struct node *node = (struct node *)malloc(sizeof(struct node));
    void *c = malloc(sizeof(double));
    *(double *)c = value;

    node->p_data = c;
    node->next = NULL;
    cur->next = node;
    printList(node, cur1.type);
}
void free_list_rec(struct node *head){
    if(head == NULL){
        return;
    }else{
        free_list_rec(head->next);
        free(head);
    }
}

int main(void){
    
    struct node *node0 = (struct node *)malloc(sizeof(struct node));
    
    append_int(node0, 12);
    append_double(node0, 2.00032);
    append_float(node0, 1.2);
    free_list_rec(node0);
    return 0;

}