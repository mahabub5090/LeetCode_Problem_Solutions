// Problem Link: https://leetcode.com/problems/zero-array-transformation-i/description/?envType=daily-question&envId=2025-05-20

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>diff(n+1,0);
        for(auto &c:queries){
            diff[c[0]]++;
            diff[c[1]+1]--;
        }
        vector<int>opCnt;
        int cnt=0;
        for(auto &c:diff){
            cnt+=c;
            opCnt.push_back(cnt);
        }
        for(int i=0;i<n;i++){
            if(opCnt[i]<nums[i])return 0;
        }
        return 1;
    }
};

// Time Complexity : O(N+Q) => O(N);
// Space Complexity: O(N);