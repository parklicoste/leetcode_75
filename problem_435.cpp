/*
Leetcode 75

453. Non-Overlapping Intervals
*/

/* ------ Approach 1 ---- */
/* Sorting + Interval */
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        sort(intervals.begin(), intervals.end());
        int i=0, j=1, n = intervals.size();
        while(j<n){
            int cs = intervals[i][0];
            int ce = intervals[i][1];
            int ns = intervals[j][0];
            int ne = intervals[j][1];

            if(ce<=ns){
                i=j;
                j++;
            }
            else if(ce<=ne){
                j++;
                count++;
            }
            else{
                i=j;
                j++;
                count++;
            }
        }

        return count;
    }
};

/* Sorting + Last Interval */

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        sort(intervals.begin(), intervals.end());
        int i=1, n = intervals.size();
        vector<int> last_interval = intervals[0];
        while(i<n){
            int cs = intervals[i][0]; // current start
            int ce = intervals[i][1]; // current end
            int ls_end = last_interval[1];

            if(ls_end <= cs)last_interval = intervals[i];
        
            else if(ls_end < ce)count++;
            
            else{
                last_interval = intervals[i];
                count++;
            }
            i++;
        }

        return count;
    }
};