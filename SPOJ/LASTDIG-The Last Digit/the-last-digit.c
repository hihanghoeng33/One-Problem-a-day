#include <stdio.h>  

int main() {
    int T;
    scanf("%d", &T);
    int a, b, c=1, mod;
    while (T--)
    {
        int total=1;
        scanf("%d %d", &a, &b);
        if(b==0){printf("1\n");continue;}
        mod = b%4;if(mod==0){mod+=4;}
        while(mod>0){total*=a;mod--;}
        printf("%d", total%10);
        printf("\n");
    }
    getchar();
    return 0;
}
