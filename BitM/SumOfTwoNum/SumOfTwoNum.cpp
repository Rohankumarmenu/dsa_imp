class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            int takeCarry=a&b;
            a=a^b;
            b=(takeCarry<<1);
        }
        return a;
    }
};