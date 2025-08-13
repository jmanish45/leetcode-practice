class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        stack<int> openst, starst;
        for(int i = 0; i<n ; i++) {
            if(s[i]=='(') openst.push(i);
            else if(s[i]=='*') starst.push(i);
            else {
                if(!openst.empty()) openst.pop();
                else if(!starst.empty()) starst.pop();
                else {
                    return false;
                }
            }
        }
        while(!openst.empty() && !starst.empty()) {
            if(openst.top() > starst.top()) return false;
            openst.pop();
            starst.pop();
        }
        return openst.empty();
    }
};