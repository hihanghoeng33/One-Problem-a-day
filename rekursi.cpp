#include <cstdio>
using namespace std;
int fibs(int t){
    if(t==0) return 0;
    if(t==1) return 1;
    return fibs(t-1) + fibs(t-2);
}

int fac(int t){
    if(t<=1) return 1;
    return t * fac(t-1);
}

int main(){
    int t;
    scanf("%d", &t);
    printf("Fibonacci ke-%d adalah %d\n", t, fibs(t));
    printf("Faktorial dari %d adalah %d\n", t, fac(t));
    return 0;
}