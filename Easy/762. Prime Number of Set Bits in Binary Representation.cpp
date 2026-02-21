// Problem Link: https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/?envType=daily-question&envId=2026-02-21

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        vector<int>isPrime(32,1);
        isPrime[0]=isPrime[1]=0;

        int cnt=0;
        for(int i=2;i*i<32;i++){
            cnt++;
            if(isPrime[i]==0)continue;
            for(int j=i*i;j<32;j+=i){
                isPrime[j]=0;
                cnt++;
            }
        }
        // cout<<cnt<<endl;

        int ans=0;
        for(int i=left;i<=right;i++){
            int cnt=__builtin_popcount(i);
            ans+=isPrime[cnt];
        }
        return ans;
    }
};

// Time Complexity : O(28) + O(r-l) => O(N);
// Space Complexity: O(32) => O(1);
// l=left, r=right;