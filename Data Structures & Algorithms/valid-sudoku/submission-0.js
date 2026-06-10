class Solution {
    /**
     * @param {character[][]} board
     * @return {boolean}
     */
    isValidSudoku(board) {
        return this.isRowValid(board) && this.isColumnValid(board) && this.isGridValid(board)
    }

    isRowValid(board) {
        for(let i = 0 ; i < board.length ; i ++) {
            let records = {}
            for(let j = 0 ; j < board.length ; j ++) {
                if(board[i][j] === '.') {
                    continue;
                }
                if(records.hasOwnProperty(board[i][j])) {
                    return false;
                }
                else {
                    records[board[i][j]] = 1
                }
            }
        }

        return true;
    }

    isColumnValid(board) {
        for(let i = 0 ; i < board.length ; i ++) {
            let records = {}
            for(let j = 0 ; j < board.length ; j ++) {
                if(board[j][i] === '.') {
                    continue;
                }
                if(records.hasOwnProperty(board[j][i])) {
                    return false;
                }
                else {
                    records[board[j][i]] = 1
                }
            }
        }

        return true;
    }

    isGridValid(board) {
        for (let blockRow = 0; blockRow < 3; blockRow++) {
            for (let blockCol = 0; blockCol < 3; blockCol++) {
                let nums = {};  // Reset for each 3x3 grid
                for (let i = 0; i < 3; i++) {
                    for (let j = 0; j < 3; j++) {
                        let cell = board[blockRow * 3 + i][blockCol * 3 + j];
                        if (cell !== '.') {
                            if (nums.hasOwnProperty(cell)) {
                                return false;
                            }
                            nums[cell] = 1;
                        }
                    }
                }
            }
        }
        return true;
    }
}
