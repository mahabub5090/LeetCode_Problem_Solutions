// Problem Link: https://leetcode.com/problems/count-collisions-on-a-road/description/?envType=daily-question&envId=2025-12-04

class Solution {
public:
    int countCollisions(string directions) {
        int ans=0,r=0;
        char last='X';
        for(auto &c:directions){
            if(c=='R'){
                r++;
                last=c;
            }
            else if(c=='S'){
                if(r)ans+=r;
                r=0;
                last=c;
            }
            else{
                if(last=='R'){
                    ans+=r+1;
                    r=0;
                }
                else if(last=='S')ans++;
                else continue;
                last='S';
            }
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);