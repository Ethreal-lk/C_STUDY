/*
 * @Author: your name
 * @Date: 2021-07-07 16:12:33
 * @LastEditTime: 2021-07-08 16:06:00
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C\LeetcodePractice\1_两数之和\1.两数之和.c
 */
/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){

  int *ret ;

  for (int  i = 0; i < numsSize -1 ; i++)
  {
    for (int  j = i + 1; j < numsSize ; j++)
    {
      if (nums[i] + nums[j] == target  )
      {
        int *ret = (int * )malloc(sizeof(int) * 2);
        ret[0] = i;
        ret[1] = j;
        *returnSize = 2;
        return ret;

      }
      
    }
    
  }
  *returnSize = 0;
  return NULL;
  

}
// @lc code=end

