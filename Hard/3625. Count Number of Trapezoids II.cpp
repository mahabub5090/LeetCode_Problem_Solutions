// Problem Link: https://leetcode.com/problems/count-number-of-trapezoids-ii/description/?envType=daily-question&envId=2025-12-03

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n=points.size();
        unordered_map<double,vector<double>>mp;
        unordered_map<int,vector<double>>mp2;

        int ans=0;
        for(int i=0;i<n;i++){
            int x=points[i][0],y=points[i][1];
            for(int j=i+1;j<n;j++){
                int x2=points[j][0],y2=points[j][1];
                int dx=x-x2,dy=y-y2;
                double k,b;
                if(x==x2){
                    k=INT_MAX;
                    b=x;
                }
                else{
                    k=(double)(y2-y)/(x2-x);
                    b=(double)(y*dx-x*dy)/dx;
                }

                int mid=(x+x2)*10000+(y+y2);
                mp[k].push_back(b);
                mp2[mid].push_back(k);
            }
        }

        for(auto &[_,c]:mp){
            if(c.size()==1)continue;

            map<double,int>cnt;
            for(auto &cc:c)cnt[cc]++;
            int sum=0;
            for(auto &[_,cc]:cnt){
                ans+=sum*cc;
                sum+=cc;
            }
        }

        for(auto &[_,c]:mp2){
            if(c.size()==1)continue;

            map<double,int>cnt;
            for(auto &cc:c)cnt[cc]++;
            int sum=0;
            for(auto &[_,cc]:cnt){
                ans-=sum*cc;
                sum+=cc;
            }
        }
        return ans;
    }
};

// Time Complexity : O(N^2);
// Space Complexity: O(N^2);