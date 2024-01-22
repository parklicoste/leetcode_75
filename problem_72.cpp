/*
Leetcode 75

72. Edit Distance
*/

/* ------ Approach 1 ---- */
/* Dynamic Programming Matrix*/
class Solution {
public:
    int minDistance(string word1, string word2) {
      int m = word1.length(), i=0;
        int n = word2.length(), j=0;
        // word1 = " " + word1;
        // word2 = " " + word2;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(i=0; i<=m; i++) dp[i][0] = i;
        for(i=0; i<=n; i++) dp[0][i] = i;

        for(i=1; i<=m; i++){
            for(j=1; j<=n; j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 +  min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
        return dp[m][n];

    }

    
};