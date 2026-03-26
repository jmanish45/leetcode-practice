class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxf = 0;
        unordered_map<int, int> mp;
        int i = 0, j = 0;
        while(j<n) {
            mp[fruits[j]]++;
            if(mp.size()<=2) {
                maxf = max(maxf, j-i+1);
            }
            while(mp.size()>2) {
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0) mp.erase(fruits[i]);
                i++;
            }
            j++;
            
        }
        return maxf;
    }
};