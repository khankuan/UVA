#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;





int main(void){
    
    int row,col,test = 0;;
    while(true){
       test++;
       scanf("%d %d",&row,&col);
       getchar();
       if (row == 0 && col == 0)
          break;
       
    
       char map[row][col];
       for (int i = 0; i < row; i++){
           scanf("%s",&map[i]);
           getchar();
       }
       
       int sX, sY, eX, eY;
       for (int i = 0; i < row; i++){
           for (int j = 0; j < col; j++){
               if (map[i][j] == 'S'){
                  sX = i;
                  sY = j;
               } else if (map[i][j] == 'T'){
                  eX = i;
                  eY = j;
               }
           }
       }

       int ans = -1;
       int visited[row][col][4][5];
       memset(visited,0,sizeof(visited));
       deque<pair<pair<int,pair<int,int> >,pair<int,int > > > Q;
       Q.push_back(make_pair(make_pair(0,make_pair(0,0)),make_pair(sX,sY)));
       bool found = false;
       while (!Q.empty()){
             pair<pair<int,pair<int,int> >,pair<int,int > > cur = Q.front(); Q.pop_front();
             int curX = cur.second.first;
             int curY = cur.second.second;
             int color = cur.first.second.second;
             int dir = cur.first.second.first;
             if (visited[curX][curY][dir][color] != 1){
                 visited[curX][curY][dir][color] = 1;
                 int breadth = cur.first.first;
                 if (curX == eX && curY == eY && color == 0){
                    ans = breadth;
                    found = true;
                    break;
                 }
                 int newX, newY, newDir, newDir2;
                 if (dir == 0){
                    newX = curX - 1;
                    newY = curY;
                    newDir = 1;
                    newDir2 = 3;
                 } else if (dir == 1){
                    newX = curX;
                    newY = curY+1;
                    newDir = 2;
                    newDir2 = 0;
                 } else if (dir == 2){
                    newX = curX+1;
                    newY = curY;
                    newDir = 3;
                    newDir2 = 1;
                 } else {
                    newX = curX;
                    newY = curY-1;
                    newDir = 0;
                    newDir2 = 2;
                 }
                 
                 
                 if (newX >= 0 && newY >= 0 && newX <= row-1 && newY <= col-1 && map[newX][newY] != '#')
                    Q.push_back(make_pair(make_pair(breadth+1,make_pair(dir,(color+1)%5)),make_pair(newX,newY)));
                 Q.push_back(make_pair(make_pair(breadth+1,make_pair(newDir,color)),make_pair(curX,curY)));
                 Q.push_back(make_pair(make_pair(breadth+1,make_pair(newDir2,color)),make_pair(curX,curY)));
             }
       }
       
       if (test != 1)
          printf("\n");
       printf("Case #%d\n",test);
       
       if (found)
          printf("minimum time = %d sec\n",ans);
       else
          printf("destination not reachable\n");
       
    }
    
    
    return 0;
}
