class Solution {
    /**
     * @param {number[]} prices
     * @return {number}
     */
    maxProfit(prices) {
        let minBuyingPrice = Number.POSITIVE_INFINITY
        let maxProfit = 0;

        for(let i = 0 ; i < prices.length; i ++) {
            minBuyingPrice = Math.min(minBuyingPrice , prices[i])
            let profit = prices[i] - minBuyingPrice;
            maxProfit = Math.max(profit , maxProfit)
        }

        return maxProfit
    }
    // maxProfit(prices) {
    //     let maxProfit = 0;
    //     for(let i = 0 ; i < prices.length; i++) {
    //         let buyingPrice = prices[i];
    //         for(let j = i + 1; j < prices.length; j++) {
    //             let sellingPrice = prices[j];
    //             let profit = sellingPrice - buyingPrice;
    //             maxProfit = Math.max(profit , maxProfit)
    //         }
    //     }

    //     return maxProfit;
    // }

    // maxProfit(prices) {
    //     let maxProfit = 0;
    //     let l = 0 ;
    //     let r = 1;

    //     while(r < prices.length){
    //         if(prices[r] > prices[l]){
    //             let profit = prices[r] - prices[l];
    //             maxProfit = Math.max(profit , maxProfit);
    //         }
    //         else {
    //             l = r;
    //         }

    //         r ++;
    //     }

    //     return maxProfit;
    // }
}
