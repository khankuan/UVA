#include <cstdio>
#include <cstring>
using namespace std;

int main(void){
    int testcases;
    scanf("%d",&testcases);
    getchar();
    for (int test = 0; test < testcases; test++){
        printf("Case #%d:\n",test+1);
        char str[11000], input[11000];
        int len = 0, sq;
        gets(input);
        for (int i = 0; i < strlen(input); i++){
            if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')){
               str[len] = input[i];
               len++;
            }
        }
        
        bool isSquare = false;
        for (int i = 1; i < 101; i++)
            if (i*i == len){
               isSquare = true;
               sq = i;
               break;
            }
        
        if (!isSquare){
           printf("No magic :(\n");
           continue;
        }    
        
        char arr[sq][sq];
        for (int i = 0; i < len; i++)
            arr[i/sq][i%sq] = str[i];
        
        
        bool isPalin = true;
        for (int i = 0; i < len; i++)
            if (str[i] != str[len-1-i]){
               isPalin = false;
               break;
            }

        if (!isPalin){
           printf("No magic :(\n");
           continue;
        }        
        
        for (int i = sq-1; i >= 0; i--){
            for (int j = 0; j < sq; j++){
                if (arr[i][j] != arr[j][i]){
                   isPalin = false;
                   break;
                }
            }
        }

        if (!isPalin){
           printf("No magic :(\n");
           continue;
        }     
            
            
        for (int i = 0; i < sq; i++){
            for (int j = sq-1; j >=0; j--){
                if (arr[j][i] != arr[i][j]){
                   isPalin = false;
                   break;
                }
            }
        }

        if (!isPalin){
           printf("No magic :(\n");
           continue;
        }     
            
        for (int i = 0; i < sq; i++){
            for (int j = sq-1; j >=0; j--){
                if (arr[i][j] != arr[sq-1-j][sq-1-i]){
                   isPalin = false;
                   break;
                }
            }
        }

        if (!isPalin)
           printf("No magic :(\n");
        else
            printf("%d\n",sq);

    }
    

    return 0;
}
