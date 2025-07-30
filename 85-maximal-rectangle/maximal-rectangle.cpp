class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st; 
        int maxArea = 0;

        for(int i = 0; i<arr.size(); i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                int element = st.top() ; st.pop();
                int preSmall = st.empty() ? -1 : st.top();
                int nextSmall = i;
                maxArea = max(maxArea , arr[element]*(nextSmall - preSmall -1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int nse = arr.size();
            int element = st.top() ; st.pop();
            int preSmall = st.empty() ? -1 : st.top();
            maxArea = max(maxArea , arr[element]*(nse - preSmall -1));
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> pSum(n,vector<int>(m,0));
        int maxArea = 0;
        //prefix sum matrix
        for(int j = 0; j < m; j++){
            int sum = 0;
            for(int i = 0; i < n; i++){
                sum += matrix[i][j] - '0';
                if((matrix[i][j] -'0') == 0) sum = 0;
                pSum[i][j] = sum;
            }
        } 

        for(int i = 0; i < n; i++){
            maxArea = max(maxArea ,largestRectangleArea(pSum[i]) );
        }
        return maxArea;
    }
};