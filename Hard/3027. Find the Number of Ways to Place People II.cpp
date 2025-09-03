// Problem Link: https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/description/?envType=daily-question&envId=2025-09-03

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans=0,n=points.size();

        sort(points.begin(),points.end(),[](auto &a,auto &b){
            return a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]);
        });
        
        for(int i=0;i<n-1;i++){
            auto &a=points[i];
            int minx=a[0]-1,maxx=INT_MAX,miny=INT_MIN,maxy=a[1]+1;

            for(int j=i+1;j<n;j++){
                auto &b=points[j];

                if(b[0]>minx && b[0]<maxx && b[1]>miny && b[1]<maxy){
                    ans++;
                    minx=b[0];
                    miny=b[1];
                }
            }
        }
        return ans;
    }
};

// Time Complexity : O(NlogN) + O(N*N) => O(N^2);
// Space Complexity: O(1);