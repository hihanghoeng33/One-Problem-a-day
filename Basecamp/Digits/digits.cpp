#include <stdio.h>
typedef long long LL;
int main(){
    LL a[32], power, n;
    power = 4LL;
    for(int i=2;i<=31;i++){
        a[i-1] = (LL)i*power - 1LL;
        power = power * 2LL;
    }
        scanf("%lld", &n);
        for(int i=1;i<=30;i++){
            if(n<=a[i]){
                printf("%d\n", i+1);
                break;
            }
        }
    return 0;
}
