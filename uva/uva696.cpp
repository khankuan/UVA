#include <cstdio>
#include <algorithm>
using namespace std;

int main(void){
    int rows,cols;
    while (true){
          scanf("%d %d",&rows,&cols);
          if (rows == 0 && cols  == 0)
             break;
          if (rows == 1 || cols  == 1)
             printf("%d knights may be placed on a %d row %d column board.\n",rows * cols, rows, cols);
          else if (rows == 2)
             printf("%d knights may be placed on a %d row %d column board.\n",((((cols >> 2) << 1) + min(cols%4,2)) << 1),rows,cols);
          else if (cols == 2)
             printf("%d knights may be placed on a %d row %d column board.\n",((((rows >> 2) << 1) + min(rows%4,2)) << 1),rows,cols);
          else 
             printf("%d knights may be placed on a %d row %d column board.\n",(rows*cols+1) >> 1,rows,cols);
    }

    system("pause");
    return 0;
}
