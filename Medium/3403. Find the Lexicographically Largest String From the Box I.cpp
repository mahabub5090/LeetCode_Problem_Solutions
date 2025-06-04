// Problem Link: https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/description/?envType=daily-question&envId=2025-06-04

class Solution {
public:
    string answerString(string word, int numFriends) {
        int n=word.size();
        int len=(n-numFriends)+1;
        char cc=word[0];for(auto &c:word)cc=max(cc,c);
        
        if(len==n)return word;

        string ans="";
        for(int i=0;i<n;i++){
            if(word[i]==cc){
                string s="";
                int j=i;
                for(;j<min(i+len,n);j++)s+=word[j];
                ans=max(ans,s);
            }
        }   

        return ans;
    }
};

// Time complexity : O(N^2);
// Space Complexity: O(N^2);