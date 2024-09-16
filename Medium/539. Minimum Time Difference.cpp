// Problem Link: https://leetcode.com/problems/minimum-time-difference/?envType=daily-question&envId=2024-09-16

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>vc;
        int ans=1e9;
        for(auto &c:timePoints){
            vc.push_back((stoi(c.substr(0,2))*60)+stoi(c.substr(3,2)));
        }
        sort(vc.begin(),vc.end());
        for(int i=0;i<vc.size()-1;i++)
            ans=min(ans,min(vc[i+1]-vc[i],1440-vc[i+1]+vc[i]));
        ans=min(ans,min(vc[vc.size()-1]-vc[0],1440-vc[vc.size()-1]+vc[0]));
        return ans;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(N);