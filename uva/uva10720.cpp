#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void){
    int count;
    while (true){
          scanf("%d", &count);
          if (count == 0)
             break;
             
          bool possible = true;
          int num[count];
          
          for (int i = 0; i < count; i++){
              scanf("%d",&num[i]);
              if (num[i] == 0){
                 i--;
                 count--;
              }
              if (num[i] < 0)
                 possible = false;
          }
          if (possible) {                
          
              sort(num, num+count);
              int sum = 0;
                  
              for (int i = 1; i < count+1; i++){
                  sum += num[count - i];
                  int second_sum = i * (i-1);
                  for (int j = i+1; j < count+1; j++)       
                       second_sum += (i < num[count-j]) ? i : num[count - j];          
                  //printf("%d %d\n",sum,second_sum);
                  if (sum > second_sum){
                     possible = false;
                     break;
                  }                 
              }
                  
              if (possible && sum % 2 == 0)                 
                  printf("Possible\n");          
              else
                  printf("Not possible\n");
          } else
            printf("Not possible\n");
    }
    return 0;
}
