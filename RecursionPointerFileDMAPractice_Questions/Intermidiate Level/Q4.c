//Write a recursive program to solve the Tower of Hanoi problem.
#include<stdio.h>

void towerOfHanoi(int n, char source[20], char destination[20], char auxiliary[20]){
    if(n == 1){
        printf("Move disk 1 from %s to %s\n", source, destination);
        return;
    }

    towerOfHanoi(n-1, source, auxiliary, destination);

    printf("Move disk %d from %s to %s\n", n, source, destination);

    towerOfHanoi(n-1, auxiliary, destination, source);
}

int main(){
    int n;

    printf("Enter the number of disk: ");
    scanf("%d", &n);

    towerOfHanoi(n, "Source", "Destination", "Auxiliary");
    return 0;
}
