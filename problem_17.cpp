/*
Leetcode 75

17. Letter Combinations of a Phone Number
*/

/* ------ Approach 1 ---- */
/* Iteratively*/
class Solution {
public:
    void appendVec(vector<string>& ans, string w){
        vector<string> fin;
        for(char& c: w){
            string st = "";
            if(ans.size() != 0) for(string s: ans) fin.push_back(s+=c);
            else{
                st += c;
                fin.push_back(st);
            }
        }

        ans = fin;
    }
    vector<string> letterCombinations(string digits) {
        vector<string> key = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        
        for(char& ch: digits){
            int x = ch -'0';
            string word = key[x-1];
            appendVec(ans, word);
        }
        return ans;
    }
};