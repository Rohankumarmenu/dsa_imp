
class Solution {
  public:
    // Function to find a solved Sudoku.
    
    bool check(vector<vector<int>> &mat,int row,int col,char c){
        for(int k=0;k<9;k++){
            if(mat[k][col]==c){
                return false;
            }
            if(mat[row][k]==c){
                return false;
            }
            if(mat[3*(row/3)+k/3][3*(col/3)+k%3]==c){
                return false;
            }
            
        }
       return true;
    }
    
  bool solve(vector<vector<int>> &mat){
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                  for(char c=1;c<=9;c++){
                  if(check(mat,i,j,c)){
                      mat[i][j]=c;
                      
                      if(solve(mat)==true){
                          return true;
                      }
                      else{
                        mat[i][j]=0;  
                      }
                 }
              }  
              return false;
                }
                
            }
        }
        return true;
    }
    
    
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        solve(mat);
        
    }
};