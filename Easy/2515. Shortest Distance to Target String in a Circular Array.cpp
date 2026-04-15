// Problem Link: https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/description/?envType=daily-question&envId=2026-04-15

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size(),ans=n;
        for(int i=0;i<n;i++){
            if(words[i]==target){
                ans=min(ans,abs(i-startIndex));
                ans=min(ans,i+n-startIndex);
                ans=min(ans,n-i+startIndex);
            }
        }
        return ans==n?-1:ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);