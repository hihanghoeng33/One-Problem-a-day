#include <cstdio>
#include <algorithm>
using namespace std;

int n, k, l[10001];

int computeBin(int l[], int kecil, int besar, int res) {
    int sum = 0, mid = 0;
    while (kecil <= besar) {
        int mid = (kecil + besar) / 2;
        int sum = 0;
        for(int i = 0; i < n; i++){sum += l[i] / mid;}
        if(sum >= k) {
            res = mid;      
            kecil = mid + 1;
        } else besar = mid - 1; 
    }
    return res;
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &l[i]);
    }
    int kecil = 1, res = 0;
    int besar = *max_element(l, l + n); 
    res = computeBin(l, kecil, besar, res); 
    printf("%d\n", res);
    return 0;
}
