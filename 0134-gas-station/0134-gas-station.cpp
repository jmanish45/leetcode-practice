// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n = cost.size();
//         int rem = 0;
//         for(int i=0;i<n; i++) {
//             if(gas[i]<cost[i]) continue;
//             rem = gas[i]-cost[i];
//             int j = (i+1)%n;
//             while(j<n) {
//                 if(rem+gas[j]>=cost[j]) rem+=(gas[j]-cost[j]);
//                 else{
//                     break;
//                     rem = 0;
//                 } 
//                 j = (j+1)%n;
//                 if(i==j) r+eturn i;
//             }
//         }
//         return -1;

//     }
// };
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();
        int totalcost = 0;
        for(int i=0; i<n; i++) {
            totalcost+=cost[i];
        }
        int totalgas = 0;
        for(int i=0; i<n; i++) {
            totalgas+=gas[i];
        }
        if(totalgas<totalcost) return -1;
        int rem = 0;
        int start = 0;
        int i = 0;
        while(i<n) {
            if(rem+gas[i]<cost[i]) {
                rem = 0;
                start=i+1;
                
            }
            else {
                rem+=(gas[i]-cost[i]) ;
            }

            i++;

        }
        return start;
    }
};