//Backtracking(3)
class Solution {
public:

vector<vector<int>>ans;

void recurse(vector<int>& nums,int ind){
   if(nums.size()==ind){
    ans.push_back(nums);
    return;
   }
   
     
   for(int i=ind;i<nums.size();i++){
    swap(nums[ind],nums[i]);
    recurse(nums,ind+1);
    swap(nums[ind],nums[i]);
   }

}

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>store;
        recurse(nums,0);
            return ans;
    }
};
