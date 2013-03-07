#include <cstdio>
#include <cstring>

int main(void){
    
    char input;
    while(scanf("%c",&input) == 1){
        if (input == '\n'){
           printf("\n");
           continue;
        }
        input -= 7;
        printf("%c",input);

    }
    return 0;
}
