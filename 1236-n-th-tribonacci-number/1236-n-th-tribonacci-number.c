int tribonacci(int n){
    if(n==0){
        return 0;
    }else if(n==1||n==2){
        return 1;
    }
    long long a=0, b=1, c=1;
    long long i=0;
    for(i=3;i<=n;i++){
        long long sum = a+b+c;
        a=b;
        b=c;
        c=sum;
    }

    return c;
}