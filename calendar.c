/*
 * use option -std=c99, -std=gnu99, -std=c11 or -std=gnu11
 */
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define SPACE ' '
#define START_DAY_INDEX(year) ( 365*(year-1)+(year-1)/4-( (year-1)/100-(year-1)/400 ) )%7+1



void main(void){
    int m[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day_of_week_start, day_of_week_end, day_index, year, days_of_month;
    char cl[13][43][2];
    char week_label[7][4]={"sun", "mon", "tue", "wed", "thu", "fri", "sat"};
    bool is_leap_year = false;

    printf("put Year\n");
    scanf("%d", &year);

    day_index=START_DAY_INDEX(year);
    is_leap_year = ( (year%4)==0 || (year%400)==0 && (year%100)!=0 );

    /* init array */
    for(int i=1; i<=12; ++i){
        for(int j=1; j<=42; ++j){
            cl[i][j][0]=' ';
            cl[i][j][1]=' ';
        }
    }

    /* construct... */
    for(int i=1; i<=12; ++i){
        days_of_month=(i==2 && is_leap_year) ? 29 : m[i];
        for(int j=1; j<=days_of_month; ++j){
            day_index+=1;
            cl[i][day_index][0]=(j<=9) ? ' ' : (char)(j/10+48);
            cl[i][day_index][1]=(char)(j%10+48);
        }
        day_index=day_index%7;
    }
    printf("\n");

    /* loop by couple of month */
    for(int i=1; i<=6; ++i){
        int l=2*(i-1)+1;
        printf("%6c*****%5d年 %3d月*****", SPACE, year, l);
        printf("%6c*****%5d年 %3d月*****\n", SPACE, year, l+1);

        printf("%2c", SPACE); 
        for(int j=0; j<7; ++j){
            printf("%4s", week_label[j]); 
        }
        printf("%2c", SPACE); 
        for(int j=0; j<7; ++j){
            printf("%4s", week_label[j]);
        }
        printf("\n");

        /* loop by week */
        for(int k=1; k<=6; ++k){
            day_of_week_start=7*(k-1)+1;
            day_of_week_end=k*7;

            printf("%2c", SPACE); 
            for(int j=day_of_week_start; j<=day_of_week_end; ++j){
                printf("%3c", cl[l][j][0]);
                printf("%1c", cl[l][j][1]);
            }

            printf("%2c", SPACE);
            for(int j=day_of_week_start; j<=day_of_week_end; ++j){
                printf("%3c", cl[l+1][j][0]);
                printf("%1c", cl[l+1][j][1]);
            }
            printf("\n");
        }
    }
}

