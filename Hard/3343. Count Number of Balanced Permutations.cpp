// Problem Link: https://leetcode.com/problems/count-number-of-balanced-permutations/description/?envType=daily-question&envId=2025-05-09

class Solution {
public:
    int countBalancedPermutations(string num) {
        int tt=0,n=num.size(),mod=1e9+7;
        vector<int>cnt(10);
        for(auto &c:num)cnt[c-'0']++,tt+=c-'0';
        
        if(tt%2)return 0;

        int target=tt/2;
        int maxOdd=(n+1)/2;
        vector<vector<long long>>combo(maxOdd+1,vector<long long>(maxOdd+1)),balanced(target+1,vector<long long>(maxOdd+1));

        for(int i=0;i<=maxOdd;i++){
            combo[i][i]=combo[i][0]=1;
            for(int j=1;j<i;j++){
                combo[i][j]=(combo[i-1][j]+combo[i-1][j-1])%mod;
            }
        }

        balanced[0][0]=1;
        int psum=0,sum=0;
        for(int i=0;i<=9;i++){
            psum+=cnt[i];
            sum+=i*cnt[i];
            for(int oddCnt=min(psum,maxOdd);oddCnt>=max(0,psum-(n-maxOdd));oddCnt--){
                int evenCnt=psum-oddCnt;
                for(int curr=min(sum,target);curr>=max(0,sum-target);curr--){
                    long long ans=0;
                    for(int j=max(0,cnt[i]-evenCnt);j<=min(cnt[i],oddCnt) && i*j<=curr;j++){
                        long long ways=(combo[oddCnt][j]*combo[evenCnt][cnt[i]-j])%mod;
                        ans+=(ways*(balanced[curr-i*j][oddCnt-j]%mod))%mod;
                        ans%=mod;
                        balanced[curr][oddCnt]=ans;
                    };
                }
            }
        }
        return balanced[target][maxOdd];
    }
};

// Time Complexity : O(N^3);
// Space Complexity: O(N^2);