int numWaterBottles(int numBottles, int numExchange) {
    int total = numBottles;
    int rem = 0;
    while(numBottles>=numExchange){
        rem = numBottles%numExchange;
        numBottles /= numExchange;
        total+=numBottles;
        numBottles += rem;
        printf("%d ", numBottles);
    }
    return total;
}