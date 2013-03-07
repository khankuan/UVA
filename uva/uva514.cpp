#include <cstdio>
#include <stack>
using namespace std;

int main(void){
    while (true){
        int size;
        scanf("%d", &size);
        if (size == 0)
           break;
        while (true){
            int array[size];
            scanf("%d", &array[0]);
            if (array[0] == 0)
               break;
            for (int i = 1; i < size; i++)
                scanf("%d", &array[i]);
            stack<int> rails;
            
            int removing = 0;
            rails.push(1);
            int current = 2;
            bool fail = false;     
            while (removing < size){                 
                  while (rails.top() != array[removing]){
                      rails.push(current);        
                      if (current > size || current > array[removing]){
                         fail = true;
                         break;
                      }
                      current++;
                  }
                  if (fail)
                      break;
                  rails.pop();
                  if (rails.empty()){
                      rails.push(current);
                      current++;
                  }
                  removing++;
            }
            if (fail)
                printf("No\n");
            else
                printf("Yes\n");   
        }
        printf("\n");
    }
    
    
    
    return 0;
}
