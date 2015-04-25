#include <stdio.h>

void main(void){
    int work,i,k,*p;
    int a[6]={0,8,3,2,5,1};
    p=&a[0];

    for(k=5;k>1;--k){
        for(i=0;i<k;++i){
            if(*(p+i)>*(p+i+1)){
                work=*(p+i);
                *(p+i)=*(p+i+1);
                *(p+i+1)=work;
            }
        }
    }
    for(i=0; i<=5; ++i){
        printf("%3d", p[i]);
    }
    printf("\n");
}

