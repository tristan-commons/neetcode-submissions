class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> operators = {"+", "-", "*", "/"};
        stack<int> s;

        for (int i = 0; i < tokens.size(); i++) {
            string cur = tokens[i];
            if (operators.count(cur)) {
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();

                if (cur == "+") {
                    s.push(op1 + op2);
                } else if (cur == "-") {
                    s.push(op1 - op2);
                } else if (cur == "*") {
                    s.push(op1 * op2);
                } else if (cur == "/") {
                    s.push (op1 / op2);
                }
            }
            else {
                s.push(stoi(cur));
            }
        }

        return s.top();
    }
};
