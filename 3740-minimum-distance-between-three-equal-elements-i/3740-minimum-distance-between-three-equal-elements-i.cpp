class Solution {
public:
    int solve(vector<int>& check) {
        int a = abs(check[0]-check[1]);
        int b = abs(check[1]-check[2]);
        int c = abs(check[0]-check[2]);
        return a+b+c;
    }

    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int mindist = INT_MAX;  
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++) {
            mp[nums[i]]++;
        }

        for(int i=0; i<n; i++) {

            if(mp[nums[i]]>=3) {
                vector<int> check;
                int a = nums[i];

                for(int j = i; j<n; j++) {

                    if(nums[j]==a) {
                        check.push_back(j);
                    }

                    // ✅ FIX: don't stop at first 3
                    if(check.size() >= 3) {
                        int sz = check.size();

                        vector<int> temp = {
                            check[sz-3],
                            check[sz-2],
                            check[sz-1]
                        };

                        mindist = min(mindist, solve(temp));
                    }
                }
            }

            mp[nums[i]]--;
            if(mp[nums[i]]==0) mp.erase(nums[i]);
        }

        return (mindist==INT_MAX) ? -1 : mindist;
    }
};