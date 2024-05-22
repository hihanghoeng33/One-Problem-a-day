long long divide(long long dividend, long long divisor) {
    long long res = dividend/divisor;
    if(res<-2147483648){
        res = -2147483648;
    }else if(res>2147483647){
        res = 2147483647;
    }
    return res;
}