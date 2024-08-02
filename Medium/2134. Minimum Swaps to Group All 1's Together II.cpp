// Problem Link: https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int cnt=count(nums.begin(),nums.end(),1);
        int n=nums.size();
        vector<int>vc(n);
        for(int i=0;i<n;i++)
            vc[i]+=(nums[i]==1)+(!i?0:vc[i-1]);
        
        int ans=cnt;
        for(int i=0;i<n;i++){
            if(i+cnt>=n){
            // int ex=cnt-(n-1-i)-1;//=> cnt-n+1;
            ans=min(ans,cnt-(vc[n-1]-vc[i]+vc[cnt-n+i]));
            }
            else ans=min(ans,cnt-(vc[i+cnt]-vc[i]));
        }
        return ans;
    }
};

// Time Complexity : O(3*N) => O(N);
// Space Complexity: O(N);