#include <stdio.h>
#include <string.h>

struct stack {
    int top;
    char data[10];
};

void push(struct stack* s, char val) {
    if (s->top >= 9) {
        printf("Exceeded capacity\n");
        return;
    }
    s->top++;
    s->data[s->top] = val;
}

char pop(struct stack* s) {
    if (s->top == -1) {
        printf("Empty stack\n");
        return '\0'; 
    }
    char popped = s->data[s->top];
    s->top--;
    return popped;
}

int isPalindrome(struct stack* s, char str[]) {
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        push(s, str[i]);
    }


    for (int i = 0; i < len; i++) {
        if (str[i] != pop(s)) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    struct stack s;   
    s.top = -1;       

    char ch[10];
    scanf("%s", ch);

    if (isPalindrome(&s, ch)) {
        printf("Palindrome\n");
    } else {
        printf("Not Palindrome\n");
    }

    return 0;
}


