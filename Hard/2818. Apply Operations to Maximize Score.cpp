// Problem Link: https://leetcode.com/problems/apply-operations-to-maximize-score/description/?envType=daily-question&envId=2025-03-29

class Solution {
public:
    int mod=1e9+7;

    long long power(long long base,long long expo){
        long long ans=1;
        while(expo>0){
            if(expo%2==1)ans=(ans*base)%mod;        
            base=(base*base)%mod;
            expo/=2;
        }
        return ans;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>primeScore(n);

        for(int i=0;i<n;i++){
            int c=nums[i];
            for(int j=2;j*j<=c;j++){
                if(c%j==0)primeScore[i]++;
                while(c%j==0)c/=j;
            }
            if(c>=2)primeScore[i]++;
        }

        vector<int>nextDom(n,n),prevDom(n,-1);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(st.size() && primeScore[st.top()]<primeScore[i]){
                int top=st.top();st.pop();
                nextDom[top]=i;
            }
            if(st.size())prevDom[i]=st.top();
            st.push(i);
        }

        vector<long long>subarrayCnt(n);
        for(int i=0;i<n;i++)subarrayCnt[i]=(long long)(nextDom[i]-i)*(i-prevDom[i]);

        priority_queue<pair<int,int>>pq;

        for(int i=0;i<n;i++)pq.push({nums[i],i});

        long long ans=1;
        while(k>0){
            auto [c,i]=pq.top();pq.pop();

            long long op=min((long long)k,subarrayCnt[i]);
            ans=(ans*power(c,op))%mod;
            k-=op;
        }
        return ans;
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(N);