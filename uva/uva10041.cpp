#include <cstdio>
#include <algorithm>
using namespace std;


int main(void){
    int testcases;
    scanf("%d",&testcases);
    for (int test = 0; test < testcases; test++){
        int count;
        scanf("%d",&count);
        int arr[count];
        for (int i = 0; i <count; i++)
            scanf("%d",&arr[i]);
            
        sort(arr,arr+count);
        int median = arr[count/2];
        int median2 = arr[(count-1)/2];
        
        int min1 = 0, min2 = 0;
        for (int i = 0; i < count; i++){
            if (arr[i] > median)
               min1 += arr[i] - median;
            else
                min1 += median - arr[i];
            if (arr[i] > median2)
               min2 += arr[i] - median2;
            else
                min2 += median2 - arr[i];
        }
    
    
        printf("%d\n",min(min1,min2));
    }
        
    return 0;
}
