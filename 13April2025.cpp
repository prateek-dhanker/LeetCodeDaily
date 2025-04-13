// 1922. Count Good Numbers
class Solution {
    public:
        const int MOD = 1e9+7;
    
        long long ppow(long long a,long long expo){
            long long res = 1;
    
            while(expo){
                if(expo&1)
                    res = (res*a)%MOD;
                
                a = (a*a)%MOD;
                expo = expo>>1;
            }
    
            return res;
        }
        int countGoodNumbers(long long n) {
            long long cntEven = n/2, cntOdd = n/2;
    
            if(n&1)
                cntEven++;
            return (1LL*ppow(5,cntEven)*ppow(4,cntOdd))%MOD;
        }
    };