#include<stdio.h>
#include<stdlib.h>
struct stack{
    struct stack* next;
    int data;
};
void push(struct stack** top, char val){
    struct stack* newnode = (struct stack*)malloc(sizeof(struct stack));
    newnode->next = NULL;
    newnode->data = val;
    if(*top == NULL){
        *top = newnode;
        return;
    }
    newnode->next = *top;
    *top = newnode;
    return;
}
int pop(struct stack** top){
    if(*top == NULL){
        printf("empty list");
        return -1;
    }
    struct stack* temp = *top;
    int popped = (*top)->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}
int peek(struct stack* top){
    if(top == NULL){
        printf("empty");
        return -1;
    }
    return top->data;
}
int evaluatePostfix(char postfix[]) {
    struct stack* s = NULL;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (ch >= '0' && ch <= '9') {
            push(&s, ch - '0');  // convert char to int
        } 
        else {
            int val2 = pop(&s);
            int val1 = pop(&s);
            switch (ch) {
                case '+': push(&s, val1 + val2); break;
                case '-': push(&s, val1 - val2); break;
                case '*': push(&s, val1 * val2); break;
                case '/': push(&s, val1 / val2); break;
                case '^': {
                    int res = 1;
                    for (int j = 0; j < val2; j++) res *= val1;
                    push(&s, res);
                    break;
                    }
            }
        }
    }

    return pop(&s);
}
int main(){
    struct stack* top = NULL;
    char postfix[100];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);
    printf("%d", evaluatePostfix(postfix));
}