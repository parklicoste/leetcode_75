/*
Leetcode 75

1071. Greatest Common Divisor of Strings 

*/

/* ------ Approach 1 ---- */
/* gcd */
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int m = str1.length(), n = str2.length();
        int x  = gcd(m, n);

        for(int i=0, j=0; i<m; i++, j++){
            if(j>= n) j-=n;
            if(str2[j] != str1[i]) return "";
        }
        
        string s = "";
        for(int i=0; i<x; i++){
            s+=str2[i];
        }


        int y = m/s.length();
        string temp = "";
        for(int i=0; i<y; i++){
            temp+=s;
        }

        return temp == str1 ? s : "";


    }
};

/* ------ Approach 2 ---- */
/* gcd */

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

      return str1 + str2 == str2 + str1 ? str2.substr(0, gcd(m,n)) : "";

    }
};
