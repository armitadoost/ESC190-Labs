#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// QUESTION 1
char *my_strcat(char *dest, char *src){
    int j, i;
    int len1 = 0;
    for(i = 0; dest[i] != NULL; i++){
        len1 ++;
    }
    for (j = 0; src[j] != NULL; j++){
        dest[len1 + j] = src[j]; // adds to dest string
        }
    dest[i + j] = NULL; //adds NULL to the end of the string
    return dest;
}

// Question 2
int removed = 0;
int my_strcmp_rec(char *str1, char *str2){
    int i = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    while (str1[i] != NULL && str2[i] != NULL){
        if (str1[i] == str2[i]){
            removed++;
            my_strcmp_rec(str1 += 1, str2 += 1);
        }

        else if (str1[i] != str2[i]){
            str1 -= removed;
            str2 -= removed;
            return str1[removed] - str2[removed];
        }
    }
    return 0;
}

// Problem 3
int my_atoi(char *str){
    int result = 0;
    int i = 0;
    for(i=0; str[i] != NULL; i++){
        result = result * 10 + (str[i] - '0'); //adds a 0 to change to char value
    }
    return result;
}

// Problem 4
struct node{
    int data; 
    struct node *next;
};

void append(struct node *head, int value){
    struct node *cur = head;
    struct node *node = (struct node *)malloc(sizeof(struct node));
    
    node->data = value;
    node->next = NULL;
    cur->next = node;
}

int floyd_cycle(struct node *head){
    struct node *t = head;
    struct node *h = head->next;
 
    while (t != h) {
        if(h == NULL || h->next == NULL){
            return 0;
        }
        t = t->next;
        h = head->next->next;
    }
    return 1;

}


int main(void){

    // Problem 1
    char word1[7] = "Hello ";
    char word2[6] = "World";
    printf(my_strcat(word1, word2));

    //Problem 2
    char word3[3] = "Hz";
    char word4[6] = "Hblel";
    int val1 = my_strcmp_rec(word3, word4);
    printf("\n%d", val1);

    // Problem 3
    char str[7] = "123456";
    int val2 = my_atoi(str);
    printf("\n%d", val2);

    // Problem 4
    struct node *node0 = (struct node *)malloc(sizeof(struct node));
    node0->data = 20;
    node0->next = NULL;

    int loop = floyd_cycle(node0);
    printf("\n%d",loop);


}