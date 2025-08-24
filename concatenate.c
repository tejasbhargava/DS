#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* next;
    struct node* prev;
    int data;
};
void display(struct node* head){
    struct node* temp = head;
    while(temp != NULL){
        printf(" %d ", temp -> data);
        temp = temp->next;
    }
    printf(" NULL");
}
void concatenate(struct node** x1, struct node** x2){
    
    if(*x1 == NULL){
        *x1 = *x2;
        return;
    }
    if(*x2 == NULL){
        return;
    }
    struct node* temp = *x1;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = *x2;
    (*x2)->prev = temp;
    return;
}
int main(){
    //code
}