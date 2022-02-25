// LAB 1

#include <stdio.h>

// Question 1 -- Use Pointers

void f(int *a)
{
    *a = 10;
}

// Question 2

void insertionsort(int arr[], int size){
    int i = 1;
    for(i = 1; i < size; i++){
        int check = arr[i];
        int side = i - 1;

        // Now compare to each element before the check value
        while (check < arr[side] && side >= 0){
            arr[side + 1] = arr[side];
            arr[side] = check;
            side = side - 1;

        }
        
    }
}

int main()
{
    // QUESTION 1
    int a;
    a = 5;
    printf("a is: %d", a);
    f(&a); // at the address of a, the value changes to 10
    printf("\na is now: %d\n", a);

    // QUESTION 2
    int arr[] = {3, 4, 7, 5, 10, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertionsort(arr, size);

    // To print out array
    int i = 0;
    for (i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }


    return 0;
}