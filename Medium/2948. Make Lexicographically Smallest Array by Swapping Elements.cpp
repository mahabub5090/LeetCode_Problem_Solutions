// Problem Link: https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/?envType=daily-question&envId=2025-01-25
// Problem Link: https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/?envType=daily-question&envId=2026-08-29


// class Solution {
// public:
//     void assignValues(auto &val,auto &id,auto &ans){
//         sort(id.begin(),id.end());
//         sort(val.rbegin(),val.rend());
//         for(auto &i:id){
//             ans[i]=val.back();
//             val.pop_back();
//         } 
//         id.clear();
//     }
//     vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
//         int n=nums.size();
//         vector<pair<int,int>>vc;
//         for(int i=0;i<n;i++){
//             vc.push_back({nums[i],i});
//         }
//         sort(vc.begin(),vc.end());
//         vector<int>ans(n,0);
//         vector<int>val,id;
//         for(int i=0;i<n-1;i++){
//             if(vc[i+1].first-vc[i].first<=limit){
//                 val.push_back(vc[i].first);
//                 id.push_back(vc[i].second);
//             }
//             else {
//                 val.push_back(vc[i].first);
//                 id.push_back(vc[i].second);

//                 assignValues(val,id,ans);
//             }
//         }
//         if(id.size()){
//             val.push_back(vc[n-1].first);
//             id.push_back(vc[n-1].second);

//             assignValues(val,id,ans);
//         }
//         for(int i=0;i<n;i++){
//             if(ans[i]==0)ans[i]=nums[i];
//         }
//         return ans;
//     }
// };

// // Time Complexity : O(3*N) + O(NlogN) => O(NlogN); 
// // Space Complexity: O(4*N) => O(N);


// Way: 2 =>

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();

        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++) temp.push_back({nums[i],i});
        temp.push_back({INT_MAX,INT_MAX});
        sort(temp.begin(),temp.end());

        vector<int> ans(n), curr;
        for(int i=0;i<n;i++){
            curr.push_back(temp[i].second);
            if(temp[i+1].first-temp[i].first>limit){
                vector<int> paired;
                for(auto &c:curr) paired.push_back(nums[c]);
                sort(curr.begin(),curr.end());
                sort(paired.begin(),paired.end());
                for(int i=0;i<curr.size();i++){
                    ans[curr[i]]=paired[i];
                }
                curr.clear();
            }
        }
        return ans;
    }
};

// Time Complexity : O(N) + O(NlogN) + O(NlogN) => O(NlogN);
// Space Complexity: O(N) + O(N) + O(N) => O(N);