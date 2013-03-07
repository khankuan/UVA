#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void){
    int testcases;
    bool first = true;
    scanf("%d",&testcases);
    for (int test = 0; test < testcases; test++){
        if (first)
            first = false;
        else
            printf("\n");
        int ax, ay, bx, by, cx, cy, dx, dy;
        scanf("%d %d %d %d %d %d %d %d",&ax, &ay, &cx, &cy, &bx, &by, &dx, &dy);
        int px, py, qx, qy;
        px = max(ax,bx);
        py = max(ay,by);
        qx = min(cx,dx);
        qy = min(cy,dy);
        if (qx > px && qy > py)
             printf("%d %d %d %d\n",px,py,qx,qy);
        else 
             printf("No Overlap\n");

    }    
    
    
    return 0;
}
