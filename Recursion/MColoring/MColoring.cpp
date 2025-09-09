
class Solution {
  public:
  
  bool check(int i,int node,int v,vector<int>&color,vector<vector<int>>&adj){
 
      for(auto it:adj[node]){
          if(color[it]==i){
               return false;
          }
      }
    return true;
          
  }
  
  bool recur(int node,int v, vector<vector<int>>&adj,vector<int>&color,int m){
       if(node == v ){
           return true;
       }
       
       for(int i =1;i<=m;i++){
           if(check(i,node,v,color,adj)){
               color[node]=i;
               if(recur(node+1,v, adj,color,m)){
                   return true;
               }
               color[node]=0;
               
           }
       }
       return false;
  }
  
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        
        vector<vector<int>>adj(v);
        
        for(auto it:edges){
            int k1=it[0];
            int k2=it[1];
            adj[k1].push_back(k2);
            adj[k2].push_back(k1);
            
        }
        vector<int>color(v,0);
        
        bool k=recur(0,v,adj,color,m);
        return k;
        
    }
};