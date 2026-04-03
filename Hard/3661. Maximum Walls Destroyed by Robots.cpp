// Problem Link: https://leetcode.com/problems/maximum-walls-destroyed-by-robots/description/?envType=daily-question&envId=2026-04-03

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n=robots.size();
        int pos,pos2,pos3,leftPos,rightPos;
        vector<int>left(n,0),right(n,0),nums(n,0);
        unordered_map<int,int>dist;
        for(int i=0;i<n;i++)dist[robots[i]]=distance[i];

        sort(robots.begin(),robots.end());
        sort(walls.begin(),walls.end());

        for(int i=0;i<n;i++){
            pos=upper_bound(walls.begin(),walls.end(),robots[i])-walls.begin();

            if(i>=1){
                int mx=max(robots[i]-dist[robots[i]],robots[i-1]+1);
                leftPos=lower_bound(walls.begin(),walls.end(),mx)-walls.begin();
            }
            else{
                leftPos=lower_bound(walls.begin(),walls.end(),robots[i]-dist[robots[i]])-walls.begin();
            }

            left[i]=pos-leftPos;

            if(i<n-1){
                int limit=min(robots[i]+dist[robots[i]],robots[i+1]-1);
                rightPos=upper_bound(walls.begin(),walls.end(),limit)-walls.begin();
            }
            else{
                rightPos=upper_bound(walls.begin(),walls.end(),robots[i]+dist[robots[i]])-walls.begin();
            }

            pos2=lower_bound(walls.begin(),walls.end(),robots[i])-walls.begin();
            right[i]=rightPos-pos2;

            if(i==0)continue;

            pos3=lower_bound(walls.begin(),walls.end(),robots[i-1])-walls.begin();
            nums[i]=pos-pos3;
        }

        int leftSub,rightSub,currLeft,currRight;
        leftSub=left[0];
        rightSub=right[0];
        for(int i=1;i<n;i++){
            currLeft=max(leftSub+left[i],rightSub-right[i-1]+min(left[i]+right[i-1],nums[i]));
            currRight=max(leftSub+right[i],rightSub+right[i]);
            leftSub=currLeft;
            rightSub=currRight;
        }
        return max(leftSub,rightSub);
    }
};

// Time Complexity : O(NlogN);
// Space Complexity: O(N);