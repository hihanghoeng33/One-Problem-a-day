#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a, b, c, check = 0;
    for(int i=0;i<n;i++){
        check = 0;
        scanf("%d %d %d", &a, &b, &c);
        if(a+b>=10 || a+c >= 10 || b+c >= 10){
            check = 1;
        }
        (check == 1) ? printf("YES") : printf("NO");
        printf("\n");
    }
    
    return 0;
}
