#include <stdio.h>
#include <math.h>

void main(void){
    int f(int n);
    int z,n;

    n=5;
    z=f(n);
    printf("%3d", z);
}

int f(int n){
    int z;
    if(n==0)
        z=1;
    else
        z=n*f(n-1);
    return(z);
}
