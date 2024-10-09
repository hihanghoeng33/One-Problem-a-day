#include <cstdio>
#include <cmath>
typedef long long ll;

ll read(){
    ll value = 0; 
    bool ne = 0;
    char c = getchar();
    while(c == ' ' || c == '\n') c = getchar();
    if(c == '-') { ne = 1; c = getchar(); }
    while(c >= '0' && c <= '9'){
        value = (value << 3) + (value << 1) + c - '0'; 
        c = getchar();
    }
    if(ne) value *= -1;
    return value;
}

int sumofFactors(int n) 
{ 
	int temp = n;
	int res = 1; 
	for (int i = 2; i <= sqrt(n); i++) 
	{ 

		
		int curr_sum = 1; 
		int curr_term = 1; 
		while (n % i == 0) { 

			n = n / i; 

			curr_term *= i; 
			curr_sum += curr_term; 
		} 

		res *= curr_sum; 
	} 


	if (n >= 2) 
		res *= (1 + n); 

	return res-temp; 
} 


int main() {
    ll M = read(), N = read();

    bool found = false;
    for (ll i = M; i <= N; i++) {
        ll j = sumofFactors(i);  
        if (j > i && j <= N && sumofFactors(j) == i) {  
            printf("%d %d\n", i, j);
            found = true;
        }
    }

    if (!found) {
        printf("Absent\n");
    }
    
    return 0;
}
