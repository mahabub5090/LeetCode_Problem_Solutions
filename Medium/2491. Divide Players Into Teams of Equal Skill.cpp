// Problem Link: https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/?envType=daily-question&envId=2024-10-04

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.rbegin(),skill.rend());
        int n=skill.size(),sum=skill[0]+skill[n-1];
        for(int i=1;i<n-1;i++){
            if(skill[i]+skill[n-1-i]!=sum)return -1;
        }
        long long ans=0;
        for(int i=0;i<n/2;i++)ans+=skill[i]*skill[n-1-i];
        return ans;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(1);