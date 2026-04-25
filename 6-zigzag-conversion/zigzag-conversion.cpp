class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows == 0) return s;
        vector<vector<char>> pattern(numRows);

        int currRow = 0;
        bool goingDown = true;

        for(int i = 0; i<s.size(); i++){
            pattern[currRow].push_back(s[i]);

            if(currRow == 0) goingDown = true;
            else if(currRow == numRows-1) goingDown = false;

            if(goingDown) currRow++;
            else currRow--;
        }
        string ans = "";
        for(int i = 0; i<numRows; i++){
            for(char j : pattern[i]){
                ans += j;
            }
        }
        return ans;
    }
};