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
            console.log(profit)
            maxProfit = Math.max(profit , maxProfit)
        }

        return maxProfit
    }
}
