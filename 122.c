#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize) {
    int bef = 0;
    int profit = 0;
    if(pricesSize <= 1)
        return 0;
    bef = prices[0];

    for(int i = 1;i < pricesSize;i++){
        if(bef < prices[i]){
            profit += (prices[i]-bef);
        }
        bef = prices[i];
    }

    return profit;
}

int main(){
    int test[] = {7,1,5,3,6,4};
    printf("%d\r\n",maxProfit(test,6));
    return 0;
}