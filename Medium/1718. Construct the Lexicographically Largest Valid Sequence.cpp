// Problem Link: 

class Solution {
    public:
         vector<int>res;
         int backtrack(int n, int l, auto& arr, auto& used) {
            if(l==arr.size()) {
                res=arr;
                return 1;
            }
    
            if(arr[l]!=-1)return backtrack(n,l+1,arr,used);
    
            for (int num=n;num>=1;--num) {
                if (used[num]) continue;
    
                int r = (num == 1) ? l : l + num;
                if (r<arr.size() && arr[r]==-1) {
                    arr[l]=arr[r]=num;
                    used[num]=1;
    
                    if (backtrack(n, l + 1, arr, used))return 1;
                    arr[l]=arr[r]=-1;
                    used[num]=0;
                }
            }
    
            return 0;
        }
        vector<int> constructDistancedSequence(int n) {
            res.clear();
            vector<int> arr(2 * n - 1, -1);
            vector<bool> used(n + 1, false);
            backtrack(n, 0, arr, used);
            return res;
        }
    };
    
    // Time Complexity : O(2^N) * O(N^2) => O(2^N);
    // Space Complexity: O(N^2);