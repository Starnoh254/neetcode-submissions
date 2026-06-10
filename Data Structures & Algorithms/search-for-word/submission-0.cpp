// class Solution {
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         return backtrack(board , word , "");
//     }

//     bool backtrack(
//         vector<vector<char>>& board , 
//         string word , 
//         string currentWord

//     ){
//         if(word == currentWord) {
//             return true;
//         }

//         for(int i = 0; i < board.size() ; i++) {
//             for(int j = 0 ; j < board[i].size(); j++) {
//                 // select the element 
//                 currentWord += board[i][j];

//                 // backtrack and deselect the element 
//                 currentWord.pop_back();
//             }
//         }

//         return false;
//     }
// };




class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        // Loop through the entire board to find the first letter of 'word'
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (backtrack(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool backtrack(vector<vector<char>>& board, string& word, int i, int j, int index) {
        // Base case: If index == word.length(), we found the word
        if (index == word.length()) {
            return true;
        }

        // Check if we are out of bounds OR if the character does not match
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }

        // Temporarily mark the cell as visited
        char temp = board[i][j];
        board[i][j] = '#';

        // Explore all 4 possible directions (up, down, left, right)
        bool found = backtrack(board, word, i + 1, j, index + 1) || 
                     backtrack(board, word, i - 1, j, index + 1) || 
                     backtrack(board, word, i, j + 1, index + 1) || 
                     backtrack(board, word, i, j - 1, index + 1);

        // Restore the cell back to its original state (undo visit)
        board[i][j] = temp;

        return found;
    }
};

