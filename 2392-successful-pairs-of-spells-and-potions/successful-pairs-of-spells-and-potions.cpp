class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> ans(n , 0);
        sort(potions.begin(), potions.end());
        for(int i = 0; i<n; i++){
            int low = 0, high = m-1;
            while(low <= high){
                int mid = (low + high) / 2;
                long long int potionNeed = 1LL*spells[i] * potions[mid];
                if(potionNeed >= success) {
                    high = mid - 1;
                }
                else low = mid + 1;
            }
            ans[i] = m - low;
        }
        return ans;
    }
};