class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int flatSize = matrix.size() * matrix[0].size();
        
        int l = 0;
        int r = flatSize - 1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arrToMat(matrix, mid) == target) {
                return true;
            }

            if (target > arrToMat(matrix, mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return false;
    }

    int arrToMat(vector<vector<int>>& matrix, int i) {
        int row = i / matrix[0].size();;
        int col = i - (row * matrix[0].size());
        return matrix[row][col];
    }
};
