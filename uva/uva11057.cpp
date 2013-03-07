#include <algorithm>
#include <cstdio>
using namespace std;

int compareints (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(void){
    
    int count;
    while(scanf("%d",&count) == 1){
        int books[count];
        for (int i = 0; i <  count; i++)
            scanf("%d",&books[i]);
        
        int money;
        scanf("%d",&money);
        
        int first = 1000005,second = 0;
        sort(books, books+count);

        for (int i = 0; i < count; i++){
            int bookTwo = money - books[i];
            if (books[i] > money)
               break;
            if ((int*)bsearch(&bookTwo, books, count, sizeof(int), compareints) != NULL){
           
               if ((books[i] << 1) == money) {
                   if (i != count-1 && books[i+1] == books[i])
                       if (abs(first - second) > abs((books[i] << 1) - money)){
                          first = books[i];
                          second = money - books[i];
                       }
               } else if (abs(first - second) > abs((books[i] << 1) - money)){
                      first = books[i];
                      second = money - books[i];
                 }
            }
        }
        if (first < second)
            printf("Peter should buy books whose prices are %d and %d.\n\n",first,second);
        else
            printf("Peter should buy books whose prices are %d and %d.\n\n",second,first);
    }
    
    return 0;
}
