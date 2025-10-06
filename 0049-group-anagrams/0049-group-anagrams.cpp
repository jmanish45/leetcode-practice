class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,  vector<string>> m;
        for(string str : strs) {
            string word = str;
            sort(word.begin(), word.end());
            
            //if word is  not  added or made in map
            if(m.find(word)==m.end()) {
                vector<string> v;
                m[word] = v;
            }
            m[word].push_back(str);   
        }
        for(auto x : m) {
            ans.push_back(x.second);
        }
        return ans;
    }

};