class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // for rows

        for (int i = 0; i < 9; i++) {
            set<char>st;
            for (int j = 0; j < 9; j++) {
                char item = board[i][j];
                if (st.find(item) != st.end())
                    return false;
                else if (item != '.')
                    st.insert(item);
            }
        }

        // for cols
        for (int i = 0; i < 9; i++) {
            set<char>st;
            for (int j = 0; j < 9; j++) {
                char item = board[j][i];
                if (st.find(item) != st.end())
                    return false;
                else if (item != '.')
                    st.insert(item);
            }
        }

        // for boxes

        vector<pair<int, int>> starts = {
            {0, 0}, {0, 3}, {0, 6},
            {3, 0}, {3, 3}, {3, 6},
            {6, 0}, {6, 3}, {6, 6}
        };

                for(auto it : starts){
                    int row = it.first;
                    int col = it.second;
                    set<char>st;
                    for(int i = row; i < row +3; i++){
                        
                        for(int j = col; j < col + 3; j++){
                            char item = board[i][j]; 
                            if(st.find(item) != st.end())return false;
                            else if(item != '.')st.insert(item);
                        }
                    }
                }

                return true;
    }
};
