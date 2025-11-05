// Problem Link: https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii/description/?envType=daily-question&envId=2025-11-05

class Solution {
public:
    vector<int>nums;
    int x=0,k=0;
    map<int,int>mp;
    multiset<pair<int,int>>large,small;
    long long sum=0;

    void balance(){
        while(large.size()<x && small.size()){
            auto it=prev(small.end());
            large.insert(*it);
            sum+=1ll*it->first*it->second;
            small.erase(*it);
        }
        while(large.size()>x){
            auto it=prev(large.end());
            small.insert(*it);
            large.erase(*it);
            sum-=1ll*it->first*it->second;
        }
        while(large.size() && small.size() && *prev(small.end())>*large.begin()) {
                auto it=prev(small.end());
                auto it2=large.begin();
                sum+=(1ll*it->first*it->second)-(1ll*it2->first*it2->second);
                
                large.insert(*it);
                small.erase(*it);
                small.insert(*it2);
                large.erase(*it2);
            }
    }

    void add(int val){
        pair<int,int>old={mp[val],val};
        if(large.find(old)!=large.end()){
            large.erase(large.find(old));
            sum-=1ll*mp[val]*val;
        }
        else if(small.find(old)!=small.end())small.erase(small.find(old));
        mp[val]++;
        small.insert({mp[val],val});

        balance();
    }
    void remove(int val){
        pair<int,int>old={mp[val],val};
        if(large.find(old)!=large.end()){
            large.erase(large.find(old));
            sum-=1ll*mp[val]*val;
        }
        else if(small.find(old)!=small.end())small.erase(small.find(old));

        mp[val]--;
        if(mp[val])small.insert({mp[val],val});
        else mp.erase(val);

        balance();
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<long long>ans;
        this->nums=nums;
        this->x=x;
        this->k=k;

        for(int i=0;i<k;i++)add(nums[i]);
        ans.push_back(sum);

        for(int i=k;i<n;i++){
            remove(nums[i-k]);
            add(nums[i]);
            ans.push_back(sum);
        }
        return ans;
    }
};

// Time Complexity : O(N*logK) => O(NlogN);
// Space Complexity: O(N);