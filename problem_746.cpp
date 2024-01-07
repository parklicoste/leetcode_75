/*
Leetcode 75

746. Min Cost Climbing Stairs
*/

/* ------ Approach 1 ---- */

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(), a, b;
        a = cost[0];
        b = cost[1];


        for(int i=2; i<n; i++){
            int x = min(a,b) + cost[i];   
            a = b;
            b = x;
        } 
        return min(a, b);
    }
        
};

/* ------ Approach 2 ---- */
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for(int i=2; i<n; i++) cost[i] += min(cost[i-1], cost[i-2]);
        return min(cost[n-1], cost[n-2]);
    }
        
};