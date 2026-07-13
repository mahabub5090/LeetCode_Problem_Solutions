// Problem Link: https://leetcode.com/problems/sequential-digits/description/?envType=daily-question&envId=2026-07-13

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int minLen=to_string(low).size(), maxLen=to_string(high).size();
        vector<int> ans;
        for(int i=minLen;i<=maxLen;i++){
            for(int j=1;j<=10-i;j++){
                int num=0;
                for(int len=0;len<i;len++){
                    num*=10;
                    num+=j+len;
                }
                if(num>=low && num<=high) ans.push_back(num);
            }
        }
        return ans;
    }
};

// Time Complexity : O(1);
// Space Complexity: O(1);