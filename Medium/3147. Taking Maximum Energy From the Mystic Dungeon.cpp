// Problem Link: https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/description/

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int ans=INT_MIN,n=energy.size();
        for(int i=n-k;i<n;i++){
            int tt=0;
            for(int j=i;j>=0;j-=k){
                tt+=energy[j];
                ans=max(ans,tt);
            }
        }
        return ans;
    }
};

// Time Complexity : O(k*(N/K)) => O(N);
// Time Complexity : O(1);