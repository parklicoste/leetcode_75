/*
Leetcode 75

452. Minimum Number of Arrows to Burst Balloons
*/

/* ------ Approach 1 ---- */
/* Interval
 */

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int count = 0, i = 0, j = 1, n = points.size();

        while(j<n){
            int cs = points[i][0], ce = points[i][1];
            int ns = points[j][0], ne = points[j][1];

            if(ce < ns){
                count++;
                i=j;
            }
            else if(ce > ne)i = j;
            j++;
        }
        return count+1;

    }
};