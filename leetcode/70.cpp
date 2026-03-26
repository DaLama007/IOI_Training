class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        int sc[n];
        sc[0] = 1;
        sc[1] = 2;

        for (int i = 2; i < n; i++) {
          sc[i] = sc[i-1] + sc[i-2];
        }

        return sc[n-1];
    }
};
