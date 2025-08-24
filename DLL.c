#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* next;
    struct node* prev;
    int data;
};

void insertLast(struct node** head, int val){
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->data = val;
    struct node* temp = *head;
    if(temp == NULL){
        *head = newnode;
        newnode->prev = NULL;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    return;
}
void delLast(struct node** head){
    struct node* temp = *head;
    if(temp == NULL){
        printf("empty list");
        return;
    }
    if(temp->next == NULL){
        *head = NULL;
        free(temp);
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    if(temp->prev != NULL){
        temp->prev->next = temp->next;
    }
    free(temp);
}
void insertPos(struct node** head, int val, int pos){
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = NULL;
    struct node* temp = *head;
    struct node* prev = NULL;
    int i = 1;
    if(pos == 1){
        newnode->next = *head;
        if(*head != NULL){
            (*head)->prev = newnode;
        }
        *head = newnode;
        return;
    }
    while(temp != NULL && i < pos){
        prev = temp;
        temp = temp->next;
        i++;
    }
    if(prev != NULL){
        prev->next = newnode;
    }
    
    newnode->next = temp;
    newnode->prev = prev;

    if(temp != NULL){
        temp->prev = newnode;
    }
    
}
void delPos(struct node** head, int pos){
    struct node* temp = *head;
    int i = 1;
    if(pos == 1){
        if(*head == NULL){
            printf("list is empty");
            return;
        }
        if((*head)->next == NULL){
            *head = NULL;
            free(temp);
            return;
        }
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
        return;
    }
    while(temp != NULL && i < pos){
        temp = temp->next;
        i++;
    }
    if(temp == NULL){
        printf("out of bounds");
        return;
    }
    if(temp->prev != NULL){
        temp->prev->next = temp->next;
    }
    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    }
    return;
}
void insertAfterNode(struct node** head, int val, int newval){
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->data = newval;
    struct node* temp = *head;
    while(temp != NULL){
        if(temp->data == val){
            newnode->next = temp->next;
            if(temp->next != NULL){
                temp->next->prev = newnode;
                
            }
            temp->next = newnode;
            newnode->prev = temp;
            return;
        }
        temp = temp->next;
    }
    return;
}
void insertBeforeNode(struct node** head, int val, int newval){
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;
    newnode->data = newval;
    struct node* temp = *head;
    while(temp != NULL){
        if(temp->data == val){
            if(temp->prev != NULL){
                temp->prev->next = newnode;
            }
            else{
                *head = newnode;
            }
            newnode->prev = temp->prev;
            newnode->next = temp;
            temp->prev = newnode;
            return;
        }
        temp = temp->next;
    }
    printf("val not found");
    return;
}
void traverse(struct node* head){
   
    struct node* temp = head;
    while(temp != NULL){
        printf(" %d ", temp -> data);
        temp = temp->next;
    }
    printf(" NULL");
}
void reverseTraversal(struct node* head){
    struct node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    while(temp != NULL){
        printf(" %d ", temp->data);
        temp = temp->prev;
    }
    printf("NULL");
    return;
}
int main(){
    //code
}