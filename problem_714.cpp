/*
Leetcode 75

714. Best Time to Buy and Sell Stock with Transaction Fee

/* ------ Approach 1 ---- */
/* Recursive */

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        return calc(prices, 0, prices.size(), true, fee);
    }

    int calc(vector<int>& prices, int curr, int n, bool buy, int fee){
        if(curr >= n) return 0;
        int profit = 0;
        

        if(buy){
            int take =   calc(prices, curr+1, n, false, fee) - prices[curr];
            int not_take =  calc(prices, curr+1, n, true, fee);
            profit  = max(profit, max(take, not_take));
        } 

        else{
            int sell = prices[curr]+ calc(prices, curr+1, n, true, fee) - fee;
            int not_sell = calc(prices, curr+1, n, false, fee);
            profit = max(profit, max(sell, not_sell));

        }
        return t[day][buy] = profit;
        
    }
};

/* ------ Approach 2 ---- */
/* Recursively + Memoization */

class Solution {
public:
    int t[50001][2];
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        memset(t, -1, sizeof(t));
        return solve(prices, n, fee, 0, true);
    }

    int solve(vector<int>& prices, int n, int fee, int day, int buy){
        if(day>=n) return 0;
        int profit = 0;
        
        if(t[day][buy] != -1) return t[day][buy];

        if(buy){
            int taken = solve(prices, n, fee, day+1, false) - prices[day];
            int not_taken = solve(prices, n, fee, day+1, true);

            profit = max({profit, taken, not_taken});
        }
        else{
            int sell =  solve(prices, n, fee, day+1, true) + prices[day] - fee;
            int not_sell = solve(prices, n, fee, day+1, false);

            profit = max({profit, sell, not_sell});
        }

        return t[day][buy] = profit;
    }

    
};

