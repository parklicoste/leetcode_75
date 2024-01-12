/*
Leetcode 75

17. Letter Combinations of a Phone Number
*/

/* ------ Approach 1 ---- */
/* Iteratively*/

class Solution {
public:
    int uniquePaths(int m, int n) {

        double ans = 1;
        for(int i=1; i<m; i++) ans = ans * (n-1+i) / i; // basically counting combinations of m+n-2 C n-1
        return int(ans);
    }
};
/* ------ Approach 1 ---- */
/* Recursively*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        return countPaths(m,n,0,0);
    }
    int countPaths(int m, int n, int i, int j){
            if(i == m-1 && j == n-1) return 1;
            else if(i>= m || j >= n) return 0;
            else{
                return countPaths(m, n, i+1, j) + countPaths(m, n, i, j+1);
            }
        }
};
        