// Problem Link: https://leetcode.com/problems/alternating-groups-ii/description/?envType=daily-question&envId=2025-03-09

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        int last=colors[0],cnt=0,ans=0;
        for(int i=1;i<n+k;i++){
            int index=i%n; 
            if(colors[index]==last){
                cnt=1;
                last=colors[index];
                continue;
            }
            last=colors[index];
            cnt++;
            if(cnt>=k)ans++;
        }
        return ans;
    }
};

// Time Complexity : O(N+K) => O(N);
// Space Complexity: O(1);