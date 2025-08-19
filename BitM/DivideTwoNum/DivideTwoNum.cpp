
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ans = 0;
        bool sign = true;
        if (dividend == divisor) {
            return 1;
        }
        if(dividend ==INT_MIN && divisor==-1){
            return INT_MAX;
        }
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
            sign = false;
        }
        long long num = llabs((long long)dividend), d = llabs((long long)divisor);

        while (num >= d) {
            int cnt = 0;
         while(num>=(d<<(cnt+1))){
                cnt++;
         }
                ans = ans + (1LL << cnt);
                num = num - (d * (1LL << cnt));
     
        }
        // if (ans > INT_MAX) {
        //     return INT_MAX;
        // }
        // if (ans == 1<<31 && sign) {
        //     return INT_MIN;
        // }
        if (ans > INT_MAX) {
            return sign ? INT_MAX : INT_MIN;
        }
       return sign ? (int)ans : -(int)ans;
    }
};