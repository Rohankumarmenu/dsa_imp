
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>umap;
        vector<string>ans;

        for(auto it:words){
          umap[it]++;
        }


   auto cmp=[](const pair<int,string>& a, const pair<int,string>& b ){
    if(a.first==b.first){
        return a.second<b.second;
    }

    return a.first>b.first;
   };

        priority_queue<pair<int,string>,vector<pair<int,string>>,decltype(cmp)>pq(cmp);

        for(auto &i:umap){
            pq.push({i.second, i.first});

            if(pq.size()>k){
                pq.pop();
            }
        }

        while(!pq.empty()){
          ans.push_back(pq.top().second);
          pq.pop();
        }
         reverse(ans.begin(), ans.end());
        return ans;
    }
};