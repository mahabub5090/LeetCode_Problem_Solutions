// Problem Link: https://leetcode.com/problems/two-furthest-houses-with-different-colors/description/?envType=daily-question&envId=2026-04-20

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans=0,n=colors.size();
        for(int i=0;i<n-1;i++){
            if(colors[i]!=colors[n-1]){
                ans=max(ans,n-i-1);
                break;
            }
        }
        for(int i=n-1;i>0;i--){
            if(colors[i]!=colors[0]){
                ans=max(ans,i);
                break;
            }
        }
        return ans;
    }
};

// Time Complexity : O(N) + O(N) => O(N);
// Space Complexity: O(1);