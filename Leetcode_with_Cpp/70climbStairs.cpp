class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)
            return n;
        int num1 = 1;
        int num2 = 2;
        int numN = 0;
        for(int i = 2; i < n; i++) {
            numN = num1 + num2;
            num1 = num2;
            num2 = numN;
        }
        return numN;
    }
};

class Solution {
public:
    int climbStairs(int n) {

        vector<int> memo(n+1, -1);
        memo[0] = 1;
        memo[1] = 2;
        
        for(int i = 2; i <= n; i++) 
            memo[i] = memo[i-1] + memo[i-2];

        return memo[n];
    }
};