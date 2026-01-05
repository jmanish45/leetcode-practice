class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totsum = 0;
        long long negcount = 0;
        int minneg = INT_MAX;
        int n = matrix.size();
        for(int i=0 ; i<n; i++) {
            for(int j = 0; j<n; j++) {
                int val = matrix[i][j] ;
                if(val<=0) {
                    totsum = totsum + (-1)*val;
                    negcount++;
                   
                }
                else totsum+=val;   
                minneg = min(minneg, abs(val)); 
            }
        }
        if(negcount%2==0) return totsum;
        else {
           totsum =  totsum - 2*(minneg);
        }
        return totsum;

    }
};