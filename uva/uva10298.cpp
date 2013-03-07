#include <stdio.h>

int main(void){
    char input[1000005];
	gets(input);
	while(input[0]!='.'|| input[1] != 0){
		int length = 1;
		int i;
		for(i = 1; input[i]; i++)
			while(input[i] != input[i%length])
				length++;
		if (i%length == 0)
			printf("%d\n",i/length);
		else
			printf("1\n");
		gets(input);
	}
	return 0;
}
