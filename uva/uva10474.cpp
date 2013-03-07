#include <algorithm>
#include <cstdio>
using namespace std;

int compareints (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

int main(void){
    int ccount = 0;
    int count, qcount;
    while(true){
        scanf("%d %d",&count,&qcount);
        ccount++;
        if (count == 0 && qcount == 0)
           break;
        
        int marbles[count];
        for (int i = 0; i < count; i++)
            scanf("%d",&marbles[i]);
        
        sort(marbles, marbles+count);
        
        int start[10001];
        start[marbles[0]] = 0;
        int i = 1;
        while ( i < count){
              if (marbles[i] != marbles[i-1])
                 start[marbles[i]] = i;
              i++;
        }
        
        int input;
        printf("CASE# %d:\n",ccount);
        for (int i = 0; i < qcount; i++){
            scanf("%d",&input);
            int* search = (int*)bsearch(&input, marbles, count, sizeof(int), compareints);
            if (search != NULL)
                printf("%d found at %d\n",input,start[*search]+1);
            else
                printf("%d not found\n",input);
        }
    
    }
    
    return 0;
}
