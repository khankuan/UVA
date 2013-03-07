#include <cstdio>
using namespace std;

int main(void){
    int count,test = 0;
    while(true){
        test++;
        scanf("%d",&count);
        if (count == 0)
           break;
           
        int arr[count];
        int sum = 0;
        for (int i = 0; i < count; i++){
            scanf("%d",&arr[i]);
            sum += arr[i]; 
        }
    
        int avg = sum/count;
        
        int moves = 0;
        for (int i = 0; i < count; i++)
            if (arr[i] > avg)
                 moves += arr[i] - avg;
        
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",test,moves);
    
    
    
    }


    return 0;
}
