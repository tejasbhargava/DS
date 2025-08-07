#include<stdio.h>
#include<stdlib.h>

struct student{
    char name[100];
    int roll;
    char grade;
};
void read(struct student* s){
    scanf("%s", s->name);
    scanf("%d", &s->roll);
    scanf(" %c", &s->grade);
}
void display(struct student* s){
    printf("%s\n", s->name);
    printf("%d\n", s->roll);
    printf("%c\n", s->grade);
}
void sort(struct student* s, int n){
    struct student temp;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if((s + j) ->roll > (s + j + 1) -> roll){
                temp = *(s + j);
                *(s + j) = *(s + j + 1);
                *(s + j + 1) = temp;
            }
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    struct student* s = (struct student*) malloc(n * sizeof(struct student));
    for(int i = 0; i < n; i++){
        read(&s[i]);
    }
    for(int i = 0; i < n; i++){
        display(&s[i]);
    }
    printf("\n\n");

    sort(s, n);

    printf("\n\n");
    for(int i = 0; i < n; i++){
        display(&s[i]);
    }

    return 0;
}