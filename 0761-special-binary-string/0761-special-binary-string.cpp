class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> specials; 
        int start = 0;
        int sum = 0;
        for(int i = 0; i< s.length(); i++) {

            sum+= (s[i]=='1') ? 1 : -1 ;
            if(sum==0) {
                specials.push_back('1'+makeLargestSpecial(s.substr(start+1, i-start-1))+'0' );
                start = i+1;
            }
        }

        sort(specials.begin(), specials.end(), greater<string>());

        string result ;
        for(auto & str : specials) {
            result+=str;
        }
        return result;
        


    }
};