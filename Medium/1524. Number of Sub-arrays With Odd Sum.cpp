// Porblem Link: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/?envType=daily-question&envId=2025-02-25

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod=1e9+7;
        int n=arr.size();
        int ans=0;
        int i=0;
        int sum=0,even=1,odd=0;
        while(i<n){
            sum+=arr[i++];
            if(sum%2)ans+=even,odd++;
            else ans+=odd,even++;
            ans%=mod;
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);