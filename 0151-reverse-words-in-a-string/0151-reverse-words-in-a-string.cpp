class Solution {
public:
    

    string reverseWords(string s) {
        int n = s.size();
        string ans = "";
        int i = 0;
        while(i<n && s[i]==' ') i++;
        while(i<n) {
            while(i<n && s[i]!=' '){ 
                ans+=s[i];
                i++;
            }
            while(i<n && s[i]==' ') i++;
            if(i<n) ans+=' ';
        
        }
        reverse(ans.begin(), ans.end());
        i = 0;
        int j = 0;
        int m = ans.size();
        while(i<m) {
            while(i<m && ans[i]==' ') {   //the sky is blue
                i++;   
            }
            while(i<m && ans[i]!=' ') {
                i++;      
              
            }
            reverse(ans.begin()+j, ans.begin()+i);
            j=i+1;
            

        }
        
        
        return ans;        
    }
};