#include <cstdio>
#include <algorithm>
typedef long long ll;
using namespace std;
 
ll N, t[100001], M, T, besar, kecil, mid, MXT;


ll compute(ll t[], ll kecil, ll besar){
    ll res = besar;
    while(kecil <= besar){
        mid = (kecil + besar) / 2;
        ll sum = 0;
        for(int i = 0; i < N; i++){
            sum += mid / t[i];
            if(sum>= M) break;
        }
        if(sum >= M){
            res = mid;
            besar = mid -1;
        } else kecil = mid + 1;
    }
    return res;
}
 
int main(){
    scanf("%lld", &T);
    while(T--){
        scanf("%lld %lld", &N, &M);
        for(int i = 0; i < N; i++){
            scanf("%lld", &t[i]);
        }
        MXT = *max_element(t, t + N);
        kecil = 1;
        besar = MXT * M;
        ll res = compute(t, kecil, besar);
        printf("%lld\n", res);
    }
    return 0;
}