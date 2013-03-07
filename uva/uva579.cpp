#include <stdio.h>

int main(void){
    int hours, minutes;
    while(true){
        scanf("%d:%d", &hours, &minutes);
        if (hours == 0 && minutes == 0)
           break;
        double angle = hours*30 + minutes/2.0 - minutes*6;
        if (angle > 0){
            if (angle > 180)
                printf("%.3lf\n", 360 - angle);
            else
                printf("%.3lf\n", angle);
        }
        else {
            if (angle < -180)     
                printf("%.3lf\n", 360 + angle);
            else
                printf("%.3lf\n", angle* - 1);
        }
    }
    
    return 0;
}
