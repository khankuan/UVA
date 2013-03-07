#include <cstdio>
#include <queue>
using namespace std;

int main(void){
    int count;
    while(true){
        scanf("%d", &count);
        if (count == 0)
           break;
        priority_queue< int, std::vector<int>, std::greater<int> > PQ;
        int input;
        for (int i = 0; i < count; i++){
            scanf("%d", &input);
            PQ.push(input);
        }
        
        int total = 0;
        int sum;
        while (PQ.size() != 1){            
              sum = PQ.top();
              PQ.pop();
              sum += PQ.top();
              PQ.pop();
              total += sum;
              PQ.push(sum);
        }
        printf("%d\n", total);   
    }
    return 0;
}
