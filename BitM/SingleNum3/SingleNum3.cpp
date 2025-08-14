
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
     long long XOR=0;
     for(int i=0;i<nums.size();i++){
       XOR=XOR^nums[i];
     }   
     long long rightmost=(XOR & XOR-1) ^ XOR;
     long long b1=0,b2=0;
     for(int i=0;i<nums.size();i++){
        if(nums[i] & rightmost){
            b1=b1^nums[i];
        }
        else{
            b2=b2^nums[i];
        }
     }
     return {int(b1),int(b2)};
    }
};