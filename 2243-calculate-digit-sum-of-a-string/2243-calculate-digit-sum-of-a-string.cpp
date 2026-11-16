class Solution {
public:
    string digitSum(string s, int k) {
        string p = s;
        while(p.length() > k) {
            int i = 0;
            string t = "";
            while(i < p.length()) {
                int sum = 0;
                for(int j = i; j < k+i && j < p.length(); j++) {
                    sum += p[j] - '0';
                }
                t += to_string(sum);
                i += k;
            }
            p = t;
        }

        return p;
    }
};