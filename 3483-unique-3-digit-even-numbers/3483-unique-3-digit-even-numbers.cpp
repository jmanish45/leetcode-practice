class Solution {
public:
    int num(vector<int>& v) {
        int m = 100;
        int N = 0;

        for(int i = 0; i < 3; i++) {
            N += v[i] * m;
            m /= 10;
        }

        return N;
    }

    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<int> st;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    if(i == j || j == k || i == k)
                        continue;
                    vector<int> v;
                    v.push_back(digits[i]);
                    v.push_back(digits[j]);
                    v.push_back(digits[k]);
                    if(v[0] != 0 && v[2] % 2 == 0) {
                        int N = num(v);
                        st.insert(N);
                    }
                }
            }
        }
        return st.size();
    }
};