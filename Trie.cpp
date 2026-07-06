#include<bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
    bool endOfWord = false;
    vector<TrieNode*> children;

    TrieNode(){
        children.resize(26, nullptr);
    }
};

class Trie {
    public:
    TrieNode* root;
    
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string word){
        TrieNode* curNode = root;
        for(int i=0;i<word.size();i++){
            int idx = word[i] - 'a';
            if(curNode->children[idx] == nullptr){
                curNode->children[idx] = new TrieNode();
            }
            curNode = curNode->children[idx];
        }
        curNode->endOfWord = true;
    }

    bool search(string word){
        TrieNode* curNode = root;
        for(int i=0;i<word.size();i++){
            int idx = word[i] - 'a';
            if(curNode->children[idx] == nullptr){
                return false;
            }
            curNode = curNode->children[idx];
        }
        return curNode->endOfWord;
    }
};


int main(){
    vector<string> words = {"mohit", "mohita", "mohiny"};
    Trie trie;
    for(int i=0;i<words.size();i++){
        trie.insert(words[i]);
    }
    cout<<"Mohit is present? "<<endl;
    cout << (trie.search("mo") ? "Yes" : "No") << endl;
    return 0;
}