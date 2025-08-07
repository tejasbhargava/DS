#include<stdio.h>
#include<stdlib.h>

struct student{
    char name[100];
    int roll;
    float marks;
};
void read(struct student* s){
    scanf("%s", s->name);
    scanf("%d", &s->roll);
    scanf("%f", &s -> marks);
}
void display(struct student* s, int n){
    for(int i = 0; i < n; i++){
        printf("%s\n", (s + i) -> name);
        printf("%d\n", (s + i) -> roll);
        printf("%f\n", (s + i) -> marks);
    }
}
struct student* highestMarks(struct student* s, int n){
    struct student* highest = s;
    struct student temp;
    for(int i = 0; i < n; i++){
        if((s + i) -> marks > highest -> marks){
            highest = (s + i);
        }
    }
    return highest;
}
int main(){
    int n;
    scanf("%d", &n);
    struct student* s = (struct student*) malloc(n * sizeof(struct student));
    for(int i = 0; i < n; i++){
        read(&s[i]);
    }

    display(s, n);
    
    printf("\n\n");

    struct student* h = highestMarks(s, n);

    printf("\n\n");
    
    printf("%s\n", h -> name);
    printf("%d\n", h -> roll);
    printf("%f\n", h -> marks);

    return 0;
}