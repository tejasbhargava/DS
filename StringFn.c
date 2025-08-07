#include<stdio.h>
#include<stdlib.h>
int length(char ch[]){
    int count = 0;
    for(int i = 0; ch[i] != '\0'; i++){
        count = count + 1;
    }
    return count;
}
char* concat(char ch1[], char ch2[]){
    int i = 0, j = 0;
    char* ans = (char*) malloc (length(ch1) + length(ch2) + 2);
    if (ans == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    while(ch1[i] != '\0'){
        ans[i] = ch1[i];
        i++;
    }
    while(ch2[j] != '\0'){
        ans[i] = ch2[j];
        i++;
        j++;
    }
    ans[i] = '\0';
    return ans;
}
int comparision(char ch1[], char ch2[]){
    int i = 0;
    int flag = 0;
    while(ch1[i] != '\0' && ch2[i] != '\0'){
        if(ch1[i] > ch2[i]){
            flag = 1;
            break;
        }
        else if(ch1[i] < ch2[i]){
            flag = -1;
            break;
        }
        else{
            i++;
        }
    }
    if(flag == 0){
        if(length(ch1) > length(ch2)){
            flag = 1;
        }
        else if(length(ch1) < length(ch2)){
            flag = -1;
        }
    }
    return flag;
}
char* insert_substring(char* ch, char sub[], int pos){
    int len_ch = length(ch);
    int len_sub = length(sub);
    char* temp = (char*) realloc(ch, len_ch + len_sub + 2);
    ch = temp;
    for(int i = len_ch - 1; i >= pos; i--){
        ch[i + (len_sub)] = ch[i];
    }
    int j = 0;
    for(int i = 0; i < len_sub; i++){
        ch[pos + i] = sub[i];
    }
    ch[len_ch + len_sub] = '\0';
    return ch;
}
void delete_substring(char* ch, int pos, int len_sub){
    int len_ch = length(ch);
    int i;
    for(i = pos + len_sub -1; i < len_ch; i++){
        ch[pos - 1] = ch[i];
        pos++;
    }
    ch[i] = '\0';
}
int main(){
    char* ch1 = (char*) malloc(100 * sizeof(char));
    char* ch2 = (char*) malloc(100 * sizeof(char));
    char* sub = (char*) malloc(100 * sizeof(char));
    scanf("%s", ch1);
    scanf("%s", ch2);
    scanf("%s", sub);

    int len1 = length(ch1);
    printf("%d \n", len1);
    int len2 = length(ch2);
    printf("%d\n", len2);

    char* ans = concat(ch1, ch2);
    printf("%s", ans);
    printf("\n");

    int comp = comparision(ch1, ch2);
    printf("%d \n", comp);

    int pos;
    scanf("%d", &pos);
    char* ans_sub = insert_substring(ch1, sub, pos);
    printf("%s", ans_sub);

    int pos1, len_sub;
    scanf("%d", &pos1);
    scanf("%d", &len_sub);
    delete_substring(ch1, pos1, len_sub);
    printf("%s", ch1);

    return 0;
}