class Solution {
public:
    int dp[301][301], power[301], mod = 1e9 + 7;
    
    int f(int n, int n_cur, int x) {
        if(!n)
            return 1;

        if(n_cur > 300 || power[n_cur] > n)
            return 0;
        
        if(~dp[n][n_cur])
            return dp[n][n_cur];

        int take = f(n - power[n_cur], n_cur + 1, x);
        int leave = f(n, n_cur + 1, x);

        return dp[n][n_cur] = (take + leave) % mod;
    }

    int pow_mod(long long base, int exp) {
        int res = 1;

        while(exp) {
            if(exp & 1)
                res = (long long)(res * base) % mod;

            base = (base * base) % mod;
            exp >>= 1;
        }

        return res;
    }
    
    int numberOfWays(int n, int x) {
        memset(dp, -1, sizeof dp);

        for(int i = 1; i < 301; ++i)
            power[i] = pow_mod(i, x);
        
        return f(n, 1, x);
    }
};