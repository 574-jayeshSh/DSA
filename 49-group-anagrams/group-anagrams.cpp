class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;
        for(const auto& s : strs){
            vector<int> count(26,0);
            for(char ch: s){
                count[ch - 'a']++;
            }
            string key = to_string(count[0]);
            for(int i = 1; i<26 ; ++i){
                key += "," + to_string(count[i]);
            }
            ans[key].push_back(s);
       }
       vector<vector<string>> res;
       for(auto it : ans){
            res.push_back(it.second);
       }

       return res;
    }
};