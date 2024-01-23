/*
Leetcode 75

17. Letter Combinations of a Phone Number
*/

/* ------ Approach 1 ---- */
/* Bruteforce */
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        sort(products.begin(), products.end());
        
        string st = "";
        for(int i=0; i<searchWord.length(); i++){
            st+=searchWord[i];
            vector<string> block;

            for(string& s: products){
                if(s.substr(0, i+1) == st && block.size() < 3) block.push_back(s);
                
            }
            ans.push_back(block);
        }
        return ans;
    }
};

/* ------ Approach 2 ---- */
/* Binary search, lower bound */
class Solution {
public:
   
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        int n = products.size();
        sort(products.begin(), products.end());

        string st = "";
        int index = 0;

        for(int i=0; i<searchWord.length(); i++){
            st+=searchWord[i];
            vector<string> block;

            int start = lower_bound(products.begin()+index, end(products), st) - begin(products);

            for(int j=start; j < min(start+3, n); j++){
                if(products[j].find(st) == 0) block.push_back(products[j]);
                // find returns the starting Index where it matches
            }
            ans.push_back(block);
            index = start;
        }
        return ans;
    }
};

