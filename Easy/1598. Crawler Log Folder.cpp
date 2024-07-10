// Problem Link: https://leetcode.com/problems/crawler-log-folder/description/?envType=daily-question&envId=2024-07-10

class Solution {
public:
    int minOperations(vector<string>& logs) {
       int depth=0;
       for(auto &c:logs){
        if(c=="../")depth=max(depth-1,0);
        else if(c!="./")depth++;
       } 
       return depth;
    }
};