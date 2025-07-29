class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st; // store indices of '('
        unordered_set<int> removeIdx; // indices to remove

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop(); // matched
                } else {
                    removeIdx.insert(i); // unmatched ')'
                }
            }
        }

        // All unmatched '(' left in the stack
        while (!st.empty()) {
            removeIdx.insert(st.top());
            st.pop();
        }

        // Build valid result
        string result;
        for (int i = 0; i < s.size(); ++i) {
            if (removeIdx.find(i) == removeIdx.end()) {
                result += s[i];
            }
        }

        return result;
    }
};
