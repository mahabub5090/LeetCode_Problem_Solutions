// Problem Link: https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/description/?envType=daily-question&envId=2025-09-02

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int ans=0,n=points.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                auto a=points[i],b=points[j];

                if(i==j || !(a[0]<=b[0] && a[1]>=b[1]))continue;
                // if(i==j || (a[0]>b[0] || a[1]<b[1]))continue; // Same as above;
                if(n==2){
                    ans++;
                    continue;
                }
                   
                int valid=1;
                for(int k=0;k<n;k++){
                    if(k==i || k==j)continue;
                    auto c=points[k];
                    int xContain=c[0]>=a[0] && c[0]<=b[0];
                    int yContain=c[1]<=a[1] && c[1]>=b[1];
                    if(xContain && yContain){
                        valid=0;
                        break;
                    }
                }
                ans+=valid;
            }
        }
        return ans;
    }
};

// Time Complexity : O(N^3);
// Space Complexity: O(1);