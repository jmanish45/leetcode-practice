class Solution {
public:
    int decimal(vector<int>& bit) {
        int dec = 0;
        int mult = 1;
        for(int i =bit.size()-1 ;i>=0; i--) {
            if(bit[i]==1) dec+=mult;
            mult*=2;
        }
        return dec;
    }
    int check(vector<int>& bin, int num) {
        
        for(int i=0; i<bin.size(); i++) {
            vector<int> bit = bin;
            if(bit[i]==1) bit[i] = 0;
            int dec = decimal(bit);
            if((dec | (dec+1))==num) return dec;

        }
        return -1;

    }
    vector<int> binary(int num) {
        vector<int> bin;
        while(num>0) {
            if(num%2==0) bin.push_back(0);
            else bin.push_back(1);
            num=num/2;
        }
        reverse(bin.begin(), bin.end());
        return bin;
    }
    
    vector<int> minBitwiseArray(vector<int>& nums) {
        
        int n = nums.size(); // n = 4
        vector<int> ans(n,0); // [0,0,0,0]
        for(int i=0; i<n; i++) {
            if(nums[i]%2==0) ans[i] = -1;  
            else {
                vector<int> bin = binary(nums[i]);  //[1,1]
                ans[i] = check(bin, nums[i]);
            }
        }
        return ans;
    }
};