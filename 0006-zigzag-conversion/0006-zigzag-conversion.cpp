class Solution {
public:
    string convert(string s, int Rows) {
        int n = s.size();
        if(Rows==1 ||  Rows>n) {
            return s;
        }
        int row = 0;
        int t = 0;
        vector<vector<char>> v(Rows);
        for(int i = 0; i<n; i++) {
            v[row].push_back(s[i]);
            if(row==0) {
                t=1;
            }
            else if(row==Rows-1){
                t=-1;
            }
            row+=t;
        }
        string ans="";
        for(int i = 0; i<Rows ;i++) {
            for(int j = 0; j<v[i].size() ; j++) {
                ans+=v[i][j];
            }
        }
        return ans;
    }
};