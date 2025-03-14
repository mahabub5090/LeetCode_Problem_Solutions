// Problem Link: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/?envType=daily-question&envId=2025-03-14

class Solution {
public:
    int possible(int mid,auto &c,long long k){
        long long number=0;
        for(int i=0;i<c.size();i++){
            number+=c[i]/mid;
        }
        return number>=k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int l=0,r=*max_element(candies.begin(),candies.end());
        while(l<r){
            int mid=(l+r+1)/2;

            if(possible(mid,candies,k))l=mid;
            else r=mid-1;
        }
        return l;
    }
};

// Time Complexity : O(Nlog(Max(candies.size()))) => O(NlogN);
// Space Complexity: O(1);