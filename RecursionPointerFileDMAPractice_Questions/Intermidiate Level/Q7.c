//Create a recursive function to find the greatest common divisor (GCD) of two numbers.
#include<stdio.h>

int findGCD(int x, int y){
    if(y == 0){
        return x;
    }
    return findGCD(y, x % y);
}

int main(){
    int gcd, x, y;

    printf("Enter two numbers to find their GCD: ");
    scanf("%d%d", &x, &y);

    if(x < 0){
        x = -(x);
    }
    if(y < 0){
        y = -(y);
    }

    gcd = findGCD(x, y);

    printf("The GCD of %d, %d = %d", x, y, gcd);
}
