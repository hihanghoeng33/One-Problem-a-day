#include <stdio.h>

int main(){
    int hour, minutes, check = 0, total = 0;
    int test;
    scanf("%d", &test);
    for(int i=0;i<test;i++){
        total=0;
        scanf("%d %d", &hour, &minutes);
        while (hour<24)
        {
            if(minutes<60){
                minutes++;
                total++;
                if(minutes==60){
                    minutes = 0;
                    hour++;
                }
            }
        }
        printf("%d\n", total);
    }
    
    return 0;
}
