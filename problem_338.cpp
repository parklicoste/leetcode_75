/*
Leetcode 75

338. COunting Bits
*/

/* ------ Approach 1 ---- */
/* Iteratively*/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<=n; i++){
            
            int temp = i, count = 0;
            while(temp != 0){
                if(temp%2) count++;
                temp=temp/2;
            }
            ans.push_back(count);
        }
        return ans;
    }
};

/* ------ Approach 1 ---- */
/* Bit Manipulation */

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0] = 0;
        for(int i=0; i<=n; i++) ans[i] = ans[i/2] + i%2;
        return ans;
    }
};