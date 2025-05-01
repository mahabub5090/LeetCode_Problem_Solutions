// Problem Link: https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/description/?envType=daily-question&envId=2025-05-01

class Solution {
public:
    bool check(int mid,int m,auto &tasks,auto &workers,int pills,int strength){
        multiset<int>ws;
        for(int i=m-mid;i<m;i++){
            ws.insert(workers[i]);
        }
        for(int i=mid-1;i>=0;i--){
            auto it=prev(ws.end());
            if(*it>=tasks[i])ws.erase(it);
            else{
                if(!pills)return 0;
                auto rep=ws.lower_bound(tasks[i]-strength);
                if(rep==ws.end())return 0;
                ws.erase(rep);
                pills--;
            }
        }
        return 1;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n=tasks.size(),m=workers.size();
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        
        int l=1,r=min(m,n),ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,m,tasks,workers,pills,strength))ans=mid,l=mid+1;
            else r=mid-1;
        }
        return ans;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(N);