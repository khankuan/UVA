#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
    
    while(true){
        int height, width;
        scanf("%d %d", &height, &width);
        char maze[height+2][width+2];
        scanf("%c",&maze[0][0]);
        int visited[height+2][width+2];
        memset(visited, 0, sizeof(visited));
        
        if (height + width == 0)
           break;
           
        for (int i = 0; i < height+1; i++)
            maze[i][0] = maze[i][width+1] = '1';
        for (int i = 1; i < width+1; i++)
            maze[0][i] = maze[height+1][i] = '1';  
           
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++)
                scanf("%c",&maze[i+1][j+1]);
            
            scanf("%c",&maze[0][0]);
        }
        
        int curx = 1;
        int cury = height;
        int dirx = 1;
        int diry = 0;
        while (true){
              
            if (maze[cury + diry][curx + dirx] == '1'){
                if (dirx == 1 && diry == 0){
                    dirx = 0;
                    diry = -1;
                } else if (dirx == 0 && diry == -1){
                    dirx = -1;
                    diry = 0;
                } else if (dirx == -1 && diry == 0){
                    dirx = 0;
                    diry = 1;
                } else {
                    dirx = 1;
                    diry = 0;
                }
                continue;
            }
            
            
            char frontRight;
            if (dirx == 1 && diry == 0)
               frontRight = maze[cury + diry + 1][curx + dirx];
            else if (dirx == 0 && diry == -1)
               frontRight = maze[cury + diry][curx + dirx + 1];
            else if (dirx == -1 && diry == 0)
               frontRight = maze[cury + diry - 1][curx + dirx];
            else
               frontRight = maze[cury + diry][curx + dirx - 1];
            
            
            if (frontRight == '1'){
                visited[cury][curx]++;
                cury += diry;
                curx += dirx;
            } else{
                visited[cury][curx]++;
                if (curx+dirx == 1 && cury+diry == height)
                   break;
                visited[cury + diry][curx + dirx]++;
                
                if (dirx == 1 && diry == 0){
                    curx += 1;
                    cury += 1;
                    dirx = 0;
                    diry = 1;
                } else if (dirx == 0 && diry == 1){
                    curx -= 1;
                    cury += 1;
                    dirx = -1;
                    diry = 0;
                } else if (dirx == -1 && diry == 0){
                    curx -= 1;
                    cury -= 1;
                    dirx = 0;
                    diry = -1;
                } else {
                    curx += 1;
                    cury -= 1;
                    dirx = 1;
                    diry = 0;
                }
            }      
            
            if (curx == 1 && cury == height)
               break;
        }
        
        int count[5];
        memset(count, 0, sizeof(count));
        for (int i = 0; i < height; i++){                    
            for (int j = 0; j < width; j++){
                if (maze[i+1][j+1] != '1' && visited[i+1][j+1] < 5)
                   count[visited[i+1][j+1]]++;            
            }           
        }
        
        for (int i = 0; i < 5; i++)
            printf("%3d",count[i]);
        printf("\n");
        
    }
    
    system("pause");
    return 0;
}
