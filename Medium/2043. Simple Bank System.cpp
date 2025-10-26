// Problem Link: https://leetcode.com/problems/simple-bank-system/description/?envType=daily-question&envId=2025-10-26

class Bank {
public:
    vector<long long>accounts;
    Bank(vector<long long>& balance) {
        accounts=balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1>accounts.size() || account2>accounts.size() || accounts[account1-1]<money)return 0;
        accounts[account1-1]-=money;
        accounts[account2-1]+=money;
        return 1;
    }
    
    bool deposit(int account, long long money) {
        if(account>accounts.size())return 0;
        accounts[account-1]+=money;
        return 1;
    }
    
    bool withdraw(int account, long long money) {
        if(account>accounts.size() || accounts[account-1]<money)return 0;
        accounts[account-1]-=money;
        return 1;
    }
};

// Time Complexity : O(1); // for each operation;
// Space Complexity: O(N); // for storing account balances;

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */