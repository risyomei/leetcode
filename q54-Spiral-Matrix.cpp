class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
        int m = matrix.size();
        int n = matrix[0].size();
        int dir = 1; // Right 1, Down 2, Left 3, Up 4
        int x=0,y=0,i;
            
        bool changed = true;
        while( changed ) {
            changed = false;
            if( dir == 1 ) { // Go Right
                for(i = 0; i< n; i++) {
                    if( -100 <= matrix[x][y] && matrix[x][y] <= 100) {
                        answer.push_back(matrix[x][y]);
                        matrix[x][y] = INT_MIN;
                        changed = true;
                        if(y + 1 < n && matrix[x][y + 1] > -1000)
                            y++;
                    } else break;
                }
                if(x + 1 < m &&  matrix[x + 1][y] > -1000)
                    x ++;
                dir = 2;
            } else if( dir == 2 ) { // Go Down
                for(i = 0; i< m; i++ ) {
                    if( -100 <= matrix[x][y] && matrix[x][y] <= 100) {
                        answer.push_back(matrix[x][y]);
                        matrix[x][y] = INT_MIN;
                        changed = true;
                        if(x + 1 < m && matrix[x + 1][y] > -1000)
                            x++;
                    } else break;
                }
                if( y - 1 >= 0 &&  matrix[x][y - 1] > -1000)
                    y --;
                dir = 3;
            } else if( dir == 3 ) { // Go Left
                for(i = 0; i< n; i++ ) {
                    if( -100 <= matrix[x][y] && matrix[x][y] <= 100) {
                        answer.push_back(matrix[x][y]);
                        matrix[x][y] = INT_MIN;
                        changed = true;
                        if(y - 1 >= 0 && matrix[x][y - 1] > -1000)
                            y--;
                    } else break;
                }
                if( x - 1 >= 0 &&  matrix[x - 1][y] > -1000)
                    x --;
                dir = 4;
            } else if( dir == 4 ) { // Go Up {
                
                for(i = 0; i< m; i++ ) {
                    if( -100 <= matrix[x][y] && matrix[x][y] <= 100) {
                        answer.push_back(matrix[x][y]);
                        matrix[x][y] = INT_MIN;
                        changed = true;
                        if(x - 1 >= 0 && matrix[x - 1][y] > -1000)
                            x--;
                    } else break;
                }
                if( y + 1 < n &&  matrix[x][y + 1] > -1000)
                    y ++;
                dir = 1;
            }
        }

        return answer;
    }
};