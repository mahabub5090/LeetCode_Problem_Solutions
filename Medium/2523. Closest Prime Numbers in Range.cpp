// Problem Link: https://leetcode.com/problems/closest-prime-numbers-in-range/description/?envType=daily-question&envId=2025-03-07

class Solution {
public:
    vector<int>get_primes(int l,int r){
        vector<int>primes(r+1,1);
        primes[0]=primes[1]=0;

        for(int i=2;i*i<=r;i++){
            if(!primes[i])continue;
            for(int j=i*i;j<=r;j+=i){
                primes[j]=0;
            }
        }
        vector<int>range;
        for(int i=l;i<=r;i++)if(primes[i])range.push_back(i);
        return range;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>primes=get_primes(left,right);
        if(primes.size()==0)return {-1,-1};
        int l=-1,r=-1,diff=INT_MAX;
        for(int i=0;i<primes.size()-1;i++){
            if(primes[i+1]-primes[i]<diff){
                diff=primes[i+1]-primes[i];
                l=primes[i],r=primes[i+1];
            }
        }
        return {l,r};
    }
};

// Time Complexity : O(R*log(logR)) => O(Nlog(logN));
// Space Complexity: O(R) => O(N);