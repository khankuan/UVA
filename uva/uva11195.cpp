#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int allCount;

int recurse(int map[15], int count, int taken){
    if (taken == count)
       return 1;
    /*
    for (int i = 0; i < count; i++){
        for (int j = 0; j  < count; j++){
            printf("%d",(map[i] >> j) & 1);
        
        }printf("\n");
    }
    printf("\n");
    */
    int sum = 0;/*
    int c = 0;
    int tmp = (~map[taken]) & (-(~map[taken]));
    while(tmp > 1){
        tmp /= 2;
        c++;
    }*/
    for (int i = 0; i < count ;i++){
        if ((map[taken] >> i) & 1)
           continue;

        if (!((map[taken] >> i) & 1)) {
           int newmap[15];
           memcpy(newmap,map,sizeof(newmap));
           
           for (int j = 0; j < count ;j++)
               newmap[j] |= (1 << i);
           
           bool restvalid1 = true;
           for (int j = taken+1; j < count; j++)
               if (newmap[j] == allCount){
                  restvalid1= false;
                  break;
               }
           if (!restvalid1)
              continue;
           
           int mini = min(i,taken);
           int outside = abs(i - taken);
           for (int j = 0-mini; j < count-mini-outside ;j++)
               newmap[taken+j] |= (1 << (i+j));
           
           bool restvalid2 = true;
           for (int j = taken+1; j < count; j++)
               if (newmap[j] == allCount){
                  restvalid2= false;
                  break;
               }
           if (!restvalid2)   
              continue;
              
           int mini2 = min(i,count-taken);
           int outside2 = abs(i - count + taken);
           for (int j = 0-mini2; j < count-mini2-outside2 ;j++)
               newmap[taken-j] |= (1 << (i+j));
           
           bool restvalid = true;
           for (int j = taken+1; j < count; j++)
               if (newmap[j] == allCount){
                  restvalid= false;
                  break;
               }
           if (restvalid)
              sum += recurse(newmap,count,taken+1);
        }   
    }
    return sum;
}

int main(void){
    int count;
    int testcount = 1;
    while(true){
        scanf("%d",&count);
        if (count == 0)
           break;
        int map[15];
        memset(map,0,sizeof(map));
        char temp;
        scanf("%c",&temp);
        for (int i = 0; i < count ;i++){          
            for (int j = 0; j <count; j++){
                scanf("%c",&temp);
                if (temp == '*')
                    map[i] |= (1 << j);
            }
            scanf("%c",&temp);
        }
        
        allCount = (1 << count) -1;
        printf("Case %d: ",testcount);
        cout << recurse(map,count,0) << endl;
        testcount++;
    }  
    return 0;
}
