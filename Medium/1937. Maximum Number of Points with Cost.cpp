// Problem Link: https://leetcode.com/problems/maximum-number-of-points-with-cost/description/

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n=points.size(),m=points[0].size();
        vector<long long>prev,l(m),r(m);
        for(auto &c:points[0])prev.push_back(c);
        int t=0;
        for(auto &c:points){
            if(t++==0)continue;
            l[0]=prev[0],r[m-1]=prev[m-1];
            for(int i=1;i<m;i++)l[i]=max(prev[i],l[i-1]-1);
            for(int i=m-2;i>=0;i--)r[i]=max(prev[i],r[i+1]-1);

            for(int i=0;i<m;i++)prev[i]=c[i]+max(l[i],r[i]);
        }
        return *max_element(prev.begin(),prev.end());
    }
};

// Time Complexity : O(2*N)+O(N*3*M) => O(N*M) => O(N^2);
// Space Complexity: O(3*M) => O(M) => O(N); 
// M is the columns number in matrix;