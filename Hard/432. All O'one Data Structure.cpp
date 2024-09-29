// Problem Link: https://leetcode.com/problems/all-oone-data-structure/description/?envType=daily-question&envId=2024-09-29

class AllOne {
public:
    unordered_map<string,int>cnt;
    set<pair<int,string>>st;
    AllOne() {
        cnt.clear();
    }
    
    void inc(string key) {
        int n=cnt[key];
        cnt[key]++;
        st.erase({n,key});
        st.insert({n+1,key});
    }
    
    void dec(string key) {
        int n=cnt[key];
        cnt[key]--;
        st.erase({n,key});
        if(cnt[key])st.insert({n-1,key});
        else cnt.erase(key);
    }
    
    string getMaxKey() {
        if(st.size())return st.rbegin()->second;
        return "";
    }
    
    string getMinKey() {
        if(st.size())return st.begin()->second;
        return "";
    }
};

// Time Complexity : O(1);
// Space Complexity: O(2*N) => O(N);

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */