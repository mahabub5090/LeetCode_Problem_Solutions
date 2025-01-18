// Problem Link: https://leetcode.com/contest/biweekly-contest-148/problems/minimum-cost-to-make-arrays-identical/description/

class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        int n=arr.size();
        vector<int>a=arr,b=brr;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(long long i=0;i<n;i++){
            ans+=abs(a[i]-b[i]);
        }
        long long ans2=0;
        for(int i=0;i<n;i++)ans2+=abs(arr[i]-brr[i]);
        return min(ans+k,ans2);
    }
};

// Time Complexity : O(2*NlogN) + O(2*N) => O(NlogN);
// Space Complexity: O(2*N) => O(N);