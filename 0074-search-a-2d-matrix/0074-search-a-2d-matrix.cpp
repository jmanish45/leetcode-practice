class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int lo = 0;
        int hi = (n*m) - 1;
        while(lo<=hi) {
            int mid_idx = lo + (hi-lo)/2;
            int row = mid_idx/m;
            int col = mid_idx % m;
            int mid_val = matrix[row][col];
            if(mid_val == target) return true;
            else if (mid_val < target) {
                lo = mid_idx + 1;
            }
            else hi = mid_idx - 1;
        }
        return false;
    }
};
// };
// class Solution {
// public:
//     bool  search(vector<int> &arr, int target) {
//         int lo = 0;
//         int hi = arr.size()-1;
//         while(lo<=hi) {
//             int mid = lo + (hi-lo)/2;
//             if(target == arr[mid]) return true;
//             else if(target > arr[mid]) {
//                 lo = mid + 1;
//             }
//             else {
//                 hi = mid - 1;
//             }
//         }
//         return false;
//     }
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         bool result = false;
//         for(int i = 0; i<m; i++) {
//             if(target>= matrix[i][0] && target<=matrix[i][n-1]) {
//                  result = search(matrix[i], target);
//             }   
//         }
//         return result;
//     }
// };