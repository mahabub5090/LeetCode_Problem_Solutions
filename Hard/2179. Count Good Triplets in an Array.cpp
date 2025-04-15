// Problem Link: https://leetcode.com/problems/count-good-triplets-in-an-array/description/?envType=daily-question&envId=2025-04-15

class FenwickTree{
    public:
    vector<int>tree;

    FenwickTree(int n){
        tree.resize(n+1,0);
    }
    void update(int i,int d){
        i++;
        while(i<tree.size())tree[i]+=d,i+=i&-i;
    }
    int query(int i){
        i++;
        int ans=0;
        while(i>0)ans+=tree[i],i-=i&-i;
        return ans;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>pos2(n),mp(n);
        for(int i=0;i<n;i++)pos2[nums2[i]]=i;
        for(int i=0;i<n;i++)mp[pos2[nums1[i]]]=i;

        FenwickTree tree(n);

        long long ans=0;
        for(int val=0;val<n;val++){
            int pos=mp[val];
            int left=tree.query(pos);
            tree.update(pos,1);
            int right=(n-1-pos)-(val-left);
            ans+=(long long)left*right;
        }
        return ans;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(N);