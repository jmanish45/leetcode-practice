class Solution {
public:
    void solve(string &str, int n, vector<string> &happys) {
        if(str.length()==n) {
            happys.push_back(str);
            return ;
        }
        for(char ch = 'a' ; ch<='c' ; ch++) {
            if(!str.empty() && str.back()==ch) continue;
            str.push_back(ch);  //  DO push the character
            solve(str, n, happys);
            str.pop_back();
        }


    }
    string getHappyString(int n, int k) {
        string str = "";
        vector<string> happys;
        solve(str, n, happys);
        if(k>happys.size()) return "";
        return happys[k-1];
    }
};