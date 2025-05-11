// Problem Link: https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/description/?envType=daily-question&envId=2025-05-10

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long cnt=0,cnt2=0,sum=0,sum2=0;
        for(auto &c:nums1)cnt+=c==0,sum+=max(c,1);
        for(auto &c:nums2)cnt2+=c==0,sum2+=max(c,1);
        
        if(cnt && cnt2)return max(sum,sum2);
        if(cnt==0 && cnt2==cnt)return sum==sum2?sum:-1;
        
        if(cnt==0){
            if(cnt2 && sum2<=sum)return sum;
            return -1;
        }
        if(cnt2==0){
            if(cnt && sum<=sum2)return sum2;
            return -1;
        }
        return -1;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(1);