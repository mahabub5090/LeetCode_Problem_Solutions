// Problem link: https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/description/?envType=daily-question&envId=2024-11-14

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1,r=*max_element(quantities.begin(),quantities.end()),mid;
        while(l<r){
            mid=(l+r)/2;
            int tt=0;
            for(auto &c:quantities)tt+=c/mid+(c%mid?1:0);
            if(tt>n)l=mid+1;
            else r=mid;
        }
        return l;
    }
};

// Time Complexity : O(N) + O(N*logN) => O(NlogN);
// Space Complexity: O(1);