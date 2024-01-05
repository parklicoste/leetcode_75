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

/* ------ Approach 2 ---- */
/* Backtracking*/
class Solution {
public:
    vector<string> result;
    vector<string> key = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void solve(string& temp, string& digits, int idx){
        if(idx >= digits.length()){
            result.push_back(temp);
            return;
        }
        int x = digits[idx] - '0';
        string s = key[x];

        for(int i=0; i<s.length(); i++){
            temp.push_back(s[i]);
            solve(temp, digits, idx+1);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        string ans;
        solve(ans, digits, 0);
        return result;

    }
};