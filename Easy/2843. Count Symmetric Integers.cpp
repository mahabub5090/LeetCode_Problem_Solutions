// Problem Link: https://leetcode.com/problems/count-symmetric-integers/description/?envType=daily-question&envId=2025-04-11

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;i++){
            string s=to_string(i);
            if(s.size()%2)continue;
            int cnt=0;
            for(int j=0;j<s.size()/2;j++)cnt+=s[j]-'0';
            for(int j=s.size()/2;j<s.size();j++)cnt-=s[j]-'0';
            if(!cnt)ans++;
        }
        return ans;
    }
};

// Time Complexity : O((high-low)*log(high-low)) => O(NlogN);
// Space Complexity: O(1);