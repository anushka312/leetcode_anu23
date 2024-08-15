// complexity : Time: recursive: O(log n ) iterative: O(N) Space: O(1)

class Solution {
private:
    long long powerFunction(long long base, long long power, const long long MOD){
        base = base % MOD;
        long long result = 1;
        while(power> 0){
            if(power % 2 == 1){
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            power /= 2;
        }
        return result;
    }
public:
    int countGoodNumbers(long long n) {
        if(n == 1) return 5;
        const long long MOD = 1000000007;
        long long result;
        
        long long odd = n / 2;
        long long even = n - odd;
            
        result = (powerFunction(4, odd, MOD) * powerFunction(5 ,even, MOD)) % MOD;
        return (int)result;
    }
};
// long long powerFunction(long long base, long long power, const long long MOD){
//         base = base % MOD;
//         power = power % MOD;
//         long long result = 1;
//         if(power == 1) return base;
//         if(power % 2 == 0){
//             result = (powerFunction((base * base)%MOD, power / 2, MOD))%MOD;
//         }else if(power % 2 == 1){
//             result = (base * powerFunction(base, power - 1, MOD))%MOD;
//         }
//         return result;
//     }