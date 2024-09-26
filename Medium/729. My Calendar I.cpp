// Problem Link: https://leetcode.com/problems/my-calendar-i/description/?envType=daily-question&envId=2024-09-26

class MyCalendar {
public:
    MyCalendar() {
        
    }
    vector<pair<int,int>>vc;
    bool book(int start, int end) {
        for(auto &c:vc){
             if(c.first<end && start<c.second)
                return false;
        }
        vc.push_back({start,end});
        return 1;
    }
};

// Time Complexity : O(N^2);
// Space Complexity: O(N);

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */