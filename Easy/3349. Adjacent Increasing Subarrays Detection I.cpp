// Problem Link: https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/description/?envType=daily-question&envId=2025-10-14

// class Solution {
// public:
//     int sorted(auto &vc){
//         int prev=vc[0];
//         for(int i=1;i<vc.size();i++){
//             if(prev>=vc[i])return 0;
//             prev=vc[i];
//         }
//         return 1;
//     }

//     bool hasIncreasingSubarrays(vector<int>& nums, int k) {
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             vector<int>a,b;
//             for(int j=i;j<i+k && j<n;j++)a.push_back(nums[j]);
//             for(int j=i+k;j<i+(2*k) && j<n;j++)b.push_back(nums[j]);

//             if(a.size()!=k || b.size()!=k)return 0;
//             if(sorted(a) && sorted(b))return 1;
//         }
//         return 0;
//     }
// };

// // Time Compelxity : O(N*K) => O(N^2);
// // Space Compelxity: O(K);

// way: 2 =>

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int ans=0,cnt=1,prev=0,n=nums.size();
        
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1])cnt++;
            else{
                prev=cnt;
                cnt=1;
            }
            ans=max(ans,min(prev,cnt));
            ans=max(ans,cnt/2);
        }
        return ans>=k;
    }
};

// Time Compelxity : O(N);
// Space Compelxity: O(1);

