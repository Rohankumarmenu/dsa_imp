class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         //priority_queue<int>pq;
         priority_queue<pair<int,int>> pq;
    //    unordered_map<int,int>umap;
    // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq2;


        for(int i=0;i<points.size();i++){
            int numSquare1=points[i][0]*points[i][0];
            int numSquare2=points[i][1]*points[i][1];
            int makeSquareRoot=(numSquare1+numSquare2);

            pq.push({makeSquareRoot,i});
            if(pq.size()>k){
                pq.pop();
            }
        }
      vector<vector<int>>ans;
      while(!pq.empty()){
        int index=pq.top().second;
        ans.push_back(points[index]);
        pq.pop();
      }
      return ans;
    }
};



