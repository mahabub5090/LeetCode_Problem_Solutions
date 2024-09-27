// Problem Link: https://leetcode.com/problems/my-calendar-ii/description/?envType=daily-question&envId=2024-09-27

class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    vector<pair<int,int>>vc,vc2;
    bool book(int start, int end) {
        for(auto &[a,b]:vc2){
            if(end>a and b>start)return 0;
        }
        for(auto &[a,b]:vc){
            if(end>a and b>start)vc2.push_back({max(start,a),min(end,b)});
        }
        vc.push_back({start,end});
        return 1;
    }
};

// Time Complexity : O(N)*O(2*N) => O(N^2); // O(N) for N calls;
// Space Complexity: O(2*N) => O(N);

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */