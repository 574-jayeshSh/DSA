class Solution {
public:
    int romanToInt(string s) {
        static int val[26] = {};
        static bool init = false;
        if (!init) {
            val['I' - 'A'] = 1;
            val['V' - 'A'] = 5;
            val['X' - 'A'] = 10;
            val['L' - 'A'] = 50;
            val['C' - 'A'] = 100;
            val['D' - 'A'] = 500;
            val['M' - 'A'] = 1000;
            init = true;
        }

        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && val[s[i] - 'A'] < val[s[i + 1] - 'A'])
                ans -= val[s[i] - 'A'];
            else
                ans += val[s[i] - 'A'];
        }
        return ans;
    }
};
