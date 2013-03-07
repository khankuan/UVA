#include <cstdio>
#include <queue>
#include <cstdlib>
using namespace std;

int main(void){
    int count;
    scanf("%d",&count);
    for (int test = 0; test < count; test++){
        int ferryLen, numCars;
        scanf("%d %d", &ferryLen, &numCars);
        ferryLen *= 100;
        
        queue<int> cars[2];
        for (int i = 0; i < numCars; i++){
            char input[10];
            int len;
            scanf("%d %s", &len, &input);
            if (input[0] == 'l')
                cars[0].push(len);
            else
                cars[1].push(len);       
        }
        
        int trips = 0;
        int ferryAt = 0;
        int ferryTaken = 0;
        while (cars[0].size() != 0 || cars[1].size() != 0){
              
              while (true){
                    if (cars[ferryAt].size() > 0 && cars[ferryAt].front() + ferryTaken <= ferryLen ){
                       ferryTaken += cars[ferryAt].front();
                       cars[ferryAt].pop();
                    } else
                      break;
              }
              trips++;
              ferryAt = 1 - ferryAt;
              ferryTaken = 0;
        }
        printf("%d\n",trips);
        
    }
    system("pause");
    return 0;
}
