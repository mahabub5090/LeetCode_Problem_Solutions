// Problem Link: https://leetcode.com/problems/count-mentions-per-user/description/?envType=daily-question&envId=2025-12-12

class Solution {
public:
    vector<int> processIds(auto &str){
        vector<int>ids;
        stringstream ss(str);
        string temp;
        while(ss>>temp){
            string s="";
            for(int i=2;i<temp.size();i++)s+=temp[i];
            ids.push_back(stoi(s));       
        }
        return ids;
    }

    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<vector<int>>offLine(numberOfUsers);
        vector<int>ans(numberOfUsers,0);

        sort(events.begin(),events.end(),[](auto &c,auto &d){             
            if(c[0]!=d[0])return c[0]=="OFFLINE";
            return stoi(c[1])<stoi(d[1]);
        });

        for(auto &c:events){
            string t=c[0];
            int time=stoi(c[1]);

            if(t=="MESSAGE"){  
                if(c[2]=="ALL")for(auto &c:ans)c++;
                else if(c[2]=="HERE"){
                    for(int i=0;i<numberOfUsers;i++){
                        int f=1;
                        for(auto &c:offLine[i]){
                            if(time>=c && time<c+60){
                                f=0;
                                break;
                            }
                        }
                        if(f)ans[i]++;
                    }
                }
                else{
                    vector<int>ids=processIds(c[2]);
                    for(auto &c:ids)ans[c]++;
                }
            }
            else{
                int id=stoi(c[2]);
                offLine[id].push_back(time);
            }
        }
        return ans;
    }
};

// Time Complexity : O(MlogM) + O(N*M) => O(N^2);
// Space Complexity: O(N+(3*N)) => O(N);
// Here N is numberOfUsers and M is events.size();