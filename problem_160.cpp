/*
Leetcode 75

162. Find Peak Element
*/

/* ------ Approach 1 ---- */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int r, l, n, m;
        n = nums.size();
        l=0, r=n-1;

        if (r==0) return r;
        
        vector<pair<int, int>> peak(n);
        for(int i=0; i<n; i++) peak[i] = {nums[i], i};
        
        sort(peak.begin(), peak.end());
    
        return checker(nums, peak, r, l);
    }
    int checker(vector<int>& nums, vector<pair<int, int>>& peak, int r, int l){
        int n = nums.size();
        while(l<=r){
            int m = l + (r-l)/2;
            int val = peak[m].first;
            int idx = peak[m].second;
            if((idx == 0 && val > nums[idx+1]) || (idx == n-1 && val > nums[idx-1])) return idx;
            else if(idx > 0 && idx < n && val > nums[idx-1] && val > nums[idx+1]) return idx;

            else{
                int x = checker(nums, peak, r, m+1);
                int y = checker(nums, peak, m-1, l);

                return (x == -1 || x == nums.size()) ? y : x;
            }
        }
        return -1;
    }
};

/* -------------- Approach 2 -----------*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> peak(n);

        for(int i=0; i<n; i++) peak[i] = {nums[i], i};
        
        sort(peak.begin(), peak.end());
    
        return peak[n-1].second; // since its the largest element and out of bounds index is considered less
    }
};
