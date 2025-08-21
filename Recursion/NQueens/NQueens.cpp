
class Solution {
public:

bool blackbox(int row,int col,vector<string>ans,int n){
 
int duprow=row;
int dupcol=col;

   while(row>=0 && col>=0){
      if(ans[row][col]=='Q'){
       return false;
      }
      row--;
      col--;
   }


    row=duprow;
    col=dupcol;
    while(col>=0){
     if(ans[row][col]=='Q'){
      return false;
     }
     col--;
  }


    row=duprow;
    col=dupcol;
     while(col>=0 && row<n){
        if(ans[row][col]=='Q'){
         return false;
       }
       col--;
       row++;
    }
   return true;
}

  void solveit(int n,int col, vector<string>&ans,vector<vector<string>>&pk){
    
    if(col==n){
      pk.push_back(ans);
      return;
    }
    for(int j=0;j<n;j++){

      if(blackbox(j,col,ans,n)){
        ans[j][col]='Q';
        solveit(n,col+1,ans,pk);
        ans[j][col]='.';
      }
    }
    

  }
  

    vector<vector<string>> solveNQueens(int n) {
        vector<string>ans(n);
        vector<vector<string>>pk;
        string take(n,'.');
        for(int i=0;i<n;i++){
          ans[i]=take; 
        }
 
       solveit(n,0,ans,pk);
        return pk;
    }
};