class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftMax(n, -1);
        vector<int> rightMax(n, n);
        stack<int> s;

        // Compute max 
        for (int i = 0; i < n; i++) {
            while (!s.empty() && heights[i] <= heights[s.top()]) {
                s.pop();
            }
            if (!s.empty()) {
                leftMax[i] = s.top();
            }
            s.push(i);
        }

        while (!s.empty()) s.pop();

        for (int i = n - 1; i >=0; i--) {
            while (!s.empty() && heights[i] <= heights[s.top()]) {
                s.pop();
            }
            if (!s.empty()) {
                rightMax[i] = s.top();
            }
            s.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            leftMax[i] += 1;
            rightMax[i] -= 1;
            int area = heights[i] * (rightMax[i] - leftMax[i] + 1);
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }

};