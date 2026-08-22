class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rS) {

        unordered_map<int, vector<int>> cine;
        for (auto v : rS) {
            int i = v[0];
            int j = v[1];

            if (cine.find(i) == cine.end())
                cine[i] = vector<int>(10, 0);

            cine[i][j - 1] = 1;
        }

        int grps = 2 * n;

        for (auto &[row, seats] : cine) {

            int cnt = 0;
            int rowGroups = 0;

            for (int j = 1; j < 9; j++) {

                if (seats[j] != 1 &&
                    cnt == 0 &&
                    (j != 2 && j != 4)) {

                    cnt++;
                }
                else if (seats[j] != 1 && cnt != 0) {
                    cnt++;
                }
                else {
                    cnt = 0;
                }

                if (cnt == 4) {
                    rowGroups++;
                    cnt = 0;
                }
            }
            grps -= (2 - rowGroups);
        }

        return grps;
    }
};