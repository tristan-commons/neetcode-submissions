class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return checkRows(board) && checkColumns(board) && checkSquares(board);
    }

    bool checkRows(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> values;
            for (int j = 0; j < 9; j++) {
                char val = board[i][j];
                
                if (val == '.') {
                    continue;
                }

                if (values.count(val)) {
                    return false;
                }

                values.insert(val);
            }
        }

        return true;
    }

    bool checkColumns(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            unordered_set<char> values;

            for (int j = 0; j < 9; j++) {
                char val = board[j][i];
                if (val == '.') {
                    continue;
                }
                if (values.count(val)) {
                    return false;
                }

                values.insert(val);
            }
        }

        return true;
    }

    bool checkSquares(vector<vector<char>>& board) {
         for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {

                unordered_set<char> values;

                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        char val = board[k][l];
                        if (val == '.') {
                            continue;
                        }
                        if (values.count(val)) {
                            return false;
                        }

                        values.insert(val);
                    }
                }
            }
         }
         return true;
    }
};
