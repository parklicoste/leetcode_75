/*
Leetcode 75

216. Combination Sum III
*/

/* ------ Approach 1 ---- */

class Solution {
public:
    vector<vector<int>> result;

    void make_combination(int start, int n, int k, vector<int>& temp){
        if(k == 0 && n==0){
            result.push_back(temp);
            return;
        }
        for(int i=start; i<=9; i++){
            temp.push_back(i);
            make_combination(i+1, n-i, k-1, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        make_combination(1, n, k, temp);
        return result;

    }

};