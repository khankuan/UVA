#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main(void){
    int testcases;
    scanf("%d",&testcases);
    for (int test = 0; test < testcases; test++){
        int count;
        scanf("%d",&count);
        int deck[count][53];
        for (int i = 0; i < count; i++)
            for (int j = 1; j < 53; j++)
                scanf("%d",&deck[i][j]);
                
        getchar();
        string input;
        int seen[count];
        int types = 0;
        while (true){
              getline(cin,input);
              if (input.length() == 0)
                 break;
              char input2[200];
              for (int i = 0; i < input.length(); i++)
                  input2[i] = input[i];
              input2[input.length()] = '\0';
              seen[types] = 0;
              for (int i = 0; i < strlen(input2); i++){
                  seen[types] *= 10;
                  seen[types] += input2[i] - '0';
              }
              seen[types]--;
              types++;
        }
        
        int arr[53];
        for (int i = 1; i < 53; i++)
            arr[i] = i;
        
        for (int i = 0; i < types; i++){
            int previousarr[53];
            for (int j = 1; j < 53; j++)
                previousarr[j] = arr[j];
            for (int j = 1; j < 53; j++)
                arr[j] = previousarr[deck[seen[i]][j]];
            
        }
    
        for (int i = 1; i < 53; i++){
            arr[i]--;
            if (arr[i] % 13 > 8 && arr[i] != 0){
               if (arr[i] % 13 == 9)
                  printf("Jack");
               else if (arr[i] %13 == 10)
                    printf("Queen");
               else if (arr[i] % 13 == 11)
                    printf("King");
               else
                   printf("Ace");
            } else
              printf("%d",arr[i] %13 +2);
            
            if (arr[i] / 13 == 0)
               printf(" of Clubs\n");
            else if (arr[i] / 13 == 1)
                 printf(" of Diamonds\n");
            else if (arr[i] /13 == 2)
                 printf(" of Hearts\n");
            else printf(" of Spades\n");
        
        }
        if (test != testcases -1)
           printf("\n");
    }

    system("pause");
    return 0;
}
