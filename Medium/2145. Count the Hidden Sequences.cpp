// Problem Link: https://leetcode.com/problems/count-the-hidden-sequences/description/?envType=daily-question&envId=2025-04-21

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        vector<int>cp=differences;
        long long n=cp.size();
        vector<long long>ans(n+1,0);
        for(long long i=0;i<n;i++){
            ans[i+1]+=ans[i]+cp[i];
        }
        long long diff=0;
        for(long long i=0;i<n+1;i++){
            if(ans[i]<lower)diff=max(diff,lower-ans[i]);
        }
        for(auto &c:ans)c+=diff;
        long long mn=*min_element(ans.begin(),ans.end());
        long long mx=*max_element(ans.begin(),ans.end());

        return max((long long)0,mn-lower+upper-mx+1);
    }
};

// Time Complexity : O(4*N) => O(N);
// Space Complexity: O(2*N) => O(N);