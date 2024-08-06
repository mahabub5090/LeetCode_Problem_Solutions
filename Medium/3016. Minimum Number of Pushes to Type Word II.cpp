// Problem Link: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/?envType=daily-question&envId=2024-08-06

class Solution {
public:
    int minimumPushes(string word) {
        vector<int>vc(26);
        for(auto &c:word)vc[c-'a']++;
        sort(vc.begin(),vc.end(),greater<int>());
        int ans=0,cnt=0;
        for(auto &c:vc){
            ans+=c*(1+(cnt++/8));
        }
        return ans;   
    }
};

// Time Complexity : O(2*N+NlogN) => O(NlogN);
// Space Complexity: O(N);