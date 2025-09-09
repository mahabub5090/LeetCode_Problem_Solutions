// Problem Link: https://leetcode.com/problems/number-of-people-aware-of-a-secret/description/?envType=daily-question&envId=2025-09-09

class Solution {
public:
    int mod=1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        deque<pair<int,int>>know,share;
        know.push_back({1,1});
        int knowCnt=1,shareCnt=0;

        for(int i=2;i<=n;i++){
            if(!know.empty() && know.front().first+delay==i){
                knowCnt=(knowCnt-know.front().second+mod)%mod;
                shareCnt=(shareCnt+know.front().second)%mod;
                share.push_back(know.front());
                know.pop_front();
            }

            if(!share.empty() && share.front().first+forget==i){
                shareCnt=(shareCnt-share.front().second+mod)%mod;
                share.pop_front();
            }

            if(!share.empty()){
                knowCnt+=shareCnt;
                knowCnt%=mod;
                know.push_back({i,shareCnt});
            }
        }
        return (knowCnt+shareCnt)%mod;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(N);