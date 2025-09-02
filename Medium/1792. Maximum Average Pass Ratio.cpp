// Problem Link: https://leetcode.com/problems/maximum-average-pass-ratio/?envType=daily-question&envId=2024-12-15
// Problem Link: https://leetcode.com/problems/maximum-average-pass-ratio/description/?envType=daily-question&envId=2025-09-01


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

// Way: 2 =>

class Solution {
public:
    double gain(int a,int b){
        return ((a+1)/((double)(b+1)))-(a/(double)b);
    }
    static bool cmp(auto &a,auto &b){
        return a[0]<b[0];
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<vector<double>, vector<vector<double>>,bool(*)(vector<double>&,vector<double>&)>pq(cmp);

        for(auto &c:classes)pq.push({gain(c[0],c[1]),(double)c[0],(double)c[1]});

        while(extraStudents--){
            auto c=pq.top();pq.pop();
            pq.push({gain(c[1]+1,c[2]+1),c[1]+1,c[2]+1});
        }
        
        double ans=0;
        while(pq.size())ans+=pq.top()[1]/pq.top()[2],pq.pop();
        ans/=classes.size();
        return ans;
    }
};

// Time Complexity : O(NlogN) + O(KlogN) => O(NlogN);
// Space Complexity: O(N);
// K is the number of classes;