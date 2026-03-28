class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.length(),vector<bool>(s.length(),false));
        string longestPalindrome = s.substr(0,1);
        int palLength = 0;

        // for pals with length 1
        for (int i = 0; i < s.length(); i++) {
          dp[i][i] = true;
        }
        
        // for invalid lengths so l < 1
        for (int i = 0; i < s.length(); i++) {
           for (int j = 0; j < i; j++) {
            dp[i][j] = false;
          }
        }
        
        // for pals with length 2 since they do not depend on any previous computation 
        for (int i = 0; i < s.length(); i++) {
          if (s[i]==s[i+1]) {
            dp[i][i+1] = true;
            longestPalindrome = s.substr(i,2);
            palLength = 2;
          }
        }

        //for everything with a length over 2
        int j;
        for (int k = 2; k < s.length(); k++) {
          for (int i = 0; i < s.length()-k; i++) {
            j = i+k;
            if(j>= s.length()) break;

            //check curr case and check old computation
            if (s[j] == s[i] && dp[i+1][j-1]==true) {
              dp[i][j] = true;
              int cl = j-i+1;
              if (cl>palLength) {
                longestPalindrome = s.substr(i,cl);
                palLength = cl;
              }
            }
          }
        }
        return longestPalindrome;
    }
};
