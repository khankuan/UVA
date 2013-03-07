#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void){
    int fibon[46];
    map<int,int> finum;
    
    fibon[0] = 1;
    finum[1] = 0;
    fibon[1] = 2;
    finum[2] = 1;
    for (int i = 2; i < 46; i++){
        fibon[i] = fibon[i-1] + fibon[i-2];
        finum[fibon[i]] = i;
    }

    int testcases;
    scanf("%d",&testcases);
    
    for (int test = 0; test< testcases; test++){
        int n;
        scanf("%d",&n);
        int num[n], largest = 0;
        for (int i = 0; i < n; i++){
            scanf("%d",&num[i]);
            if (num[i] > largest)
                  largest = num[i];
        }
        
        char sentence[110];
        getchar();
        gets(sentence);
        
        char ans[110];
        memset(ans, ' ', sizeof(ans));
        ans[finum[largest]+1] = '\0';    
            
        int j = 0;
        for (int i = 0; i < n; i++){
            while(sentence[j] < 'A' || sentence[j] > 'Z')
                j++;
            ans[finum[num[i]]] = sentence[j];
            j++;
        }
 
        printf("%s\n",ans);               
    }
    
    return 0;
}
