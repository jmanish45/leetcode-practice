class Solution {
public:
    void solve(string &str, int n, int &count, int k,  string& happy) {
        if(str.length()==n) {
            count++;
            if(count==k) happy = str;
            return ;
        }
        for(char ch = 'a' ; ch<='c' ; ch++) {
            if(!str.empty() && str.back()==ch) continue;
            str.push_back(ch);  //  DO push the character
            solve(str, n, count, k,  happy);
            str.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string str = "";
        string happy = "";
        int count = 0;
        solve(str, n, count, k,  happy);
        
        return happy;
    }
};