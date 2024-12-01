class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> indices;
        indices.push(-1); 
        int maxLength = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                indices.push(i);
            } else {
                indices.pop();
                if (indices.empty()) {
                    indices.push(i);
                } else {
                    maxLength = max(maxLength, i - indices.top());
                }
            }
        }
        return maxLength;
    }
};
