class Solution {
  public:
    bool canJump(vector<int>& nums) {
      if (nums.size()==1) {
        return true;
      }
      int curr=0;
      while (true ) {
        int maxr = curr+nums[curr];
        if (nums[curr] == 0) {
          return false;
        }
        else if(maxr>=nums.size()-1){
          return true;
        }
        else{
          int maxind=curr+1;

          for (int i = curr+2; i <= maxr; i++) {
            if(i + nums[i]>maxind + nums[maxind]){
              maxind = i;
            }
          }
          curr = maxind;
        }
      }
      return true;
    }
};
