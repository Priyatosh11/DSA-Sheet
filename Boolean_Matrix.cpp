class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       int row = matrix.size();
        int col = matrix[0].size();
        
        bool arr_row[row]; fill(arr_row, arr_row+row, false);
        bool arr_col[col]; fill(arr_col, arr_col+col, false);
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++){
                if(matrix[i][j] == 0){
                    arr_row[i] = true;
                    arr_col[j] = true;
                }
            }
        }
        
        for(int i=0;i<row;i++){
            if(arr_row[i]){
                for(int j=0;j<col;j++){
                    matrix[i][j]= 0;
                }
            }
        }
        
        for(int i=0;i<col;i++){
            if(arr_col[i]){
                for(int j=0;j<row;j++){
                    matrix[j][i] = 0;
                }
            }
        }  
    }
};
