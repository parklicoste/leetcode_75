/*
Leetcode 75

208. Implement Trie (Prefix Tree)
*/


/* ------ Approach 1 ---- */
/* Making Trie Data Structure */ 

class Trie {
public:
    struct TrieNode{
        TrieNode *child[26];
        bool end;
    };

    TrieNode* root;
    TrieNode* makeNode(){
        TrieNode* node = new TrieNode();
        node->end = false;
        for(int i=0; i<26; i++){
            node->child[i] = NULL;
        }
        return node;
    }

    Trie() {
        root = makeNode();
    }
    
    void insert(string word) {
        TrieNode* current = root;
        int i = 0;
        for(char ch: word){
            i = ch - 'a';
            if(current->child[i] == NULL) current->child[i] = makeNode();
            current = current->child[i];
        }
        current->end = true;
    }
    
    bool search(string word) {
        TrieNode* current = root;
        int i = 0;
        for(char ch: word){
            i = ch - 'a';
            if(current->child[i] == NULL) return false;
            current = current->child[i];
        }
        return current->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* current = root;
        int i=0, counter = 0;
        for(char ch: prefix){
            i = ch - 'a';
            counter++;
            if(current->child[i] == NULL) return false;
            current = current->child[i];
        }

        return counter == prefix.length();
    }
};


/* ------ Approach 2 ---- */
/* Iteratively */
class Trie {
public:
    unordered_set<string> hey;
    Trie() {
        
    }
    
    void insert(string word) {
        hey.insert(word);
    }
    
    bool search(string word) {
        return hey.find(word) != hey.end();
    }
    
    bool startsWith(string prefix) {
        bool flag = false;
        int n = prefix.length();
        for(auto s = hey.begin(); s!= hey.end(); s++){
            string x = *s;
            if(n > x.length()) continue;
            else {
                int count = 0;
                for(int i=0; i<n; i++){
                    if (x[i] != prefix[i]) continue;
                    else count++;
                }
                if (count == n){
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        return flag;
    }
};

