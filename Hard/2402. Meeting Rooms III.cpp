// Probblem Link: https://leetcode.com/problems/meeting-rooms-iii/description/?envType=daily-question&envId=2025-07-11

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<long long>roomTime(n,0);
        vector<int>meetCnt(n,0);
        sort(meetings.begin(),meetings.end());

        for(auto &meet:meetings){
            int start=meet[0],end=meet[1];
            long long avails=LLONG_MAX;
            int minAvails=0;
            bool unUsed=0;

            for(int i=0;i<n;i++){
                if(roomTime[i]<=start){
                    unUsed=1;
                    meetCnt[i]++;
                    roomTime[i]=end;
                    break;
                }
                if(avails>roomTime[i]){
                    avails=roomTime[i];
                    minAvails=i;
                }
            }

            if(unUsed==0){
                roomTime[minAvails]+=end-start;
                meetCnt[minAvails]++;
            }
        }

        int maxMeetCnt=0,maxMeetRoom=0;
        for(int i=0;i<n;i++){
            if(meetCnt[i]>maxMeetCnt){
                maxMeetCnt=meetCnt[i];
                maxMeetRoom=i;
            }
        }
        return maxMeetRoom;
    }
};

// Time Complexity : O((N^2)logN);
// Space Complexity: O(N);