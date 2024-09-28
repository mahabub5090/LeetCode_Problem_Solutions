// Problem Link: https://leetcode.com/problems/design-circular-deque/description/?envType=daily-question&envId=2024-09-28

class MyCircularDeque {
public:
    vector<int>vc,vc2,v;int cnt=0,cnt2=0,n;
    MyCircularDeque(int k) {
     n=k;   
    }
    
    bool insertFront(int value) {
        if(cnt+cnt2==n)return 0;
        vc.push_back(value);
        cnt++;
        return 1;
    }
    
    bool insertLast(int value) {
        if(cnt+cnt2==n)return 0;
        vc2.push_back(value);
        cnt2++;
        return 1;
    }
    
    bool deleteFront() {
        if(vc.size()==0){
            if(vc2.size()){
                vc2.erase(vc2.begin());
                cnt2--;
                return 1;
            }
            return 0;
        };
        vc.pop_back();
        cnt--;
        return 1;
    }
    
    bool deleteLast() {
        if(vc2.size()==0){
            if(vc.size()>0){
                vc.erase(vc.begin());
                cnt--;
                return 1;
            }
            return 0;
        };
        cnt2--;
        vc2.pop_back();
        return 1;
    }
    
    int getFront() {
        if(vc.empty()){
            if(vc2.empty())return -1;
            return vc2.front();
        }
        return vc.back();
    }
    
    int getRear() {
        if(vc2.empty()){
            if(vc.empty())return -1;
            return vc.front();
        }
        return vc2.back();
    }
    
    bool isEmpty() {
        return cnt==0 && cnt2==0;
    }
    
    bool isFull() {
        return cnt+cnt2==n;
    }
};

// Time Complexity : O(N)*O(N) => O(N^2);// O(N) for n times call;
// Space Complexity: O(N);

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */