class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;
        for(const auto& s : strs){
            string st = s;
            sort(st.begin(),st.end());
            string key = "";
            for(int i = 0; i<st.size() ;i++){
                if(i == st.size()-1) key += st[i];
                key += st[i];
                key += ",";
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