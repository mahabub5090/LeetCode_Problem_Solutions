// Problem Link: https://leetcode.com/problems/design-a-number-container-system/description/?envType=daily-question&envId=2025-02-08

class NumberContainers {
    public:
        unordered_map<int,set<int>>mp;
        unordered_map<int,int>indexVal;
        NumberContainers() {
           
        }
        void change(int index, int number) {
            if(indexVal[index]){
                int prev=indexVal[index];
                mp[prev].erase(index);
            }
        
            mp[number].insert(index);
            indexVal[index]=number;
        }
        
        int find(int number) {
            if(mp[number].size())return *mp[number].begin();
            return -1;
        }
    };
    
     // Time Complexity : O(N) * O(logN+1) => O(NlogN);
     // Space Complexity: O(2*N) => O(N);
     // In each call Change() function takes O(logN) times and find() function takes O(1) times;
    
    /**
     * Your NumberContainers object will be instantiated and called as such:
     * NumberContainers* obj = new NumberContainers();
     * obj->change(index,number);
     * int param_2 = obj->find(number);
     */
    
    