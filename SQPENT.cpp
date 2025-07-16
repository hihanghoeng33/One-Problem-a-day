#include <cstdio>
using namespace std;
typedef long long ll;

ll result, mod = 3367900313, t, r;
ll pentagon[2501];

int main(){
    scanf("%lld", &t);
    pentagon[1] = 1;
    pentagon[2] = 9801;
    while (t--)
    {
        scanf("%lld", &r);
        for(int i=3; i<=r; i++){
            pentagon[i] = (pentagon[i-1] * 9602 - pentagon[i-2] + 200) % mod;
        }
        printf("%lld\n", pentagon[r]);
    }
    return 0;
}