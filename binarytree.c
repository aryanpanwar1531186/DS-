#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * L;
    struct Node * R;
};

struct Node *create_node(int data){
    struct Node temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->L=NULL;
    temp->R=NULL;
    
    return temp;
}

struct Node preorder(struct Node root){
    if(root!=NULL){
        printf("Element: %d\n",root->data);
        preorder(root->L);
        preorder(root->R);
    }
}

struct Node postorder(struct Node root){
    if(root!=NULL){
        postorder(root->L);
        postorder(root->R);
        printf("Element: %d\n",root->data);
    }
}

struct Node inorder(struct Node root){
    if(root!=NULL){
        inorder(root->L);
        printf("Element: %d\n",root->data);
        inorder(root->R);
    }
}

int main(){
    struct Node * first = create_node(2);
    struct Node * second = create_node(4);
    struct Node * third = create_node(5);
    struct Node * fourth = create_node(6);

    first->L=second;
    first->R=third;
    third->L=fourth;

    printf("Elements in INORDER:\n");
    inorder(first);
    printf("Elements in PREORDER:\n");
    preorder(first);
    printf("Elements in POSTORDER:\n");
    postorder(first);
}