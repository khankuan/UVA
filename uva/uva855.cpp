#include <cstdio>
#include <algorithm>
using namespace std;

int main(void){
    int count;
    scanf("%d",&count);
    
    for (int i = 0; i < count; i++){
        int streets, avenues, friends;
        scanf("%d %d %d", &streets, &avenues, &friends);
        int streetArr[friends], avenueArr[friends];
        for (int j = 0; j < friends; j++)
            scanf("%d %d", &streetArr[j], &avenueArr[j]);
        sort(streetArr, streetArr + friends);
        sort(avenueArr, avenueArr + friends);
        printf("(Street: %d, Avenue: %d)\n",streetArr[((friends-1) >> 1)], avenueArr[((friends-1) >> 1)]);
    }
    system("pause");
    return 0;
}
