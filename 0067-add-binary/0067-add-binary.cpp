class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        string ans = "";
        int carry = 0;
        while(i>=0 || j>=0 ) {
            int sum = carry;
            if(i>=0) { 
                sum+= a[i] - '0';
                i--;
            }
            if(j>=0) {
                sum += b[j] - '0';
                j--;
            }
            if(sum%2==0) {
                ans+= (sum%2)+ '0';
                carry = sum/2;
            }
            else {
                ans += (sum % 2) + '0';
                carry = sum / 2;
            }
            
        }
        if(carry==1) {
            ans+='1';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};