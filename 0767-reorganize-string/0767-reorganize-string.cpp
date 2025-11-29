class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        int n = s.length();
        //unordered_map and heap both can require
        vector<int> freq(26, 0);
        for(int i=0; i<n;i++) {
            freq[s[i]-'a']++;
        }

        priority_queue<pair<int, char>> pq;
        for(int i=0; i<26; i++) {
            if(freq[i]>0) {
                pq.push({freq[i], char('a'+i)});
            }
        }

        while(pq.size()>1) {
            int f1 = pq.top().first;
            char c1 = pq.top().second;
            pq.pop();
            int f2 = pq.top().first;
            char c2 = pq.top().second;
            pq.pop();
            ans+=c1;
            ans+=c2;
            f1--;
            f2--;
            if(f1>0) {
                pq.push({f1, c1});
            }
            if(f2>0) {
                pq.push({f2, c2});
            } 
        }
        if(pq.size()==1) {
            if(pq.top().first == 1) ans+=pq.top().second;
            else return "";
        }

        return ans;

        
        

    }
};