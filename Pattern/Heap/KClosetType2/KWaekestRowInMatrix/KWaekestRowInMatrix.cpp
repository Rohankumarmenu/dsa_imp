class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>pq2;
        priority_queue<pair<int,int>> pq;

        for (int i = 0; i < mat.size(); i++) {
            int cnt=0;
            for (int j = 0; j < mat[i].size(); j++) {
                  if(mat[i][j]==1){
                    cnt++;
                  }
                  else{
                    break;
                  }
                    
            }
            pq.push({cnt,i});
            if (pq.size() > k) {
                pq.pop();
            }
        }

    vector<int>ans;
        while(!pq.empty()){
         ans.push_back(pq.top().second);
         pq.pop();
        }
     reverse(ans.begin(),ans.end());
        return ans;
    }
};


//                                                 OR


class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> pq;

        for (int i = 0; i < mat.size(); i++) {
            int cnt=0;
            for (int j = 0; j < mat[i].size(); j++) {
                  if(mat[i][j]==1){
                    cnt++;
                  }
                  else{
                    break;
                  }
                    
            }
            pq.push({cnt,i});
            if (pq.size() > k) {
                pq.pop();
            }
        }

    vector<int>ans(k);

    for(int i=k-1;i>=0;i--){
        ans[i]=pq.top().second;
        pq.pop();
    }
        return ans;
    }
};