#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
ll a, bil, n;

int main(){
    scanf("%lld", &n);
    bil = 2ll*ceil((double)(n+sqrt(6.0*n))/2)-n;
    a=(3ll*n+bil)/2ll;
    printf("%lld\n", a);
    return 0;
}
