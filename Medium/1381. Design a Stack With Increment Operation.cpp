// Problem Link: https://leetcode.com/problems/design-a-stack-with-increment-operation/?envType=daily-question&envId=2024-09-30

class CustomStack {
public:
    int n;
    stack<int>st;
    vector<int>vc;
    CustomStack(int maxSize) {
        n=maxSize;
    }
    
    void push(int x) {
        if(st.size()<n)st.push(x),vc.push_back(0);
    }
    
    int pop() {
        if(st.empty())return -1;
        if(vc.size()>1)vc[vc.size()-2]+=vc.back();
        int ans=st.top()+vc.back();
        st.pop();vc.pop_back();
        return ans;
    }
    
    void increment(int k, int val) {
        if(st.size()){
            int id=min(k,(int)vc.size())-1;
            vc[id]+=val;
        }
    }
};

// Time Complexity : O(1);
// Space Complexity: O(2*N) => O(N);

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */