// Problem Link: https://leetcode.com/problems/destroying-asteroids/description/?envType=daily-question&envId=2026-05-31

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long curr_mass=mass;
        sort(asteroids.begin(),asteroids.end());
        for(auto &c:asteroids){
            if(c>curr_mass) return 0;
            curr_mass+=c;
        }
        return 1;
    }
};

// Time Complexity : O(NlogN) + O(N) => O(NlogN);
// Space Complexity: O(1);