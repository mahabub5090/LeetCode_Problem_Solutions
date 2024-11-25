// Problem Link: https://leetcode.com/problems/sliding-puzzle/description/?envType=daily-question&envId=2024-11-25

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>>dir={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        string ansString="123450";
        string start="";
        for(auto &c:board)for(auto &cc:c)start+=to_string(cc);

        map<string,int>vis;
        queue<string>q;
        q.push(start);
        vis[start]++;

        int ans=0;
        while(q.size()){
            int size=q.size();
            while(size--){
                string curr=q.front();
                q.pop();

                if(curr==ansString)return ans;
                int pos=-1;
                for(auto &c:curr){
                    pos++;
                    if(c=='0')break;
                }
                for(auto c:dir[pos]){
                    string next=curr;
                    swap(next[pos],next[c]);

                    if(vis[next])continue;
                    vis[next]++;
                    q.push(next);
                }
            }
            ans++;
        }
        return -1;
    }
};

// Time Complexity : O((N*M)!) => O(6!) => 720;
// Space Complexity: O(N*M) * O((N*M)!) => O(6) * O(6!) => 6 * 720 => O(4320);