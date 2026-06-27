// Problem Link: https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/description/?envType=daily-question&envId=2026-06-27

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> mp;
        for(auto &c:nums) mp[c]++;

        int ans=0;
        if(mp.count(1)) ans=mp[1]-(mp[1]%2==0);
        mp.erase(1);

        for(auto &[num,_]:mp){
            int cnt=0;
            long long c=num;
        	while(mp.count(c) && mp[c]>1){
                cnt+=2;
                c*=c;			
            }

        	mp.count(c)?cnt++:cnt--;
        	ans=max(ans,cnt);
        }
    
        return ans;
    }
};

// Time Complexity : O(N) + O(M*log(logv)) => O(Nlog(logV));
// Space Complexity: O(N);
// N = nums.size(), M = total distinct elements in nums, V =  max(nums[i]);