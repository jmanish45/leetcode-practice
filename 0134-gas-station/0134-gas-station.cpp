class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas = 0;
        for(int i = 0; i<gas.size(); i++) {
            totalgas+=gas[i];
        }
        int totalcost = 0;
        for(int i = 0 ; i<cost.size(); i++) {
            totalcost+=cost[i];
        }
        if(totalgas<totalcost) return -1;
        int i = 0;
        int fuelrem = 0;
        int start = 0;
        while(i<gas.size()) {
            fuelrem += (gas[i]-cost[i]);
            if(fuelrem<0) {
                fuelrem = 0;
                start = i+1;
            }
            
            i++;
        }
        return start;
    }

};