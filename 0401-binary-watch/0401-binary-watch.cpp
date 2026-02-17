class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> times;
        for(int HH = 0; HH<=11 ; HH++){
            for(int MM=0; MM<=59; MM++) {
                if(__builtin_popcount(HH)+ __builtin_popcount(MM) == turnedOn) {
                    string hour = to_string(HH);
                    string min = (MM>=10 ? "" : "0") + to_string(MM);

                    times.push_back(hour + ":" + min);
                    
                }
            }
        }
        return times;
    }
};