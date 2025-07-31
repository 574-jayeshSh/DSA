class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp (256,-1);
        int n = s.size();
        int l = 0, r = 0;
        int maxlen = 0;

        while(r != n){
            if(mpp[s[r]] != -1){
                if(mpp[s[r]] >= l){
                    l = mpp[s[r]] + 1;
                }
            }
            int len = r - l + 1;
            maxlen = max(maxlen,len);
            mpp[s[r]] = r;

            r++;
        }
        return maxlen;
    }
};