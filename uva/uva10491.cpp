#include <cstdio>
using namespace std;

int main()
{
    double cow, car, show;
    while(scanf("%lf%lf%lf", &cow, &car, &show) == 3)
        printf("%.5lf\n", (cow * car + car * (car - 1)) / (car + cow) / (car + cow - show - 1));
    return 0;
}
