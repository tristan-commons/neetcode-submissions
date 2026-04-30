class Solution {
    /**
     * @param {character[][]} board
     * @return {boolean}
     */
    isValidSudoku(board) {
        let rows = [];
        let columns = [];
        let boxes = [];

        for (let i = 0; i < board.length; i++) {
            for (let j = 0; j < board[i].length; j++) {
                if (i === 0) {
                    columns[j] = new Set();
                }
                if (j === 0) {
                    rows[i] = new Set();
                }

                const boxIdx = Math.floor(j/3) + (3 * Math.floor(i/3));
                if (i % 3 === 0 && j % 3 === 0) {
                    boxes[boxIdx] = new Set();
                }

                const char = board[i][j];;

                if (char === '.') {
                    continue;
                }
                if (!(char >= '0' && char <= '9')) {
                    return false;
                }

                if (rows[i].has(char)) {
                    return false;
                }
                if (columns[j].has(char)) {
                    return false;
                }
                if (boxes[boxIdx].has(char)) {
                    return false;
                }

                rows[i].add(char);
                columns[j].add(char);
                boxes[boxIdx].add(char);
            }
        }

        return true;
    }
}
