class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxLen = 0;

        for (int t = 1; t <= 26; t++) {
            vector<int> count(26, 0);
            int l = 0, r = 0;
            int unique = 0;     // total unique characters in window
            int atLeastK = 0;   // characters appearing at least k times

            while (r < s.size()) {
                if (unique <= t) {
                    int idx = s[r] - 'a';
                    if (count[idx] == 0) unique++;
                    count[idx]++;
                    if (count[idx] == k) atLeastK++;
                    r++;
                } else {
                    int idx = s[l] - 'a';
                    if (count[idx] == k) atLeastK--;
                    count[idx]--;
                    if (count[idx] == 0) unique--;
                    l++;
                }

                if (unique == t && unique == atLeastK) {
                    maxLen = max(maxLen, r - l);
                }
            }
        }

        return maxLen;
    }
};
