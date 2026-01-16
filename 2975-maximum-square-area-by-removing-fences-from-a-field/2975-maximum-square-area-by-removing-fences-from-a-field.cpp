class Solution {
public:
    int MOD = 1e9 + 7;
    int maximizeSquareArea(int m, int n, vector<int>& hfences, vector<int>& vfences) {
        vector<int> hf;
        hf.push_back(1);
        for(auto& x : hfences) {
            hf.push_back(x);
        }
        hf.push_back(m);
        int H = hf.size();
        sort(hf.begin(), hf.end());
        unordered_set<int> hst;
        for(int i=0; i<H; i++) {
            for(int j=i+1; j<H; j++) {
                hst.insert(hf[j]-hf[i]);
            }
        }
        vector<int> vf;
        vf.push_back(1);
        unordered_set<int> vst;
        
        for(auto& x : vfences)  {
            vf.push_back(x);
        }
        vf.push_back(n);
        int V = vf.size();
        sort(vf.begin(), vf.end());
        for(int i=0; i<V; i++) {
            for(int j=i+1; j<V; j++) {
                vst.insert(vf[j]-vf[i]);
            }
        }
        long long maxarea = 0;
        int area = 0;
        for (int x : hst) {
            if (vst.count(x)) {
            maxarea =max(maxarea, 1LL * x * x);
            }
        }
        return maxarea == 0 ? -1 : maxarea % MOD;
    }
};