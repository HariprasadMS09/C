#include<stdio.h>

void findTables(int tables[][10], int r, int c, int num){
    for(int i=1;i<=c;i++){
        tables[r][i] = num*i;
    }

}

int main(){
    int tables[10][10];
    findTables(tables, 0, 10, 2);
    findTables(tables, 1, 10, 3);
    for(int i=0;i<2;i++){
        for(int j=1;j<=10;j++){
            printf("%d\t",tables[i][j]);
        }
        printf("\n");
    }
}
