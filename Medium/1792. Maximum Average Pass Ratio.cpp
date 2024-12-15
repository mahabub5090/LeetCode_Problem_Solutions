// Problem Link: https://leetcode.com/problems/maximum-average-pass-ratio/?envType=daily-question&envId=2024-12-15

class Solution {
public:
    class cmp{
        public:
        bool operator()(auto a,auto b){
            return get<0>(a)<get<0>(b);
        }
    };
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<tuple<double,int,int>,vector<tuple<double,int,int>>,cmp>pq;

        auto diff=[](auto a,auto b){
            return 1.0*(a+1)/(b+1)-1.0*a/b;};
        
        for(auto &c:classes){
            pq.push({diff(c[0],c[1]),c[0],c[1]});
        }
        while(extraStudents--){
            auto [a,b,c]=pq.top();
            pq.pop();
            b++,c++;
            pq.push({diff(b,c),b,c});
        }
        double ans=0;
        while(pq.size()){
            ans+=1.0*get<1>(pq.top())/get<2>(pq.top());
            pq.pop();
        }
        ans/=classes.size();
        return ans;
    }
};

// Time Complexity : O(NlogN) + O(KlogN) => O(NlogN);
// Space Complexity: O(N);
// K is the number of classes;