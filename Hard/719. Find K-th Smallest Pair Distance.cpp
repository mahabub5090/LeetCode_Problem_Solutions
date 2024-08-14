// Problem Link: https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/?envType=daily-question&envId=2024-08-14

class Solution {
public:
    int countPair(int diff,auto &arr){
        int l=0,r=0,cnt=0;
        while(r!=arr.size()){
            while(arr[r]-arr[l]>diff)l++;
            cnt+=r-l;
            r++;
        }
        return cnt;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums[nums.size()-1];
        while(l<r){
            int mid=(l+r)/2;
            int cnt=countPair(mid,nums);
            if(cnt<k)l=mid+1;
            else r=mid;
        }
        return r;
    }
};

// Time Complexity : O(NlogN+(logM*N)) => O(NlogN); // M = maximum distance in the nums array. 
// Space Complexity: O(1);