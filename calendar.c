#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void main(void){
    char space=' ';
    int m[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i, j, day_of_week_start, day_of_week_end, day_index, year, days_before, days_of_month, k, l;
    char cl[13][43][2];
    char week_label[7][4]={"sun", "mon", "tue", "wed", "thu", "fri", "sat"};
    bool is_leap_year = false;

    printf("put Year\n");
    scanf("%d", &year);

    /* init array */
    for(i=1; i<=12; ++i){
        for(j=1; j<=42; ++j){
            cl[i][j][0]=' ';
            cl[i][j][1]=' ';
        }
    }

    days_before=365*(year-1)+(year-1)/4-( (year-1)/100-(year-1)/400 );
    day_index=days_before%7+1;
    is_leap_year = ( (year%4)==0 || (year%400)==0 && (year%100)!=0 );

    for(i=1; i<=12; ++i){
        days_of_month=(i==2 && is_leap_year) ? 29 : m[i];
        for(j=1; j<=days_of_month; ++j){
            day_index+=1;
            cl[i][day_index][0]=(j<=9) ? ' ' : (char)(j/10+48);
            cl[i][day_index][1]=(char)(j%10+48);
        }
        day_index=day_index%7;
    }
    printf("\n");

    l=0;
    /* loop by couple of month */
    for(i=1; i<=6; ++i){
        l=2*(i-1)+1;
        printf("%6c*****%5d年 %3d月*****", space, year, l);
        printf("%6c*****%5d年 %3d月*****\n", space, year, l+1);

        printf("%2c", space); 
        for(j=0; j<7; ++j){
            printf("%4s", week_label[j]); 
        }
        printf("%2c", space); 
        for(j=0; j<7; ++j){
            printf("%4s", week_label[j]);
        }
        printf("\n");

        /* loop by week */
        for(k=1; k<=6; ++k){
            day_of_week_start=7*(k-1)+1;
            day_of_week_end=k*7;

            printf("%2c", space); 
            for(j=day_of_week_start; j<=day_of_week_end; ++j){
                printf("%3c", cl[l][j][0]);
                printf("%1c", cl[l][j][1]);
            }

            printf("%2c", space);
            for(j=day_of_week_start; j<=day_of_week_end; ++j){
                printf("%3c", cl[l+1][j][0]);
                printf("%1c", cl[l+1][j][1]);
            }
            printf("\n");
        }
    }
}

