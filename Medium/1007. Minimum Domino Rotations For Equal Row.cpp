// Problem Link: https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/description/?envType=daily-question&envId=2025-05-03

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans=INT_MAX;
        int cnt=0,n=tops.size();
        for(int i=1;i<=6;i++){
            cnt=0;
            for(int j=0;j<n;j++){
                if(tops[j]==i)continue;
                if(bottoms[j]==i)cnt++;
                else{
                    cnt=INT_MAX;
                    break;
                }
            }
            ans=min(ans,cnt);
        }
        for(int i=1;i<=6;i++){
            cnt=0;
            for(int j=0;j<n;j++){
                if(bottoms[j]==i)continue;
                if(tops[j]==i)cnt++;
                else{
                    cnt=INT_MAX;
                    break;
                }
            }
            ans=min(ans,cnt);
        }
        return ans==INT_MAX?-1:ans;
    }
};

// Time Complexity : O(2*6*N) => O(N);
// Space Complexity: O(1);
