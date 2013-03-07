#include <stdio.h>
#include <string.h>
#include <math.h>

char land;

int fill(int i, int j, int row, int col, char map[20][20]){
    map[i][j] = (char)(land+1);
    int flood = 1;
    if (i > 0 && map[i-1][j] == land)
       flood += fill(i-1,j,row,col,map);
    if (i < row-1 && map[i+1][j] == land)
       flood += fill(i+1,j,row,col,map);
    if (map[i][((j+col)-1)%col] == land)
       flood += fill(i,((j+col)-1)%col,row,col,map);
    if (map[i][(j+1)%row] == land)
       flood += fill(i,(j+1)%row,row,col,map);
    return flood;
}

int main(void){
    
    int row, col;
    char map[20][20];
    while(scanf("%d %d",&row,&col) == 2){ 
        
        char dummy;
        scanf("%c",&dummy);
        for (int i = 0; i < row; i++){
            for (int j=  0; j < col ; j++)
                scanf("%c",&map[i][j]);
            scanf("%c",&dummy);
        }
        
        int kingRow, kingCol;
        scanf("%d %d",&kingRow, &kingCol);
        land = map[kingRow][kingCol];
        
        fill(kingRow,kingCol,row,col,map);
        
        int maxLand = 0;
        for (int i = 0; i < row; i++){
            for (int j=  0; j < col ; j++){
                if (map[i][j] == land){                           
                   int contSize = fill(i,j,row,col,map);
                   if (contSize > maxLand)
                      maxLand = contSize;
                }
            }
        }
        printf("%d\n",maxLand);
                
    }
    return 0;
}
