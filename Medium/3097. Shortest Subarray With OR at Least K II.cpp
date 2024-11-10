// Problem Link: https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/description/?envType=daily-question&envId=2024-11-10

class Solution {
public:
    void addNum(int num,auto &bits){
        for(int i=0;i<32;i++){
            if((num>>i)&1){
                bits[i]++;
            }
        }
    }
    void deleteNum(int num,auto &bits){
        for(int i=0;i<32;i++){
            if((num>>i)&1){
                bits[i]--;
            }
        }
    }
    int getIntVal(auto &bits){
        int ans=0;
        for(int i=0;i<32;i++){
            if(bits[i]>0)ans|=(1<<i);
        }
        return ans;
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if(k==0)return 1;
        vector<int>bits(32,0);
        int i=0,j=0,ans=nums.size()+1;
        int curr=0;
        while(i<nums.size()){
            if(j<nums.size() && curr<k){
                addNum(nums[j],bits);
                j++;
            }else{
                deleteNum(nums[i],bits);
                i++;
            }
            curr=getIntVal(bits);
            if(curr>=k)ans=min(ans,j-i);
        }
        return ans==nums.size()+1?-1:ans;
    }
};

// Time Complexity : O(32*N) => O(N);
// Space Complexity: O(1);