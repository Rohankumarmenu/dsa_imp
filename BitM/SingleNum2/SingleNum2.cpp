
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){
            int cntO =0;
            int cntE=0;
            for(int j=0;j<nums.size();j++){
                if((1<<i)&nums[j]){
                    cntO++;
                }
                else{
                    cntE++;
                }
            }
            if(cntO%3==1){
              ans=ans | (1<<i);
            }
        }
        return ans;
    }
};