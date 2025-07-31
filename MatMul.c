#include<stdio.h>
#include<stdlib.h>
int** allocate(int r, int c){
    int** mat = (int**) malloc(r * sizeof(int*));
    for(int i = 0; i < r; i++){
        *(mat + i) = (int*) malloc(c * sizeof(int));
    }
    return mat;
}
void input(int** mat, int r, int c){
    printf("enter values");
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf("%d", &(*(*(mat + i) + j)));
        }
    }
}
void display(int** mat, int r, int c){
    printf("the values are: ");
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            printf("%d ", *(*(mat + i) + j));
        }
        printf("\n");
    }
}
int** matMul(int** mat1, int** mat2, int r1, int r2, int c1, int c2){
    int** ans = allocate(r1, c2);
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c2; j++){
            int sum = 0;
            for(int k = 0; k < c1; k++){
                sum = sum + mat1[i][k] * mat2[k][j];
                ans[i][j] = sum;
            }
        }
    }
    return ans;
}
void freeMat(int** mat, int r, int c){
    for(int i = 0; i < r; i++){
        free(*(mat + i));
    }
    free(mat);
}
int main(){
    int r1, r2, c1, c2;
    printf("input r and c");
    scanf("%d", &r1);
    scanf("%d", &c1);
    scanf("%d", &r2);
    scanf("%d", &c2);

    int** mat1 = allocate(r1, c1);
    int** mat2 = allocate(r2, c2);

    input(mat1, r1, c1);
    input(mat2, r2, c2);

    display(mat1, r1, c1);
    display(mat2, r2, c2);

    int** ans = matMul(mat1, mat2, r1, r2, c1, c2);
    
    display(ans, r1, c2);

    if(ans == NULL){
        printf("Memory not available");
        return 1;
    }
    
    freeMat(mat1, r1, c1);
    freeMat(mat2, r2, c2);
    freeMat(ans, r1, c2);

    return 0;
}