class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long modpow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }
    long long factorial(int n) {
        long long fact = 1;
        for(int i=2;i<=n; i++) {
            fact = (fact * i) % MOD;
        }
        return fact;
    }
    long long count(string &word) {
        unordered_map<char, int> mp;
        int w = word.size();
        long long ans = factorial(w);
        for(char c: word) {
            mp[c]++;
        }
    
        for(auto &x: mp) {
            long long div = factorial(x.second);
            ans = ans*modpow(div, MOD - 2) % MOD;
        }
        return ans;

    }
    int countAnagrams(string s) {
        long long ans = 1;
        string word = "";
        for (char c : s) {
            if (c != ' ') {
                word += c;
            } 
            else {
                ans = (ans * count(word)) % MOD;
                word = "";
            }
        }
        if(!word.empty()) {
            ans = (ans* count(word)) % MOD;
        }
        return ans % MOD;

    }

};