class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> arr(n+1, 0);
        for(int i = 0; i<n; i++) {
            int c = citations[i];
            if(c>n) arr[n]++;
            else
              arr[c]++;
            
        }
        int sum = 0;
        for(int i=n; i>=0; i--) {
           
             sum+=arr[i];
              if(sum>=i) return i;
        }
        return -1;
    }
};