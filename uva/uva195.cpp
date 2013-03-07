#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

void print(char unique[], int uniq, char current[], int taken, int length, int lifes[]){
     
     if (taken == length){
        printf("%s\n", current);
        return;
     }
     for (int i = 0; i < uniq; i++){
         if (lifes[(int)unique[i]] > 0){
            lifes[(int)unique[i]]--;
            current[taken] = unique[i];
            current[taken+1] = '\0';
            print(unique, uniq, current, taken+1, length, lifes);
            lifes[(int)unique[i]]++; 
            current[taken] = '\0';        
         }
     }
     return;
}


int main(void){
    int count;
    scanf("%d",&count);
    
    char input[1000];
    for(int i = 0; i < count; i++){
        scanf("%s",&input);
        int uniqueint[80];
        int uniq = 0;
        int life[256];
        memset(life,0,sizeof(life));
        for (int j = 0; j < strlen(input); j++){
            if (life[(int) input[j]] == 0){
               if (input[j] >= 'a')
                  uniqueint[uniq] = ((int) input[j] - (int)'a')*2 + 1;
               else
                  uniqueint[uniq] = ((int) input[j] - (int)'A')*2;
               uniq++;
            }
            life[(int) input[j]]++;
        }
        
        
        sort(uniqueint,uniqueint + uniq);
        
        char unique[80];
        for (int j = 0; j < uniq; j++){
            if (uniqueint[j]%2 == 0)
               unique[j] = (char) (uniqueint[j]/2 + (int)'A');
            else
               unique[j] = (char) (uniqueint[j]/2 + (int)'a');
        }
                
        char current[1000] = "";   
        print(unique, uniq, current, 0, strlen(input),life);    
    }
    
    system("pause");
    return 0;
}
