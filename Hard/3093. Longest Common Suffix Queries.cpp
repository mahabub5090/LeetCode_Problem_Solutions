// Problem Link: https://leetcode.com/problems/longest-common-suffix-queries/description/?envType=daily-question&envId=2026-05-28

class Solution {
    class TrieNode{
        public:
            int child[26];
            int bestLen,bestIndex;

            TrieNode(){
                fill(begin(child),end(child),-1);
                bestLen=1e9;
                bestIndex=1e9;
            }
    };

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<TrieNode> trie;
        trie.emplace_back();
        
        for(int i=0;i<wordsContainer.size();i++){
            int curr=0, len=wordsContainer[i].size();

            if(len<trie[curr].bestLen || (len==trie[curr].bestLen && i<trie[curr].bestIndex)){
                trie[curr].bestLen=len;
                trie[curr].bestIndex=i;
            }

            for(int j=len-1;j>=0;j--){
                int charIndex=wordsContainer[i][j]-'a';

                if(trie[curr].child[charIndex]==-1){
                    trie[curr].child[charIndex]=trie.size();
                    trie.emplace_back();
                }

                curr=trie[curr].child[charIndex];

                if(len<trie[curr].bestLen || (len==trie[curr].bestLen && i<trie[curr].bestIndex)){
                    trie[curr].bestLen=len;
                    trie[curr].bestIndex=i;
                }
            }
        }


        vector<int> ans;
        ans.reserve(wordsQuery.size());

        for(auto &c:wordsQuery){
            int curr=0, len=c.size();

            for(int j=len-1;j>=0;j--){
                int charIndex=c[j]-'a';
    
                if(trie[curr].child[charIndex]==-1) break;
                curr=trie[curr].child[charIndex];
            }
            ans.push_back(trie[curr].bestIndex);
        }
        return ans;
    }
};

// Time Complexity : O(N*LC) + O(M*LQ) => Roughly, O(N^2);
// Space Complexity: O(26*N*LC) => Roughly, O(N^2);
// N = wordsContainer.size(), M = wordsQuery.size();
// LC = max(wordsContainer[i].size()), LQ = max(wordsQuery[i].size());