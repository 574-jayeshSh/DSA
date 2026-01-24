class Solution {
public:
    string nextTerm(string s) {
        string res = "";
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int cnt = 1;

            while (i + 1 < n && s[i] == s[i + 1]) {
                cnt++;
                i++;
            }

            res += to_string(cnt);
            res += s[i];
        }
        return res;
    }

    string countAndSay(int n) {
        string ans = "1";

        for (int i = 2; i <= n; i++) {
            ans = nextTerm(ans);
        }

        return ans;
    }
};
