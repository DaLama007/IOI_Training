class Solution {
  public:
    bool searchforString(string s, vector<string>& wordDict){
      for (int k = 0; k < wordDict.size(); k++) {
        if(s  == wordDict[k]){
          return true;
        }
      }
      return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
      int sl = s.length();
      vector<bool> dp(sl, false);
      for (int i = 0; i < sl; i++) {
        string cs = s[0,i];
        for (int k = 0; k < wordDict.size(); k++) {
          if(cs == wordDict[k]){
            dp[i] = true;
            break;
          }
        }
        if (dp[i] == false) {
          for (int j= i-1 ; j >= 0; j++) {
            if (dp[j]== true) {
              if(searchforString(s[i,j],wordDict)){
                dp[i] = true;
              }
            }
          }
        }
      }
      return dp[sl];
    }
};
