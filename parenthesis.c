#include<stdio.h>

struct stack{
    int top;
    char data[10];
};
void push(struct stack* s, char val){
    if(s->top > 9) printf("exceeded capacity");
    s->top = s->top + 1;
    s->data[s->top] = val;
}
int pop(struct stack* s){
    if(s->top == -1){
        printf("empty stack");
        return -1;
    }
    
    int popped = s->data[s->top];
    s->top -= 1;
    return popped;
}
int peek(struct stack* s){
    if(s->top == -1){
        printf("empty stack");
    }
    return s->data[s->top];
}
int ParenthesesBalanced(struct stack* s, char expr[]) {

    for (int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(s, ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s->top == -1) return 0; 

            char top = pop(s);
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return 0;
            }
        }
    }
    if(s->top == -1){
        return 1;
    }
    return 0;
}
int main() {
    struct stack s;   
    s.top = -1;       

    char ch[10];
    scanf("%s", ch);

    if (ParenthesesBalanced(&s, ch)) {
        printf("balanced\n");
    } else {
        printf("Not balanced\n");
    }

    return 0;
}
