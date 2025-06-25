// Problem Link: https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/description/?envType=daily-question&envId=2025-06-25

class Solution {
public:
    int bs(auto &nums2,long long c,long long m){
        int n2=nums2.size();
        int l=0,r=n2-1;
        while(l<=r){
            int mid=(l+r)/2;
            if((c>=0 && nums2[mid]*c<=m || c<0 && nums2[mid]*c>m))l=mid+1;
            else r=mid-1;
        }
        if(c>=0)return l;
        return n2-l;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int n1=nums1.size();
        long long l=-1e10,r=1e10;
        while(l<=r){
            long long mid=(l+r)/2;
            long long cnt=0;

            for(int i=0;i<n1;i++){
                cnt+=bs(nums2,nums1[i],mid);
            }
            if(cnt<k)l=mid+1;
            else r=mid-1;
        }
        return l;
    }
};

// Time Complexity : O(N*log(n));
// Space Complexity: O(1);