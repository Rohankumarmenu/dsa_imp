
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>umap;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                nums[i] = -1;
            }
        }
int sum=0;
int i=-1;
int maxi=0;
umap[sum]=-1;
    for(i=0;i<nums.size();i++){
     sum=sum+nums[i];
     
     if(umap.find(sum)!=umap.end()){
         maxi =max(maxi,i-umap[sum]);

     }else{
        umap[sum]=i;
     }
    //BYOWN
    }
    return maxi;
    }
};