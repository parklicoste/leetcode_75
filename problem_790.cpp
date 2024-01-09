/*
Leetcode 75

17. Letter Combinations of a Phone Number
*/

/* ------ Approach 1 ---- */
/* Bottom Down*/
class Solution {
public:
    int M = 1000000007;
    int numTilings(int n) {
        if(n==1 || n==2) return n;
        vector<int> tilings(n+1,0);

        tilings[1] = 1;
        tilings[2] = 2;
        tilings[3] = 5;

        for(int i=4; i<=n; i++){
            tilings[i] = ((2*tilings[i-1] % M) + (tilings[i-3] % M) )%M; 
        }
        return tilings[n];

    }
};

/* ------ Approach 2 ---- */
/* Recursive*/
class Solution {
public:
    int M = 1000000007;
    int numTilings(int n) {
        if(n==1 || n==2) return n;
        else if (n==3) return 5;
        else return ((2*numTilings(n-1) % M) + (numTilings(n-3) % M) )%M; 

    }
};