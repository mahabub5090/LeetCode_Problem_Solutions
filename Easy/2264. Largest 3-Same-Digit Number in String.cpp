// Problem Link: https://leetcode.com/problems/largest-3-same-digit-number-in-string/description/?envType=daily-question&envId=2025-08-14

class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="";
        for(int i=2;i<num.size();i++){
            if(num[i-2]==num[i-1] && num[i-1]==num[i]){
                ans=max(ans,string(3,num[i]));
            }
        }
        return ans;
    }
};

// Time Complexity : O(3*N) => O(N);
// Space Complexity: O(1);