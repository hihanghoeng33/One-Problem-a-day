#include <stdio.h>
#include <math.h>

typedef long long ll;

ll f(ll n){
    if(n<=1){
        return 1;
    }
    return n*f(n-1);
}

int main(){
    ll N, a = 1;
    scanf("%lld", &N);
    for(ll i=1;i<N;i++){
        a=2*a + i-1;
    }
    ll res = f(N) + a;
    printf("%lld", res);
    return 0;
}
