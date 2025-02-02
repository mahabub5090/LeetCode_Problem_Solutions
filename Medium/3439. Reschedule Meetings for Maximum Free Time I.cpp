// Problem Link: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/description/

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<pair<int,int>>vc;
        for(int i=0;i<n;i++){
            vc.push_back({startTime[i],endTime[i]});
        }
        vector<int>diff;
        if(startTime[0])diff.push_back(startTime[0]);
        for(int i=0;i<n-1;i++){
            diff.push_back(vc[i+1].first-vc[i].second);
        }
        if(eventTime-endTime[n-1])diff.push_back(eventTime-endTime[n-1]);
        
        // for(auto &c:diff)cout<<c<<" ";
        int ans=0,sum=0;
        int i=0,j=0;
        while(j<diff.size()){
            sum+=diff[j];
            j++;
            if(j-i==k+1){
                ans=max(ans,sum);
                sum-=diff[i++];
            }
        }
        ans=max(ans,sum);
        return ans;
    }
};

// Time Complexity : O(3*N) => O(N);
// Space Complexity: O(2*N) => O(N);