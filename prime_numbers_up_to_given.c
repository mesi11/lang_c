/**
 * use option -std=c99, -std=gnu99, -std=c11 or -std=gnu11
 */
#include <stdio.h>
#include <stdbool.h>

void main(){
    int max_number;

    printf("put max number:");
    scanf("%d", &max_number);
    printf("1\n");

    for(int i=2; i<=max_number; ++i){
        bool is_prime=true;
        for(int j=2; j<i; j++){
            if(i%j==0){
                is_prime = false;
                break;
            }
        }
        if(is_prime)printf("%d\n",i);
    }
}

