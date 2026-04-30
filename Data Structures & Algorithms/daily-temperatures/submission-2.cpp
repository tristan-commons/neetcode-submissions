class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> waiting;
        vector<int> result(temperatures.size());

        for (int i = 0; i < temperatures.size(); i++) {
            while (!waiting.empty() && temperatures[i] > temperatures[waiting.top()]) {
                result[waiting.top()] = i - waiting.top();
                waiting.pop();
            }

            waiting.push(i);
        }

        return result;
    }
};
