#include <stdio.h>
#include <string.h>

int main(void){
    bool isFirst = true;
    int count = 0;
    while(true){
        count++;
        int row, col;
        scanf("%d %d", &row, &col);
        if (row == 0 && col == 0)
           break;
        if (!isFirst)
           printf("\n");
        isFirst = false;
        int array[row+2][col+2];
        memset(array,0,sizeof(array));
        char input;
        scanf("%c",&input);
        for (int i = 1; i < row+1; i++){
            for (int j = 1; j < col+1; j++){
                
                scanf("%c",&input);
                if (input == '*'){
                   array[i][j] = -10;
                   array[i-1][j-1]++;
                   array[i-1][j]++;
                   array[i-1][j+1]++;
                   array[i][j-1]++;
                   array[i][j+1]++;
                   array[i+1][j-1]++;
                   array[i+1][j]++;
                   array[i+1][j+1]++;
                }
            }
            scanf("%c",&input);
        }
        
        printf("Field #%d:\n",count);
        for (int i = 1; i < row+1; i++){
            for (int j = 1; j < col+1; j++){
                if (array[i][j] < 0)
                   printf("*");
                else
                    printf("%d",array[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
