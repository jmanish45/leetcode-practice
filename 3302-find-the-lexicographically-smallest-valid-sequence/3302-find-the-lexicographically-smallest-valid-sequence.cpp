class Solution {
public:
    vector<int> validSequence(string w1, string w2) {
        int m = w1.length();
        int n = w2.length();
        vector<int> sameinright(m, 0);
        int rightsame = 0;
        int i = m-1;
        int j = n-1;
        while(i >= 0) {
            if(j >= 0 && w1[i] == w2[j]) {
                rightsame++;
                j--;
            }

            sameinright[i] = rightsame;
            i--;
        }

        vector<int> ans;
        bool canchange = true; 

        i = 0;
        j = 0;
        while(i < m && j < n) {
            if(w1[i] == w2[j]) {
                ans.push_back(i);
                j++;
            } else if(canchange == true && i+1 < m && sameinright[i+1] >= n-j-1) {
                ans.push_back(i);
                j++;
                canchange = false;
            }

            i++;
        }

        return j == n ? ans : vector<int>();
    }
};