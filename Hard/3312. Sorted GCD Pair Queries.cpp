// Problem Link: https://leetcode.com/problems/sorted-gcd-pair-queries/description/?envType=daily-question&envId=2026-07-17

class Solution {
public:
    using ll = long long;

    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx=*max_element(nums.begin(),nums.end());
        vector<ll> cnt(mx+1);
        for(auto &c:nums) cnt[c]++;

        for(int i=1;i<=mx;i++){
            for(int j=i*2;j<=mx;j+=i) cnt[i]+=cnt[j];
        }

        for(int i=1;i<=mx;i++) cnt[i]=(cnt[i]-1)*cnt[i]/2;

        for(int i=mx;i>=1;i--){
            for(int j=i*2;j<=mx;j+=i) cnt[i]-=cnt[j];
        }

        for(int i=1;i<=mx;i++) cnt[i]+=cnt[i-1];

        vector<int> ans;
        for(auto &c:queries){
            c++;
            int val=lower_bound(cnt.begin(),cnt.end(),c)-cnt.begin();
            ans.push_back(val);
        }
        return ans;
    }
};

// Time Complexity : O(N) + O(MlogM) + O(M) + O(MlogM) + O(M) + O(QlogM) => O(N + MlogM + QlogM);
// Space Complexity: O(M) + O(Q) => O(M + Q); 
// M = max(nums[i]), Q = queries.size();