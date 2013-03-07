#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;


int main(void){
    
    int testcount;
    scanf("%d",&testcount);
    for (int test = 0; test < testcount; test++){
        if (test != 0)
           printf("\n");
        long long input;
        cin >> input;
        long long i = 1;
        long long cur = input;
        long long max = 999999999;
        max *= 1000;

        
        while (cur < max){
              
              bool check[10];
              memset(check,false,sizeof(check));
              bool valid = true;
              while(cur > 0){
                  int curNum = cur % 10;
                  if (check[curNum]){
                      valid = false;
                      break;
                  } else
                    check[curNum] = true;
                  cur /= 10;
              }
              
              bool check2[10];
              memset(check2,false,sizeof(check2));
              int i2 = i;
              while(i2 > 0){
                  int i2Num = i2 % 10;
                  if (check2[i2Num]){
                      valid = false;
                      break;
                  } else
                    check2[i2Num] = true;
                  i2 /= 10;
              }
              
              if (valid)
                 cout << i*input << " / " << i << " = " << input << endl;
              i++;
              cur = input * i;
        }
        
    }
    return 0;
}
