// Problem Link: https://leetcode.com/problems/fruits-into-baskets-iii/description/?envType=daily-question&envId=2025-08-06

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans=0,n=fruits.size(),m=sqrt(n);
        int block=(n+m-1)/m;
        vector<int>maxBlock(block);

        for(int i=0;i<n;i++)maxBlock[i/m]=max(maxBlock[i/m],baskets[i]);

        for(auto &c:fruits){
            int flag=1;
            for(int i=0;i<block;i++){
                if(maxBlock[i]<c)continue;
                int taken=0;
                maxBlock[i]=0;
                for(int j=0;j<m;j++){
                    int pos=i*m+j;
                    if(pos<n && baskets[pos]>=c && taken==0)baskets[pos]=0,taken++;
                    if(pos<n)maxBlock[i]=max(maxBlock[i],baskets[pos]);
                }
                flag=0;
                break;
            }
            ans+=flag;
        }
        return ans;
    }
};

// Time Complexity : O(N * Sqrt(N)) => O(N∗Sqrt(N));
// Space Complexity: O(Sqrt(N));
