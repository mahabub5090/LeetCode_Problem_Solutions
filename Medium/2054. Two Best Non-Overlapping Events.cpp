// problem link: https://leetcode.com/problems/two-best-non-overlapping-events/description/?envType=daily-question&envId=2024-12-08

// class Solution {
// public:
//     int maxTwoEvents(vector<vector<int>>& events) {
//         int n = events.size();
//         sort(events.begin(),events.end(),[](auto &a, auto &b){
//             return a[0]<b[0];
//         });
        
//         vector<int>suffixMax(n);
//         suffixMax[n-1]=events[n-1][2];
        
//         for (int i=n-2;i>=0;i--) {
//             suffixMax[i]=max(events[i][2],suffixMax[i+1]);
//         }
        
//         int maxSum=0;
        
//         for (int i=0;i<n;i++) {
//             int left=i+1,right=n-1;
//             int nextEventIndex=-1;
            
//             while(left<=right) {
//                 int mid=left+(right-left)/2;
//                 if (events[mid][0]>events[i][1]) {
//                     nextEventIndex=mid;
//                     right=mid-1;
//                 }
//                 else{
//                     left=mid+1;
//                 }
//             }
            
//             if (nextEventIndex!=-1) {
//                 maxSum=max(maxSum,events[i][2]+suffixMax[nextEventIndex]);
//             }
            
//             maxSum=max(maxSum,events[i][2]);
//         }
        
//         return maxSum;
    
//     }
// };

// // Time Complexity : O(NlogN);
// // Space Complexity: O(N);


// Way: 2 =>

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());

        map<int,int>mp;
        for(auto &c:events)mp[c[0]]=max(mp[c[0]],c[2]);

        vector<pair<int,int>>suff;
        for(auto &c:mp)suff.push_back({c.first,c.second});
        sort(suff.begin(),suff.end());

        int m=suff.size();
        for(int i=m-2;i>=0;i--){
            suff[i].second=max(suff[i].second,suff[i+1].second);
        }

        // for(auto &c:suff){
        //     cout<<c.first<<" "<<c.second<<endl;
        // }

        int ans=0;
        for(int i=0;i<n;i++){
            int tt=events[i][2],next=events[i][1];
            
            auto it=upper_bound(suff.begin(),suff.end(),next,[](int val,pair<int,int>&c){return val<c.first;});

            if(it!=suff.end())tt+=it->second;
            ans=max(ans,tt);
        }
        return ans;
    }
};

// Time Complexity : O(2(NlogN) + O(2*N) => O(NlogN);
// Space Complexity: O(2*N) => O(N);