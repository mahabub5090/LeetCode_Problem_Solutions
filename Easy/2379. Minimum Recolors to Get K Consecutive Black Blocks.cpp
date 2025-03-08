// Problem Link: https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/?envType=daily-question&envId=2025-03-08

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int b=0,ans=k;
        int i=0,j=0,n=blocks.size();
        while(j<n){
            if(j<k)b+=blocks[j]=='B',j++;
            else{
                b+=blocks[j]=='B',j++;
                b-=blocks[i]=='B',i++;
            }
            ans=min(ans,k-b);
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);