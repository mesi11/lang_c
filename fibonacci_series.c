#include <stdio.h>
#include <stdbool.h>

int fibonacci_item(int);

void main(void){
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        printf("%d\n", fibonacci_item(i));
    }
}

int fibonacci_item(int n){
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }else{
        return ( fibonacci_item(n-1)+fibonacci_item(n-2) );
    }
}

