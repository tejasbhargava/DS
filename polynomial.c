#include<stdio.h>
#include<stdlib.h>
struct node{
    int coeff;
    int exp;
    struct node* next;
    struct node* prev;
};
void insert(struct node** head, int coef, int expo){
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->coeff = coef;
    newnode->exp = expo;
    newnode->next = NULL;
    newnode->prev = NULL;
    struct node* temp = *head;
    if(temp == NULL){
        *head = newnode;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    return;
}
void add(struct node** head1, struct node** head2, struct node** result){
    struct node* temp1 = *head1;
    struct node* temp2 = *head2;
    int sumCoeff;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->exp > temp2->exp){
            insert(result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        }
        else if(temp1->exp < temp2->exp){
            insert(result, temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }
    
        else{
            sumCoeff = temp1->coeff + temp2->coeff;
            insert(result, sumCoeff, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    while(temp1 != NULL){
        insert(result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }
    while(temp2 != NULL){
        insert(result, temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }
}
void display(struct node* head) {
    struct node* temp = head;

    while (temp != NULL) {
        if (temp->coeff != 0) {
            printf("%dx^%d", temp->coeff, temp->exp);

            if (temp->next != NULL) {
                if (temp->next->coeff != 0) {
                    printf(" + ");
                }
            }
        }
        temp = temp->next;
    }
    printf("\n");
}



int main(){
    //code
}