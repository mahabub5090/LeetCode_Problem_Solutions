// Problem Link: https://leetcode.com/problems/prime-subtraction-operation/submissions/1449644423/?envType=daily-question&envId=2024-11-11

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        vector<bool>primes(mx+1,1);
        primes[0]=primes[1]=0;
        for(int i=2;i*i<=mx;i++){
            if(primes[i]){
                for(int j=i*i;j<=mx;j+=i){
                    primes[j]=0;
                }
            }
        }
        map<int,int>mp;
        for(int i=2;i<=mx;i++){
            if(primes[i])mp[i]=i;
            else mp[i]=mp[i-1];
        }
        int prev=0;
        for(int i=0;i<nums.size();i++){
            nums[i]-=mp[nums[i]-prev-1];
            prev=nums[i];
        }
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>=nums[i+1])return 0;
        }
        return 1;
    }
};

// Time Complxeity : O(N) + O(Mlog(logM)) + O(N) + O(M) + O(N) => O(Mlog(logN) + M);
// Space Complexity: O(M); 
// M is the maximam number in the given nums array.