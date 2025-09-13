
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> k;
    vector<vector<int>> dir{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int m,n;
    bool find(int s, vector<vector<char>>& board, string& word, int x, int y) {

        if (s == word.size()) {
            return true;
        }
        if (x < 0 || y < 0 || x >= m || y >= n || board[x][y] != word[s]) {
            return false;
        }

        char temp = board[x][y];
        board[x][y] = '$';

        for (auto &it : dir) {
            int newx = x + it[0];
            int newy = y + it[1];
            if( find (s + 1, board, word, newx, newy) ){
                return true;
            }
        }
        board[x][y]=temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n= board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && find(0, board, word, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};