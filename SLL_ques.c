#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* next;
    int val;
};
void insertBefore(struct node** head, int newValue, int value){ 
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->val = newValue;
    if (*head == NULL) {
        printf("List is empty.\n");
        free(newnode);
        return;
    }
    struct node* temp = *head;
    struct node* prev = *head;
    if(value == (*head)->val){
        newnode -> next = *head;
        *head = newnode;
        return;
    }
    while(temp->next != NULL){
        if(temp->next->val == value){   
            newnode->next = temp->next;
            temp->next = newnode;
            return;
        }
        temp = temp->next;
    }
    printf("value not found");
    free(newnode);
}

void insertAfter(struct node** head, int newValue, int value){
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->val = newValue;
    newnode->next = NULL;
    if((*head) == NULL){
        printf("List is empty.\n");
        free(newnode);
        return;
    }
    struct node* temp = *head;
    while(temp != NULL){
        if(temp->val == value){
            newnode->next = temp->next;
            temp->next = newnode;
            return;
        }
        temp = temp->next;
    }
    printf("value not found");
    free(newnode);
}
void del(struct node** head, int value){
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = *head;
    if((*head)->val == value){
        struct node* temph = *head;
        *head = (*head)->next;
        free(temph);
        return;
    }
    while(temp->next != NULL){

        if(temp->next->val == value){
            struct node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            free(nodeToDelete);
            return;
        }
        temp = temp->next;
    }
    printf("not found");
    return;
}
void display(struct node* head){
    struct node* temp = head;
    while(temp != NULL){
        printf(" %d ->", temp -> val);
        temp = temp->next;
    }
    printf(" NULL");
}
void reverse(struct node** head){
    struct node* current = *head;
    struct node* prev = NULL;
    struct node* next = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
void sort(struct node** head){
    if (*head == NULL){
        printf("empty list");
        return;
    } 
    struct node* i = (*head);
    struct node* j = NULL;
    int tempData;
    while (i != NULL) {
        j = i->next;
        while (j != NULL) {
            if (i->val > j->val) {
                tempData = i->val;
                i->val = j->val;
                j->val = tempData;
            }
            j = j->next;
        }
        i = i->next;
    }
}
void delAlt(struct node** head){
    if(*head == NULL){
        printf("list is empty");
        return;
    }
    struct node* current = *head;
    struct node* temp;
    while(current != NULL && current->next != NULL){
        temp = current->next;
        current->next = temp->next;
        free(temp);
        current = current->next;
    }
    return;
}
void insertSorted(struct node** head, int value){
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->val = value;
    struct node* temp = *head;
    if(temp == NULL || temp->val > value){
        newnode->next = *head;
        *head = newnode;
        return;
    }
    struct node* prev = NULL;
    while(temp != NULL && temp->val < value){
        prev = temp;
        temp = temp->next;
    }
    prev->next = newnode;
    newnode->next = temp;    
    return;
}

int main(){
    struct node* head = NULL;
    return 0;
}