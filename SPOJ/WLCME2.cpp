// SPOJ problem DIVSUM 
#include <cstdio>
#include <cmath>
using namespace std;

int t, n;
// solution 1
int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        if(n==1) {printf("0\n"); continue;}
        int ans = 1;
        for(int i = 1; i <= sqrt(n); i++){
            if(n%i==0) {
                ans += i;
                if(i != n/i && n/i!=n) ans += n/i;
            }
        }
        printf("%d\n", ans-1);
    }   
    return 0;
}

