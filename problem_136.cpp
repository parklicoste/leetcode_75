/*
Leetcode 75

136. Single Number
*/

/* ------ Approach 1 ---- */
/* Bit Manipulation */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int x: nums) ans^=x;
        return ans;
    }
};
