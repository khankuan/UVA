#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

char cell[200][200];
int countPaths[200][200], startX, startY;
int size;

int numPaths(int x, int y) {
     if (x == 0) {countPaths[x][y] = 1; return 1;}
     if (countPaths[x][y] != -1) return countPaths[x][y];

     countPaths[x][y] = 0;
     if (cell[x-1][y-1] != 'B' && x-1 >= 0 && y-1 >= 0) 
            countPaths[x][y] = (countPaths[x][y] % 1000007 + numPaths(x-1,y-1) % 1000007) % 1000007;
     else if (cell[x-2][y-2] != 'B' && x-2 >= 0 && y-2 >= 0)
            countPaths[x][y] = (countPaths[x][y] % 1000007 + numPaths(x-2,y-2) % 1000007) % 1000007;
     if (cell[x-1][y+1] != 'B' && x-1 >= 0 && y+1 < size) 
            countPaths[x][y] = (countPaths[x][y] % 1000007 + numPaths(x-1,y+1) % 1000007) % 1000007;
     else if (cell[x-2][y+2] != 'B' && x-1 >= 0 && y+2 < size)
            countPaths[x][y] = (countPaths[x][y] % 1000007 + numPaths(x-2,y+2) % 1000007) % 1000007;
     
     return countPaths[x][y];
}


int main(void){
    
    int testcases;
    scanf("%d",&testcases);
    for (int test = 0; test < testcases; test++){
        scanf("%d",&size);
        getchar();
        memset(countPaths,-1,sizeof(countPaths));
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                scanf("%c",&cell[i][j]);
                if (cell[i][j] == 'W'){
                   startX = i;
                   startY = j;
                }
            }
            getchar();
        }
        
        numPaths(startX,startY);
        
        printf("Case %d: %d\n",test+1,countPaths[startX][startY]%1000007);
        
    }

    return 0;
}
