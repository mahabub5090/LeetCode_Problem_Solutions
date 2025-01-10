// Problem Link: https://leetcode.com/problems/word-subsets/description/?envType=daily-question&envId=2025-01-10

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>vc(26,0);
        for(auto &c:words2){
            vector<int>vc2(26,0);
            for(auto &cc:c){
                vc2[cc-'a']++;
            }
            for(int i=0;i<26;i++)vc[i]=max(vc[i],vc2[i]);
        }
        vector<string>ans;
        for(auto &c:words1){
            vector<int>cmp(26,0);
            for(auto &cc:c)cmp[cc-'a']++;
            int f=1;
            for(int i=0;i<26;i++){
                if(vc[i]>cmp[i]){
                    f=0;break;
                }
            }
            if(f)ans.push_back(c);
        }
        return ans;
    }
};

// Time Complexity : O(N*max(M+26)) => O(N*max(10,26)) => O(N*26) => O(N);
// Space Complexity: O(N);
// M is words1[i].length and words2[i] here, Which is maximam <=10;