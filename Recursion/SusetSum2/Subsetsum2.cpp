class Solution {
    public:
        void recurse(int index, vector<vector<int>>&ans, vector<int>&store, vector<int>&nums) {
            int n = nums.size();
             ans.push_back(store);
            for (int i = index; i < n; i++) {
               
                if(i!=index && nums[i]==nums[i-1]){
                    continue;
                }
                store.push_back(nums[i]);
                recurse(i + 1, ans, store, nums);
                store.pop_back();
            }
        }
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         sort(nums.begin(),nums.end());
            vector<vector<int>> ans;
            vector<int> store;
            recurse(0, ans, store, nums);
            return ans;
        }
    };