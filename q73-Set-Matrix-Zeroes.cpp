/*

Using the first row and first column to mark the rows and columns that need to be reset to zero.

*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();      
        
        bool v_zero = false;
        bool h_zero = false;
        
        // Handling for the first row, column
        for(int i=0; i<m; i++){
            if(matrix[i][0] == 0) {
                v_zero = true;
                break;
            }
        }
        for(int j=0; j<n; j++){
            if(matrix[0][j] == 0) {
                h_zero = true;
                break;
            }
        }
        
        // Marking Zeros (execept for 1 row, 1 column)
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // Setting Zeros for Sub Matrix
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {                
                if( matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;   
                }
            }
        }
        
        // Setting Zeros for first Row and Column
        for(int i=0; i<m && v_zero; i++) {
            matrix[i][0] = 0;
        }
        
        for(int j=0; j<n && h_zero; j++) {
            matrix[0][j] = 0;
        }
    }
};