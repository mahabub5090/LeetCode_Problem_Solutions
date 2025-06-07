// Problem Link: https://leetcode.com/problems/snakes-and-ladders/description/?envType=daily-question&envId=2025-05-31

class Solution {
public:
    int ans=INT_MAX;
    map<int,pair<int,int>>mp;
    unordered_map<int,int>dp;
    
    void makeMap(int n){
        int num=1;
        for(int i=n-1;i>=0;i--){
            int l=n-i;
            for(int j=(l%2?0:n-1);j!=(l%2?n:-1);j+=(l%2?1:-1))mp[num++]={i,j};
        }
    }

    void getAns(int num,int cnt,auto &board){        
        if(num==mp.size()){
            ans=min(ans,cnt);
            return;
        }

        if(dp.count(num) && dp[num]<=cnt)return;
        dp[num]=cnt;

        for(int step=num+1;step<=min(num+6,(int)mp.size());step++){
            auto [ni,nj]=mp[step];
            if(board[ni][nj]!=-1){
                getAns(board[ni][nj],cnt+1,board);
            }
            else getAns(step,cnt+1,board);
        }
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        makeMap(n);
        getAns(1,0,board);
        return ans==INT_MAX?-1:ans;  
    }
};

// Time Complexity : O(N^2);
// Space Complexity: O(N^2);