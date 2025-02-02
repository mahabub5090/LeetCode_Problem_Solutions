// Problem Link: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/description/

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<pair<int,int>>vc;
        for(int i=0;i<n;i++){
            vc.push_back({startTime[i],endTime[i]});
        }
        vector<int>diff;
        diff.push_back(startTime[0]);
        for(int i=0;i<n-1;i++){
            diff.push_back(vc[i+1].first-vc[i].second);
        }
        diff.push_back(eventTime-endTime[n-1]);

        // for(auto &c:diff)cout<<c<<" ";
        priority_queue<int>pq;
        for(auto &c:diff)pq.push(c);
        
        int ans=0;
        cout<<endl;
        for(int i=0;i<n;i++){
            int time=endTime[i]-startTime[i];
            int f=0;
            vector<int>temp;
            int d=0,d2=0;
            while(pq.size() && time<=pq.top()){
                int c=pq.top();pq.pop();
                temp.push_back(c);
                // cout<<c<<" ";
                if((c==diff[i] && d==0) || (c==diff[i+1] && d2==0)){
                    if(c==diff[i] && d==0)d++;
                    else d2++;
                }
                else {
                    f=1;
                    break;
                }
            }
            // cout<<" "<<f<<endl;
            ans=max(ans,diff[i]+diff[i+1]+(f?time:0));
            for(auto &c:temp)pq.push(c);
        }
        return ans;
    }
};

// Time Complexity : O(2*N) + O(2*NlogN) => O(NlogN);
// Space Complexity: O(4*N) => O(N);