// Problem Link: https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/description/?envType=daily-question&envId=2024-11-07

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans=0;
        for(int i=0;i<32;i++){
            int cnt=0;
            for(auto &c:candidates){
                if(c & (1<<i))cnt++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};

// Time Complexity : O(32*N) => O(N);
// Space Complexity: O(1);