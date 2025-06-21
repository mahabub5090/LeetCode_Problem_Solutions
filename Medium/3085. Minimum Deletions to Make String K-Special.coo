// Problem Link: https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/description/?envType=daily-question&envId=2025-06-21

class Solution {
public:
    int getAns(int mid,auto &vc,int k){
        int tt=0;
        for(int i=0;i<vc.size();i++){
            if(vc[i]>mid)tt+=mid;
            else if(mid-vc[i]<=k)tt+=vc[i];
        }
        return tt;
    }
    int minimumDeletions(string word, int k) {
        vector<int>vc(26,0);
        for(auto &c:word)vc[c-'a']++;
        int tt=0,mx=*max_element(vc.begin(),vc.end()),mn=*min_element(vc.begin(),vc.end());
        for(int i=mx;i>=mn;i--){
            tt=max(tt,getAns(i,vc,k));
        }
        return word.size()-tt;
    }
};

// Time Complexity : O(3*26) + O(N*26) => O(N);
// Space Complexity: O(26) => O(1);