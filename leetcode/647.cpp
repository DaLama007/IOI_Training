class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        int l = s.length();
        // dp table so that the row num indicates the starting pos 
        // and the column num indicates the end position of the curr substring
        vector<vector<bool>> dp(l, vector<bool>(l, false));
        
        //set cases for length = 1 to true
        for (int i = 0; i < l; i++) {
          dp[i][i] = true;
          count++;
        }

        for (int i = 0; i < l-1; i++) {
          if (s[i] == s[i+1]) {
            dp[i][i+1] = true;
            count++;
          }
        }
        int j;
        for (int k = 2; k < l; k++) {
          for (int i = 0; i < l-k; i++) {
            j = i+k;
            
            if (j >= l) {
              break;
            }
            if (s[i] == s[j] && dp[i+1][j-1]) {
              dp[i][j] = true;
              count++;
            }
          }
        }
        return count;

    }
};
