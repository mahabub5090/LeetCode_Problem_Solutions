// Problem Link: https://leetcode.com/problems/number-of-unique-xor-triplets-ii/description/?envType=daily-question&envId=2026-07-24

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size(), mx=0; 
        for(auto &c:nums) mx=max(mx,c);
        int maxXorVal=1;
        while(maxXorVal<=mx) maxXorVal<<=1;
        
        vector<int> mayHave(maxXorVal);
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++) mayHave[(nums[i]^nums[j])]++;
        }

        vector<int> have(maxXorVal);
        for(int i=0;i<maxXorVal;i++){
            if(mayHave[i]==0) continue;

            for(auto &c:nums) have[(i^c)]++;
        }

        int ans=0;
        for(int i=0;i<maxXorVal;i++) if(have[i]) ans++;
        return ans;
    }
};

// Time Complexity : O(N) + O(logM) + O(N^2) + O(M*N) + O(M) => O((N^2)+(M*N));
// Space Complexity: O(M) + O(M) => O(M);
// M = maxXorVal (The smallest power of 2 greater than max(nums[i]));