/*
Leetcode 75

739. Daily Temperatures
*/

/* ------ Approach 1 ---- */
/* Monotonic Stack */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> box;
        int n=temperatures.size();
        vector<int> ans(n);

        for(int i=n-1; i>=0; i--){
            while(!box.empty() && temperatures[i] >= temperatures[box.top()]) box.pop();
            if(box.empty()) ans[i] = 0;
            else ans[i] = box.top() - i;

            box.push(i);
        }
        return ans;
    }
};
