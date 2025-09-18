#include<stdio.h>
#include<stdlib.h>
struct stack{
    struct stack* next;
    char data;
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
char pop(struct stack** top){
    if(*top == NULL){
        printf("empty list");
        return -1;
    }
    struct stack* temp = *top;
    char popped = (*top)->data;
    *top = (*top)->next;
    free(temp);
    return popped;
}
char peek(struct stack* top){
    if(top == NULL){
        printf("empty");
        return -1;
    }
    return top->data;
}
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    struct stack* s = NULL;
    int i, k = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9') {
            postfix[k++] = ch;
        } 
        else if (ch == '(') {
            push(&s, ch);
        } 
        else if (ch == ')') {
            while (s != NULL && peek(s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s); 
        } 
        else {
            while (s != NULL && precedence(peek(s)) >= precedence(ch)) {
                postfix[k++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    while (s != NULL) {
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0';
}
int main(){
    struct stack* top = NULL;
    char infix[100], postfix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
    return 0;
}