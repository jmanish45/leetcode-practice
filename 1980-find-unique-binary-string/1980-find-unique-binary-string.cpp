// class Solution {
// public:
//     string findDifferentBinaryString(vector<string>& nums) {
//         string ans = "";
//         int len = nums[0].length(); // len = 2 
        
//         unordered_set<string> mp;
//         for(int i = 0; i<nums.size(); i++) {
//             mp.insert(nums[i]);
//         }
//         //len = 2 
//         //  1<<1 -> 10
//         // 1<<2 -> 100   -> 4
//         int total = 1<<len;
//         ///0000000000000000000000000000

//         // i = 0 -> 1  -> 01

//         for(int i=0; i<total; i++) {
//             string s = bitset<32>(i).to_string();
                //string s = bitset<32>(i).to_string();
//             s = s.substr(32-len);
//             if(mp.find(s)==mp.end()) {
//                 return s;
//             }
//         }
//         return ans ;
        
//     }
// };

// class Solution {
// public:
//     void solve(int n, string curr, vector<string>& bin) {
//         if(curr.length()==n) {
//             bin.push_back(curr);
//             return;
//         }
//         solve(n, curr+"0", bin);
//         solve(n, curr+"1",  bin);   
//     }
//     string findDifferentBinaryString(vector<string>& nums) {
//         string ans = "";
//         int n = nums[0].length();
//         vector<string> bin ;
//         solve(n , "", bin);
//         unordered_set<string> st;
//         for(int i=0; i<nums.size(); i++) {
//             st.insert(nums[i]);
//         }
//         for(int i=0; i<bin.size(); i++) {
//             if(st.find(bin[i])==st.end()) {
//                 return bin[i];
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    void solve(int n, string& curr, vector<string>& bin) {
        if(curr.length()==n) {
            bin.push_back(curr);
            return;
        }  

        // start with 0
        curr.push_back('0');
        solve(n, curr, bin);
        curr.pop_back();

        //start with "1" 
        curr.push_back('1');
        solve(n, curr, bin);
        curr.pop_back();


    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        string curr = "";
        vector<string> bin;
        solve(n, curr, bin);

        unordered_set<string> st(nums.begin(), nums.end());
        for(string s : bin) {
            if(st.find(s)==st.end()) {
                return s;
            }
        }
        
        return "";
    }
};