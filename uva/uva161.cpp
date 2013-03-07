#include <stdio.h>

int main(void){
    
    int input[100];
    int count = 0;
    int times = 0;
    while(true){
        int next;
        scanf("%d",&next);
        if (next == 0){
           if (count > 0){
              int time = 100;
              for (int i = 0; i < count; i++)
                  if (input[i]-5 < time)
                     time = input[i]-5;
                  
                  while (time <= 18000){
                     bool found = true;
                     for (int i = 0; i < count; i++){
                         if ((time % (input[i] << 1)) >= input[i]-5){
                            time += (input[i] << 1) - (time % (input[i] << 1));
                            found = false;
                            break;
                         }
                     }
                     if (found){
                        printf("%02d:%02d:%02d\n",time/3600,(time%3600)/60,time%60);
                        break;
                     }
                  }
                  if (time > 18000)
                     printf("Signals fail to synchronise in 5 hours\n");
           }
           
           count = 0;
           times++;           
        } else {
           times = 0;
           input[count] = next;
           count++;
        }
          
        if (times > 3)
           break;         
    }

    return 0;
}
