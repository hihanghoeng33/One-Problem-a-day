int maxProfit(int* prices, int pricesSize) {
    int profit = 0, i=0, buy=prices[0];
    for(i=1;i<pricesSize;i++){
        if(prices[i]<buy){
            buy = prices[i];
        }else if(prices[i]-buy>profit){
            profit = prices[i]-buy;
        }
    }
    return (profit<0) ? 0 : profit;
}