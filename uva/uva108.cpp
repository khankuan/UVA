#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void){
    int size;
    scanf("%d",&size);
    int value[size][size];
    int sum[size][size];
    for (int i = 0; i <size; i++){
        for (int j = 0; j <size; j++)
            scanf("%d",&value[i][j]);
    }
    
    sum[0][0] = value[0][0];
    
    for (int i = 1; i <size; i++){
        sum[i][0] = value[i][0] + sum[i-1][0];
        sum[0][i] = value[0][i] + sum[0][i-1];
    }
    
    for (int i = 1; i <size; i++){
        for (int j = 1; j <size; j++)
            sum[i][j] = value[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
    }
    
    int max = -20000000;
    for (int y1 = 0; y1 < size; y1++){
        for (int x1 = 0; x1 < size; x1++){
            for (int y2 = y1; y2 < size; y2++){
                for (int x2 = x1; x2 < size; x2++){
                    int recSize = sum[y2][x2];
                    if (y1 > 0)
                       recSize -= sum[y1-1][x2];
                    if (x1 > 0)
                       recSize -= sum[y2][x1-1];
                    if (y1 >0 && x1 > 0)
                       recSize += sum[y1-1][x1-1];
                    if (recSize > max)
                       max = recSize;
                } 
            } 
        } 
    } 
    printf("%d\n",max);
    system("pause");
    return 0;
}
