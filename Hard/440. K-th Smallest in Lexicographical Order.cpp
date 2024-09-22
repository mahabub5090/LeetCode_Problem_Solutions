// Problem Link: https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/

class Solution {
public:
    long long count(long long curr,long long n){
        long long cnt=0;
        long long other=curr+1;
        while(curr<=n){
            cnt+=min(other,n+1)-curr;
            curr*=10;
            other*=10;
        }
        return cnt;
    }
    int findKthNumber(int n, int k) {
        long long curr=1,i=1;
        while(i<k){
            long long steps=count(curr,n);
            if(i+steps<=k){
                curr+=1;
                i+=steps;
            }
            else curr*=10,i++;
        }
        return curr;
    }
};

// Time Complexity : O(logN^2);
// Space Complexity: O(1);