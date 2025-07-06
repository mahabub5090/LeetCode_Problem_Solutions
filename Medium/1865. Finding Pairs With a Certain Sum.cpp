// Problem Link: https://leetcode.com/problems/finding-pairs-with-a-certain-sum/description/?envType=daily-question&envId=2025-07-06

class FindSumPairs {
public:
    vector<int>nums1,nums2;
    unordered_map<int,int>mp;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1=nums1;
        this->nums2=nums2;
        for(auto &c:nums2)mp[c]++;
    }
    
    void add(int index, int val) {
        mp[nums2[index]]--;
        nums2[index]+=val;
        mp[nums2[index]]++;
    }
    
    int count(int tot) {
        int cnt=0;
        for(auto &c:nums1){
            if(mp.count(tot-c))cnt+=mp[tot-c];
        }
        return cnt;
    }
};

// Time Complexity : O(N) * O(Q) => O(N^2);
// Space Complexity: O(N+M) => O(N);
// N is nums1.size(), M is nums2.size(), Q is maximam call;
// nums1.size()<=1000, nums2.size()<=1e5, Q<=1000;

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */