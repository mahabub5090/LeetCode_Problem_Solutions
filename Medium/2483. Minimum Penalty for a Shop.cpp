// Problem Link: https://leetcode.com/problems/minimum-penalty-for-a-shop/description/?envType=daily-question&envId=2025-12-26

class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        int open=count(customers.begin(),customers.end(),'Y'),close=n-open;
        if(open==n)return n;

        int ans=0,mn=open,prev=0;
        for(int i=0;i<n+1;i++){
            int penalty=prev+open;
            
            if(penalty<mn){
                ans=i;
                mn=penalty;
            }

            if(i==n)break;

            prev+=customers[i]=='N';
            open-=customers[i]=='Y';
        }
        return ans;
    }
};

// Time Complexity : O(2*N) => O(N);
// Space Complexity: O(1);