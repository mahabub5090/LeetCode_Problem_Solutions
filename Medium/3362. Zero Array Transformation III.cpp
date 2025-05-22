// Problem Link: https://leetcode.com/problems/zero-array-transformation-iii/description/?envType=daily-question&envId=2025-05-22

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        sort(queries.begin(),queries.end());
        vector<int>diff(n+1,0);
        priority_queue<int>pq;

        int opCnt=0;
        for(int i=0,j=0;i<n;i++){
            opCnt+=diff[i];

            while(j<queries.size() && queries[j][0]==i){
                pq.push(queries[j][1]);
                j++;
            }

            while(opCnt<nums[i] && pq.size() && pq.top()>=i){
                opCnt+=1;
                diff[pq.top()+1]-=1;
                pq.pop();
            }

            if(opCnt<nums[i])return -1;
        }
        return pq.size();
    }
};

// Time Complexity : O(QlogQ + N + QlogQ) => O(NlogN);
// Space Complexity: O(N+Q) => O(N);