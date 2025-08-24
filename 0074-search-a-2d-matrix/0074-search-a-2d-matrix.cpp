class Solution {
public:
    bool  search(vector<int> &arr, int target) {
        int lo = 0;
        int hi = arr.size()-1;
        while(lo<=hi) {
            int mid = lo + (hi-lo)/2;
            if(target == arr[mid]) return true;
            else if(target > arr[mid]) {
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool result = false;
        for(int i = 0; i<m; i++) {
            if(target>= matrix[i][0] && target<=matrix[i][n-1]) {
                 result = search(matrix[i], target);
            }   
        }
        return result;
    }
};