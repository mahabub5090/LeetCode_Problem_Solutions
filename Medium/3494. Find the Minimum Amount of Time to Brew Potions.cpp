// Problem Link: https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/description/?envType=daily-question&envId=2025-10-09

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size();
        vector<long long>time(n,0);
        for(auto &c:mana){
            time[0]+=1ll*c*skill[0];
            for(int i=1;i<n;i++){
                long long curr=1ll*c*skill[i];
                time[i]=max(time[i],time[i-1])+curr;
            }
            for(int i=n-2;i>=0;i--){
                long long curr=1ll*c*skill[i+1];
                time[i]=time[i+1]-curr;
            }
        }
        return time[n-1];
    }
};

// Time Complexity : O(N*M) => O(N^2);
// Space Complexity: O(N);