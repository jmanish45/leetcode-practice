class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool flag = false;
        int n = nums.size();
        int i = 1;
        while(i<n && nums[i]>nums[i-1]) {
            flag = true;
            i++;
        }
        if(flag == false) return false;
        else flag =false;

        
        while(i<n && nums[i]<nums[i-1]) {
            flag = true;
            i++;
        }
        if(flag == false) return false;
        else flag =false;

        while(i<n && nums[i]>nums[i-1]) {
            flag = true;
            i++;
        }
        if(i!=n) return false;
        if(flag == false) return false;
        

        return true;


    }
};