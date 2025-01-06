#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 15
char binaryTree[MAX_SIZE];

void insert(char value){
    for(int i=0;i<MAX_SIZE;i++){
        if(binaryTree[i] == ' '){
            binaryTree[i] = value;
            break;
        }
        if(i+1 == MAX_SIZE){
            printf("Binary Tree isn't Empty!\n");
        }
    }
}

int leftChild(int index) {
    return 2 * index + 1;
}

int rightChild(int index) {
    return 2 * index + 2;
}


void deleteNode(int index) {
    int leftChildIndex = leftChild(index); // B
    if (leftChildIndex < MAX_SIZE && binaryTree[leftChildIndex] != ' ') {
        int replacementIndex = leftChildIndex;
        binaryTree[index] = binaryTree[replacementIndex];

        deleteNode(replacementIndex);
    } else if (rightChild(index) < MAX_SIZE && binaryTree[rightChild(index)] != ' ') {
        int replacementIndex = rightChild(index);
        binaryTree[index] = binaryTree[replacementIndex];
        deleteNode(replacementIndex);
    } else {
        binaryTree[index] = ' ';
    }
}

void printTree(char arr[], int n, int index, int space) {
    if (index >= n) {
        return;
    }
    printTree(arr, n, rightChild(index), space + 5);
    for (int i = 0; i < space; i++) {
        printf(" ");
    }
    printf("%c\n", arr[index]);
    printTree(arr, n, leftChild(index), space + 5);
}
int mode = 1;
char value;
char status;
int main(){
    for(int i=0;i<MAX_SIZE;i++){
        binaryTree[i] = ' ';
    }
    while(mode != 0){
        printf("Binary Tree Program #^$#*&@^\n\n");
        printf(" [1] Insert Value\n");
        printf(" [2] Delete Value\n");
        printf(" [3] Show Binary Tree \n");
        printf(" [0] Exit \n\n");
        B:
        printf("Enter Mode : ");
        int check = scanf(" %d",&mode);
        if(mode < 0 || mode > 3){
            printf("Got Exception !#!^$!^ | Please Try Again!\n");
            goto B;
        }
        if(mode == 1){
            printf("Enter Insert Value (Character/Number(0-9)) : ");
            scanf(" %c",&value);
            insert(value);
            printf("Binary Tree Display \n");
            printTree(binaryTree, sizeof(binaryTree), 0, 0);
        }else if(mode == 2){
            printf("Enter Delete Value (Character/Number(0-9)) : ");
            scanf(" %c",&value);
            H:
            for(int i=0;i<MAX_SIZE;i++){
                if(binaryTree[i] == value){
                    deleteNode(i);
                    goto H;
                }
            }
            printf("Binary Tree Display \n");
            printTree(binaryTree, sizeof(binaryTree), 0, 0);
        }else if(mode == 3){
            /*printf("[ ");
            for(int i=0;i<MAX_SIZE;i++){
                printf("(%d) %c,",i,binaryTree[i]);
            }
            printf(" ]");*/
            printf("Binary Tree Display \n");
            printTree(binaryTree, sizeof(binaryTree), 0, 0);
        }else if(mode == 0){
            break;
        }
        A:
        printf("Continue (Y/N) : ");
        scanf(" %c",&status);
        if(status == 'Y' || status == 'y'){
            continue;
        }else if (status == 'N' || status == 'n'){
            break;
        }else{
            printf("Got Exception !#!^$!^ | Please Try Again!\n");
            goto A;
        }
    }
}







