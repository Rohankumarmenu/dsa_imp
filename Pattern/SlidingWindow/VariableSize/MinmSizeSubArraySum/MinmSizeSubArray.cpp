
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int>store;
        int j=0,sum=0;
        int find=INT_MAX;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
      
            while(sum>=target&&j<=i){
            find=min(find,i-j+1);
              sum=sum-nums[j];
              j++;
            }

           
        }
       return find == INT_MAX ? 0 : find;
    }
};