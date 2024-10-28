// Problem Link: https://leetcode.com/problems/longest-square-streak-in-an-array/description/?envType=daily-question&envId=2024-10-28

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        set<int>st;for(auto &c:nums)st.insert(c);
        int ans=0;
        for(long long c:st){
            int cnt=0;
            c*=c;
            while(st.find(c)!=st.end()){
                if(c>=INT_MAX)break;
                cnt++;
                c*=c;
            }
            ans=max(ans,cnt);
        }
        return ans?ans+1:-1;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(N);