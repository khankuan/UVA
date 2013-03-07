#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare_str(const void* a, const void* b) {
    char* arg1 = (char*) a;
    char* arg2 = (char*) b;
    return strcmp(arg1, arg2);
}

int compare_char(const void* a, const void* b) {
    char* arg1 = (char*) a;
    char* arg2 = (char*) b;
    return strcmp(arg1, arg2);
}

int main(void){
    char str[1000][20];
    char str2[1000][20];
    int counted[1000];
    memset(counted, 0, sizeof(counted));
    int count = 0;
    
    while(1){
        char input[20];
        scanf("%s",&input);
        if (input[0] == '#')
           break;
        
        strcpy(str[count],input);
        strcpy(str2[count],input);
        int i;
        for (i = 0; i < strlen(str2[count]); i++){
            if (str2[count][i] < 'a')
               str2[count][i] += 32;
        }
        count++;
    }
    
    int i;
    for (i = 0; i < count; i++)
        qsort(&str2[i], strlen(str2[i]), sizeof(char), compare_char);
        
    for (i = 0; i < count; i++){
        if (counted[i])
           continue;
        int j;
        for (j = i+1; j < count; j++){
            if (strcmp(str2[i],str2[j]) == 0)
               counted[i] = counted[j] = 1;
        }
    }
   
    
    char str3[1000][20];
    int unique = 0;
    for (i = 0; i < count; i++){
        if (counted[i] == 0){
           strcpy(str3[unique] ,str[i]);
           unique++;
        }
    }
    
    qsort(str3, unique, 20*sizeof(char), compare_str);
    for (i = 0; i < unique; i++)
        printf("%s\n",str3[i]);
    
    system("pause");
    return 0;
}
