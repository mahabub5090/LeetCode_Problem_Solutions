// Problem Link: https://leetcode.com/problems/longest-happy-string/description/?envType=daily-question&envId=2024-10-16

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {  
        priority_queue<pair<int,char>>pq;
        pq.push({a,'a'}),pq.push({b,'b'}),pq.push({c,'c'});
        string s="";
        int fg=0;
        while(pq.size()){
            auto c=pq.top();pq.pop();
            if(s.empty()){
                s+=c.second;
                c.first--;
                pq.push(c);
                continue;
            }
            if(c.first==0)continue;
            if(s.back()==c.second){
                if(fg){
                    if(pq.size()==0)break;
                    auto c2=pq.top();pq.pop();pq.push(c);
                    if(c2.first==0)continue;
                    s+=c2.second;
                    c2.first--;
                    pq.push(c2);
                    fg=0;
                }
                else{
                    s+=c.second;
                    c.first--;
                    pq.push(c);
                    fg=1;
                }
            }
            else{
                s+=c.second;
                c.first--;
                pq.push(c);
            }
        }
        return s;
    }
};

// Time Complexity : O(a+b+c) => O(N); 
// Space Complexity: O(1);
