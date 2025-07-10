// Problem Link: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/description/
// Problem Link: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/description/?envType=daily-question&envId=2025-07-10

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

// Way: 2 =>

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int ans=0,n=startTime.size();
        int lmax=0;

        for(int i=0;i<n;i++){
            int prev=(i==0?startTime[0]:startTime[i]-endTime[i-1]);
            int next=(i==n-1?eventTime-endTime[i]:startTime[i+1]-endTime[i]);

            int len=endTime[i]-startTime[i];

            int f=lmax>=len;

            ans=max(ans,prev+next+(f?len:0));

            lmax=max(lmax,prev);
        }

        int rmax=0;

        for(int i=n-1;i>=0;i--){
            int prev=(i==n-1?eventTime-endTime[i]:startTime[i+1]-endTime[i]);
            int next=(i==0?startTime[0]:startTime[i]-endTime[i-1]);

            int len=endTime[i]-startTime[i];

            int f=rmax>=len;

            ans=max(ans,prev+next+(f?len:0));

            rmax=max(rmax,prev);
        }

        return ans;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(1);