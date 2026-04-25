// Problem Link: https://leetcode.com/problems/maximize-the-distance-between-points-on-a-square/description/?envType=daily-question&envId=2026-04-25

class Solution {
public:
    int check(int limit, int side, int k, auto &vc){
        for(auto &start:vc){
            long long end=start+4ll*side-limit;
            long long curr=start;

            for(int i=0;i<k-1;i++){
                auto it=lower_bound(vc.begin(),vc.end(),curr+limit);

                if(it==vc.end() || *it>end){
                    curr=-1;
                    break;
                }
                curr=*it;
            }

            if(curr>=0)return 1;
        }
        return 0;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long>vc;
        for(auto &c:points){
            int x=c[0],y=c[1];
            if(x==0)vc.push_back(y);
            else if(y==side)vc.push_back(side+x);
            else if(x==side)vc.push_back(3ll*side-y);
            else vc.push_back(4ll*side-x);
        }
        sort(vc.begin(),vc.end());

        long long l=1,r=side;
        int ans=0;
        while(l<=r){
            long long mid=(l+r)/2;

            if(check(mid,side,k,vc)){
                l=mid+1;
                ans=mid;
            }
            else r=mid-1;
        }
        return ans;
    }
};

// Time Complexity : O(P) + O(PlogP) + O(logS * PlogP) => O(NlogN);
// Space Complexity: O(P) => O(N);
// P = points.size(), s = side;