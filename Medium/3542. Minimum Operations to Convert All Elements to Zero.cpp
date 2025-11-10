// Problem Link: https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/description/?envType=daily-question&envId=2025-11-10

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt=0;
        vector<int>vc;
        for(auto &c:nums){
            while(vc.size() && vc.back()>c)vc.pop_back();
            if(c==0)continue;
            if(vc.empty() || vc.back()<c){
                cnt++;
                vc.push_back(c);
            }
        }
        return cnt;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);