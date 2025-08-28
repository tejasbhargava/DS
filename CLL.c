#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insertAtEnd(struct node** first, struct node** last, int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    if(*first == NULL){
        *first = newnode;
        *last = newnode;
        newnode->next = newnode;
        return;
    }
    (*last)->next = newnode;
    newnode->next = *first;
    *last = newnode;    
    return;
}
void delBeg(struct node** first, struct node** last){
    struct node* temp;
    if(*first == NULL){
        printf("list is empty");
        return;
    }
    if(*first == *last){
        *first = NULL;
        *last = NULL;
        return;
    }
    temp = *first;
    *first = (*first)->next;
    (*last)->next = *first;
    free(temp);
    return;
}
void delEnd(struct node** first, struct node** last){
    struct node* temp = *first;
    struct node* prev = NULL;       
    if(*first == NULL){
        printf("list is empty");
        return;
    }
    if(*first == *last){
        *first = NULL;
        *last = NULL;
        return;
    }
    while(temp->next != *first){
        prev = temp;
        temp = temp->next;
    }
    prev->next = *first;
    *last = prev;
    free(temp);
    return;
}
void display(struct node** first, struct node** last){
    struct node* temp = *first;
    while(temp->next != *first){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
    printf(" back to-> %d", (*first)->data);
    printf("\n");
}
int main(){
    //code
}