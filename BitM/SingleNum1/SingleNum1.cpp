
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int XOR=0;  //Ex=nums= [4,1,2,1,2]
        for(auto it :nums){
            XOR=XOR^it;
        }
        return XOR;
    }
};


        //XOR=4^1^2^1^2
        //XOR=4^(1^1)^(2^2)
        //XOR=4^0^0
        //XOR=4