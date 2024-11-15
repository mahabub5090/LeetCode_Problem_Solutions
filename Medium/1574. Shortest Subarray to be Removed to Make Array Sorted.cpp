// Problem Link: https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/submissions/1453614641/?envType=daily-question&envId=2024-11-15

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        if(is_sorted(arr.begin(),arr.end()))return 0;
        int n=arr.size(),l=0,r=n-1;
        while(l+1<n && arr[l]<=arr[l+1])l++;
        while(r>0 && arr[r]>=arr[r-1])r--;
        int ans=min(n-l-1,r);
        for(int i=0;i<=l;i++){
            int j=lower_bound(arr.begin()+r,arr.end(),arr[i])-arr.begin();
            if(j<n)ans=min(ans,j-i-1);
        }
        return ans;
    }
};

// Time Complexity : O(N) + O(N) + O(N*logN) => O(NlogN);
// Space Complexity: O(1);

// There was a better solution of this problem which time complexity is O(N) and space complexity is O(1), but i can't come up with this solution, you can check that solution in youtube.