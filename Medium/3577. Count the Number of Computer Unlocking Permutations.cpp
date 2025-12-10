// Problem Link: https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/description/?envType=daily-question&envId=2025-12-10

class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n=complexity.size();
        for(int i=1;i<n;i++){
            if(complexity[0]>=complexity[i])return 0;
        }
        
        long long ans=1,mod=1e9+7;
        for(int i=1;i<n;i++){
            ans*=i;
            ans%=mod;
        }
        return ans;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(1);