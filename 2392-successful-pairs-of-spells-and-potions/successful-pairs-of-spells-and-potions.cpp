class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> ans;

        for (int spell : spells) {
            // Calculate the minimum potion needed
            long long required = (success + spell - 1) / spell;  // ceil(success / spell)
            // Use lower_bound to find first potion >= required
            auto it = lower_bound(potions.begin(), potions.end(), required);
            int count = potions.end() - it;
            ans.push_back(count);
        }
        return ans;
    }
};
