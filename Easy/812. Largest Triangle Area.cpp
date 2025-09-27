// Problem Link: https://leetcode.com/problems/largest-triangle-area/?envType=daily-question&envId=2025-09-27

class Solution {
public:
    double area(auto &a,auto &b,auto &c){
        return 0.5*abs((a[0]*b[1]+b[0]*c[1]+c[0]*a[1])-(a[1]*b[0]+b[1]*c[0]+c[1]*a[0]));
    }

    double largestTriangleArea(vector<vector<int>>& points) {
        int n=points.size();
        double ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++) ans=max(ans,area(points[i],points[j],points[k]));
            }
        }
        return ans;
    }
};

// Time Complexity : O(N^3);
// Space Complexity: O(1);