// Problem Link: https://leetcode.com/problems/max-chunks-to-make-sorted/description/?envType=daily-question&envId=2024-12-19

// class Solution {
// public:
//     int maxChunksToSorted(vector<int>& arr) {
//          vector<int>vc;
//          int ans=0,cnt=0;
//          for(int i=0;i<arr.size();i++){
//             vc.push_back(arr[i]);
//             sort(vc.begin(),vc.end());
//             bool fg=1;
//             for(int j=0;j<=i;j++){
//                 if(j!=vc[cnt]){fg=0;break;}
//                 cnt++;
//             }
//             cnt=0;
//             if(fg)ans++;
//          }
//          return ans;
//     }
// };

// Time Complexity : O((N^2)logN);
// Space Complexity: O(N);

// Way: 2 =>

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        for(int i=1;i<arr.size();i++)arr[i]+=arr[i-1];
        int ans=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==((i*(i+1))/2))ans++;
        }
        return ans;
    }
};

// Time Complexity : O(N);
// Space Complexity: O(1);
