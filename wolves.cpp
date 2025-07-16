#include <cstdio>
#include <cmath>
#define ll long long

ll k, n, sum = 0;
double accuracy = 1e-6;
ll strength[1000010];

ll calculateWolf(double time) {
    ll sum = 0;
    for (int i = 0; i < n && sum <= k; i++) {
        sum += (ll) ceil((strength[i] * 1.0) / time);
    }
    return sum;
}

int main() {
    while (1) {
        sum = 0;
        if (scanf("%lld %lld", &k, &n) != 2 || (k == 0 && n == 0)) {
            break;
        }

        for (int i = 0; i < n; i++) {
            scanf("%lld", &strength[i]);
            sum += strength[i];
        }

        if (k < n) {
            printf("Impossible\n");
        } else {
            double lo = 0, hi = sum * 1.0 + 1, mid;
            while (hi - lo > accuracy) {
                mid = (lo + hi) / 2.0;
                ll totalWolf = calculateWolf(mid);
                if (totalWolf > k) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
            printf("%.6f\n", hi);
        }
    }
    return 0;
}