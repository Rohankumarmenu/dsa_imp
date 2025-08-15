// User function Template for C++

class Solution {
  public:
    int find(int nums){ // Function to find XOR of all numbers from 0 to n
        // using the property that XOR from 0 to n can be found
        if(nums%4==1){
            return 1;
        }
        else if(nums%4==2){
            return nums+1;
        }
        else if(nums%4==3){
            return 0;
        }
        else{
            return nums;
        }
    }
    
    int findXOR(int l, int r) {
      // Function to find XOR of all numbers from l to r
        // using the property that XOR from 0 to n can be found
        // using the pattern based on n % 4
        // and then using the property that XOR from l to r
        // can be found as XOR(0 to r) ^ XOR(0 to l-1)
        
        if(l==r){
            return l;
        }
        // If l is greater than r, we can return 0
       return find(l-1)^find(r);
        
    }
};