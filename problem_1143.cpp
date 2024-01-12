/*
Leetcode 75

1143. Longest Common Subsequence
*/

/* ------ Approach 1 ---- */
/* Iteratively */

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), i=0;
        int n = text2.length(), j=0;
        text1 = " " + text1;
        text2 = " " + text2;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(text1[i] == text2[j]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};

/* ------ Approach 2 ---- */
/* Recursively */
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
    
        return findit(text1, text2, 0, 0);
    
    }

    int findit(string t1, string t2, int i, int j){
        if(i == t1.length() || j== t2.length()) return 0;
        else if(t1[i] == t2[j]) return 1 + findit(t1, t2, i+1, j+1);
        else return max(findit(t1, t2, i+1, j), findit(t1, t2, i, j+1));
    }
};
