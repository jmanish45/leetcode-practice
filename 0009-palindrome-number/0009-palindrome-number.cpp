class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        int left = 0; 
        int right =  str.size()-1;
        while(left<right){
        if(str[left]!=str[right]) {
            return false;
        }
        left++;
        right--;
        }
    return true;
    }
};
// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if(x<0 || (x%10==0 && x!=0)) {
//             return false;
//         }
//         int reversedhalf = 0;
//         while(x>reversedhalf) {
//             int digits = x%10;
//             reversedhalf = reversedhalf*10 + digits;
//             x/=10;
//         }
//         return(x==reversedhalf || x==reversedhalf/10);
//     }
// };