// Problem Link: https://leetcode.com/problems/jump-game-iii/description/?envType=daily-question&envId=2026-05-17

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int> visit(n,0);
        queue<int> q;
        q.push(start);

        while(q.size()){
            int index=q.front();
            q.pop();

            if(index<0 || index>=n || visit[index]) continue;
            if(arr[index]==0) return 1;

            visit[index]=1;
            q.push(index+arr[index]);
            q.push(index-arr[index]);
        }
        return 0;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N) + O(N) => O(N);