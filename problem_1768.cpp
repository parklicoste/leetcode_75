/*
Leetcode 75

1768. Merge Strings Alternately

*/

/* ------ Approach 1 ---- */
/* Merging */

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.length(), n = word2.length(), i, j;
        string x = "";
        for(i=0, j=0; i< m && j < n; i++, j++){
            x += word1[i];
            x += word2[j];
        }
        while(i<m){
            x+= word1[i];
            i++;
        }
        while(j<n){
            x+= word2[j];
            j++;
        } 

        return x;
    }
};
