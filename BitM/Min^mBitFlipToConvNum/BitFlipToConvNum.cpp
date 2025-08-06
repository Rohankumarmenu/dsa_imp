class Solution {
public:
    int minBitFlips(int start, int goal) {
        int k=start^goal;   // XOR operation to find differing bits
        // The number of bits that are different can be found by counting the number of 1s in the binary representation of k 
        int cnt =0;
        while(k!=0){
            k=k&(k-1);
            cnt++;
        }
        return cnt;
    }
};


