// Problem Link: https://leetcode.com/problems/sum-of-distances/description/?envType=daily-question&envId=2026-04-23

// class Solution {
// public:
//     vector<long long> distance(vector<int>& nums) {
//         int n=nums.size();
//         unordered_map<int,long long>index,cnt,sums;
//         vector<long long>ans(n,0);

//         for(int i=0;i<n;i++){
//             int c=nums[i];
//             if(index.count(c)){
//                 if(sums.count(index[c])==0)sums[i]=i-index[c];
//                 else sums[i]+=(i-index[c])*cnt[c]+sums[index[c]];
//             }
//             index[c]=i;
//             cnt[c]++;
//         }

//         for(auto &c:sums)ans[c.first]+=c.second;
//         index.clear(),cnt.clear(),sums.clear();

//         for(int i=n-1;i>=0;i--){
//             int c=nums[i];
//             if(index.count(c)){
//                 if(sums.count(index[c])==0)sums[i]=index[c]-i;
//                 else sums[i]+=(index[c]-i)*cnt[c]+sums[index[c]];
//             }
//             index[c]=i;
//             cnt[c]++;
//         }

//         for(auto &c:sums)ans[c.first]+=c.second;
//         return ans;
//     }
// };

// // Time Complexity : O(N) + O(N) + O(N) + O(N) => O(N);
// // Space Complexity: O(N+N+N) + O(N) => O(N);

// Way: 2 =>

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)mp[nums[i]].push_back(i);

        vector<long long>ans(n,0);
        for(auto &[val,pos]:mp){
            int n=pos.size();
            long long tt=accumulate(pos.begin(),pos.end(),0ll);
            
            long long prevSums=0;
            for(int i=0;i<pos.size();i++){
                ans[pos[i]]=(1ll(i*pos[i])-prevSums;
                ans[pos[i]]+=tt-(prevSums+(1ll*(n-i)*pos[i]));
                prevSums+=pos[i];
            }
        }
        return ans;
    }
};

// Time Complexity : O(N) + O(2*N) => O(N);
// Space Complexity: O(N) + O(N) => O(N);