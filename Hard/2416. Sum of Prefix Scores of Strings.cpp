// Problem Link: https://leetcode.com/problems/sum-of-prefix-scores-of-strings/submissions/1402060697/?envType=daily-question&envId=2024-09-25

class Trie{
    public:
    int score;
    Trie *child[26];
    Trie(){
        score=0;
        memset(child,0,sizeof(child));
    }
    void add(string &c,int i){
        if(i)score++;
        if(i==c.size())return;
        if(!child[c[i]-'a'])child[c[i]-'a']=new Trie();
        child[c[i]-'a']->add(c,i+1);
    }
    int dfs(string &c,int i){
        if(i==c.size())return score;
        return score+child[c[i]-'a']->dfs(c,i+1);
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie *tie=new Trie();
        for(auto &c:words)tie->add(c,0);
        vector<int>ans;
        for(auto &c:words)ans.push_back(tie->dfs(c,0));
        return ans;
    }
};

// Time Complexity : O(N*L) => O(N^2);
// Space Complexity: O(N*L) => O(N^2);
// L= length of biggest word;