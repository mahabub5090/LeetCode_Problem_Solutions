// Problem Link: https://leetcode.com/problems/rabbits-in-forest/description/?envType=daily-question&envId=2025-04-20

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int>mp;
        for(auto &c:answers)mp[c]++;
        int ans=0;
        for(auto &c:mp){
            double overflow=(c.second*1.00)/(c.first+1);
            overflow=ceil(overflow);
            ans+=overflow*(c.first+1);
        } 
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);