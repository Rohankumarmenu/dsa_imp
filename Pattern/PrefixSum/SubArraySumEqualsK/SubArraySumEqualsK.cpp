class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        unordered_map<int,int>umap;
        int sum=0;
        for(int i=0;i<n;i++){
          sum+=nums[i];
          if(sum==k){
            cnt++;
          }

          if(umap.find(sum-k)!=umap.end()){
             cnt+=umap[sum-k];
          }

          if(umap.find(sum)!=umap.end()){
             umap[sum]++;
          }else{
          umap[sum]=1;
         }
          

        }

        return cnt;
    }
};