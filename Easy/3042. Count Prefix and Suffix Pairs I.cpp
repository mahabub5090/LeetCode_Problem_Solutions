// Problem Link: https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/

class Solution {
public:
    int isPrefixAndSuffix(string s,string s2){
        for(int i=0;i<s.size();i++){
            if(s[i]!=s2[i])return 0;
        }
        int j=s.size()-1;
        for(int i=s2.size()-1;i>=0,j>=0;i--){
            if(s[j]!=s2[i])return 0;
            j--;
        }
        return 1;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                ans+=isPrefixAndSuffix(words[i],words[j]);
            }
        }
        return ans;
    }
};

// Time Complexity : O((N^2)*L) => O(N^3);
// Space Complexity: O(1);
// L is the words[i] length here;