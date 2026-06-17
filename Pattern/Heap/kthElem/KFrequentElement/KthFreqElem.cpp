
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        //priority_queue<int,vector<int>,greater<int>>pq;
        vector<int>ans;
        unordered_map<int,int>umap;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq2;
        for(auto& it:umap){
           pq2.push({it.second,it.first});

           if(pq2.size()>k){
            pq2.pop();
           }
        }
        int copyk=k;
        // while(copyk!=0 && !pq2.empty()){
        //     ans.push_back(pq2.top().second);
        //     pq2.pop();
        //     copyk--;
        // }

        while(!pq2.empty()){
            ans.push_back(pq2.top().second);
            pq2.pop();
        }
     return ans;
    }
};