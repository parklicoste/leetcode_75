/*
Leetcode 75

875. Koko Eating Bananas
*/

class Solution {
public:
    bool check(vector<int>& piles, int m, int h){
        int count = 0;
        
        for(int& x: piles){
            count += x/m;
            if(x%m != 0) count++;
        }
        return count <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1; int r = *max_element(piles.begin(), piles.end());

        while(l < r){
            int mid = l + (r-l)/2;
            if(check(piles, mid, h)) r = mid;
            else l = mid+1;
        }
        return l;

    }
};

//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