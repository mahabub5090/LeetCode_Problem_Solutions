// Problem Link: https://leetcode.com/problems/minimum-pair-removal-to-sort-array-ii/description/?envType=daily-question&envId=2026-01-23

class Solution {
public:
    using ll=long long;

    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();

        vector<ll>vc;
        for(auto &c:nums)vc.push_back(c);

        vector<int>prevIndex(n),nextIndex(n);
        for(int i=0;i<n;i++)prevIndex[i]=i-1,nextIndex[i]=i+1;

        int badCnt=0;
        set<pair<ll,int>>pairSum;

        for(int i=0;i<n-1;i++){
            if(vc[i]>vc[i+1])badCnt++;
            pairSum.insert({vc[i]+vc[i+1],i});
        }

        int ans=0;
        while(badCnt){
            auto it=pairSum.begin();
            int curr=it->second,prev=prevIndex[curr],next=nextIndex[curr];

            int nextOfNext=nextIndex[next];
            pairSum.erase(it);

            if(vc[curr]>vc[next])badCnt--;

            if(prev>=0){
                if(vc[prev]>vc[curr])badCnt--;
                if(vc[prev]>vc[curr]+vc[next])badCnt++;
                pairSum.erase({vc[prev]+vc[curr],prev});
            }

            if(nextOfNext<n){
                if(vc[next]>vc[nextOfNext])badCnt--;
                if(vc[curr]+vc[next]>vc[nextOfNext])badCnt++;
                pairSum.erase({vc[next]+vc[nextOfNext],next});
            }

            vc[curr]=vc[curr]+vc[next];
            nextIndex[curr]=nextOfNext;

            if(nextOfNext<n)prevIndex[nextOfNext]=curr;
            if(prev>=0)pairSum.insert({vc[prev]+vc[curr],prev});
            if(nextOfNext<n)pairSum.insert({vc[curr]+vc[nextOfNext],curr});

            ans++;
        }
        return ans;
    }
};

// Time Complexity : O(3*N) + O(NlogN) => O(NlogN);
// Space Complexity: O(N);