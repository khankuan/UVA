#include <stdio.h>

int main(void){
	char current;
	int count = 0;
	bool isWord = false;
	while(1){            
        int check = scanf("%c",&current);  
        if (check != 1)
           break;
        if ((current >= 'a' && current <= 'z') || (current >= 'A' && current <= 'Z')) {
    	   if (!isWord){
              isWord = true;
    	      count++;
           }
        } else{
          isWord = false;
          if (current == '\n'){
             printf("%d\n",count);
             count = 0;
          }
        }
	}

   return 0;
}
