#include <cstdio>
using namespace std;
typedef long long ll;
int n, k;
int a[1001];
ll dp[1001][1001];
int main() {
    while (scanf("%d %d", &n, &k) == 2) {
        if (n == 0 && k == 0)
            break;
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        
        for (int i = 0; i < n; i++)
            for (int j = 1; j <= k; j++)
                dp[i][j] = 0;

        for (int i = 0; i < n; i++)
            dp[i][1] = 1;

        for (int len = 2; len <= k; len++) {
            for (int i = 0; i < n; i++) {
                ll sum = 0;
                for (int prev = 0; prev < i; prev++) {
                    if (a[prev] < a[i])
                        sum += dp[prev][len-1];
                }
                dp[i][len] = sum;
            }
        }

        ll res = 0;
        for (int i = 0; i < n; i++)
            res += dp[i][k];

        printf("%lld\n", res);
    }

    return 0;
}
