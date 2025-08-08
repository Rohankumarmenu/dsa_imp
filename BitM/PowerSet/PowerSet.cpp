
class Solution {
public:
vector<vector<int>>ans;
vector<int>kk;
vector<int>gk;
    vector<int>findList(string binary,vector<int>nums) {
        kk.clear();
      for(int i=binary.size()-1;i>=0;i--){
        if(binary[i]=='0'){
            continue;
        }
        else{
         kk.push_back(nums[binary.size()-i-1]);
        }
      }
  return kk;
    }
    string toFixedLengthBinary(int num, int length) {
        string binary;
        for (int i = length - 1; i >= 0; --i) {
            binary += (num & (1LL << i)) ? '1' : '0';
        }
        return binary;
    }
    vector<vector<int>> subsets(vector<int>& nums) {

        int n = nums.size();
        int prod = 1<<n;
        // for (int i = 0; i < n; i++) {
        //     prod = prod * 2;
        // }

        for (int i = 0; i < prod; i++) {
            string binary = toFixedLengthBinary(i, prod);
            gk= findList(binary,nums);
            ans.push_back(gk);
        }

        return ans;
    }
};

//Few test cases to validate the solution ,it will fail some time;
