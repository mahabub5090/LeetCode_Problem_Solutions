// Problem Link: https://leetcode.com/problems/longest-balanced-subarray-ii/description/?envType=daily-question&envId=2026-02-11

class Solution {
public:
    vector<int>mn,mx,lazy;

    void push(int v){
        int val=lazy[v];
        lazy[v]=0;
        if(val==0)return;

        mn[2*v]+=val;
        mx[2*v]+=val;
        lazy[2*v]+=val;

        mn[2*v+1]+=val;
        mx[2*v+1]+=val;
        lazy[2*v+1]+=val;
    }
    void update(int v,int tl,int tr,int l,int r,int add){
        if(l>r)return;
        if(l==tl && r==tr){
            mn[v]+=add;
            mx[v]+=add;
            lazy[v]+=add;
        }
        else{
            push(v);
            int tm=(tl+tr)/2;
            update(2*v,tl,tm,l,min(tm,r),add);
            update(2*v+1,tm+1,tr,max(l,tm+1),r,add);
            mn[v]=min(mn[2*v],mn[2*v+1]);
            mx[v]=max(mx[2*v],mx[2*v+1]);
        }
    }
    int findFirst(int v,int tl,int tr,int l,int r){
        if(l>r || mn[v]>0 || mx[v]<0)return -1;
        if(tl==tr)return tl;
        push(v);
        int tm=(tl+tr)/2;
        int ans=findFirst(2*v,tl,tm,l,min(tm,r));
        if(ans==-1)ans=findFirst(2*v+1,tm+1,tr,max(l,tm+1),r);
        return ans;
    }


    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        mn.assign(4*n+1,0);
        mx.assign(4*n+1,0);
        lazy.assign(4*n+1,0);

        unordered_map<int,int>mp;
        int ans=0;

        for(int i=0;i<n;i++){
            int type=nums[i]%2==0?1:-1;
            int prev=mp.count(nums[i])?mp[nums[i]]:-1;

            update(1,0,n-1,prev+1,i,type);
            mp[nums[i]]=i;

            int firstIndex=findFirst(1,0,n-1,0,i);
            if(firstIndex!=-1)ans=max(ans,i+1-firstIndex);
        }
        return ans;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(N);