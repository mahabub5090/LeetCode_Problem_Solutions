// Problem Link: https://leetcode.com/problems/maximize-active-section-with-trade-ii/description/?envType=daily-question&envId=2026-07-22

class Solution {
public:
    class SparseTable{
    public:
        vector<vector<int>> st;

        SparseTable(const vector<int> &sum){
            st.push_back(sum);
            int i=1, n=st[0].size();

            while(2*i<=n+1){
                auto &prev=st.back();
                vector<int> curr;
                for(int j=0;j<n-i*2+1;j++){
                    curr.push_back(max(prev[j],prev[j+i]));
                }
                st.push_back(curr);
                i<<=1;
            }
        }

        int query(int s, int e){
            if(s>e) return 0;

            int len=e-s+1, log=0;
            while((1<<(log+1))<=len) log++;
            return max(st[log][s],st[log][e-(1<<log)+1]);
        }
    };


    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n=s.size(), cnt=count(s.begin(),s.end(),'1');

        vector<int> zeroBlocks, leftBlock, rightBlock;
        int i=0;
        while(i<n){
            int start=i;
            while(i<n && s[i]==s[start]) i++;

            if(s[start]=='0'){
                zeroBlocks.push_back(i-start);
                leftBlock.push_back(start);
                rightBlock.push_back(i-1);
            }
        }

        int m=zeroBlocks.size();
        if(m<2) return vector<int> (queries.size(),cnt);

        vector<int> tempSum(m-1);
        for(int i=0;i<m-1;i++) tempSum[i]=zeroBlocks[i]+zeroBlocks[i+1];

        SparseTable sp(tempSum);
        vector<int> ans;

        for(auto &c:queries){
            int l=c[0], r=c[1];
            int i=lower_bound(rightBlock.begin(),rightBlock.end(),l)-rightBlock.begin();
            int j=upper_bound(leftBlock.begin(),leftBlock.end(),r)-leftBlock.begin()-1;

            if(i>m-1 || j<0 || i>=j){
                ans.push_back(cnt);
                continue;
            }

            int firstLen=rightBlock[i]-max(leftBlock[i],l)+1;
            int lastLen=min(rightBlock[j],r)-leftBlock[j]+1;

            if(i+1==j){
                int extra=firstLen+lastLen;
                ans.push_back(cnt+extra);
                continue;
            }

            int val=firstLen+zeroBlocks[i+1];
            int val2=zeroBlocks[j-1]+lastLen;
            int val3=sp.query(i+1,j-2);

            int extra=max({val,val2,val3});
            ans.push_back(cnt+extra);
        }
        return ans;
    }
};

// Time Complexity : O(N) + O(N) + O(M) + O(MlogM) + O(QlogM) => O(N + MlogM + QlogM);
// Space Complexity: O(M) + O(MlogM) + O(Q) => O(MlogM + Q);
// N = s.size(), Q = queries.size() and M = number of continuos blocks of '0' in s;