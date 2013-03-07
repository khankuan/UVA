#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int set, num, testcount = 1;
    while(scanf("%d %d",&set,&num) == 2){
        
        int arr[set*2];
        int total = 0;
        for (int i = 0; i < num; i++)  
            scanf("%d",&arr[i]);

        
        for (int i = num; i < set*2; i++)  
            arr[i] = 0;
        sort(arr,arr+2*set);
        
        printf("Set #%d\n",testcount);
        
        testcount++;
        int score[set];
        for (int i = 0; i < set; i++){
            printf(" %d:",i);
            if (arr[i] != 0)
                printf(" %d",arr[i]);
            if (arr[2*set-1-i] != 0)
               printf(" %d",arr[2*set-1-i]);
            printf("\n");
            score[i] = arr[i] + arr[2*set-1-i];
            total += score[i];
        }

        int imbal = 0;
        for (int i = 0; i < set; i++){
            if (score[i]*set < total)
                imbal += total - score[i]*set;
            else
                imbal += score[i]*set - total;
        }
        
        printf("IMBALANCE = %.5lf\n\n",(double)imbal/(double)set);


    }
    
    return 0;
}
