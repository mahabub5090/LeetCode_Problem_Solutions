// Problem Link: https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/?envType=daily-question&envId=2024-09-03

class Solution {
public:
    int getLucky(string s, int k) {
        string str="";
        for(auto &c:s)str+=to_string(c-'a'+1);
        int ans=0;
        for(int i=0;i<k;i++){
            ans=0;
            for(auto &c:str)ans+=c-'0';
            str=to_string(ans);
        }
        return ans;
    }
};

// Time Complexity : O(N*N) => O(N);
// Space Complexity: O(1);