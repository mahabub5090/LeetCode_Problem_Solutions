// Problem Link: https://leetcode.com/problems/separate-black-and-white-balls/description/?envType=daily-question&envId=2024-10-15

class Solution {
public:
    long long minimumSteps(string s) {        
        long long ans=0,cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                ans+=i-cnt;
                cnt++;
            }
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);
