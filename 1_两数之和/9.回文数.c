/*
 * @Author: your name
 * @Date: 2021-07-08 09:15:31
 * @LastEditTime: 2021-07-08 13:08:12
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C\LeetcodePractice\1_两数之和\9.回文数.c
 */
/*
 * @lc app=leetcode.cn id=9 lang=c
 *
 * [9] 回文数
 */

// @lc code=start


bool isPalindrome(int x){

  int  p = 1;
  if (x < 0 )
  {
    return 0;
  }
while (x / p >= 10 ) 
{
  p = p * 10;
}

/**
 * @description: 依次比较数据中的头尾两个数字是否相等 
 * @param {*}
 * @return {*}
 */
while (x > 0)
{
  int left = x / p;
  int right = x %10;
  if (left != right )
  {
    return 0 ;
  }
  x = (x % p ) / 10;  //取得去掉首尾之后的数据
  p /= 100;           //减去头尾两个数字，除数要除以100
}
return 1;
}
//测试vscode中上传代码到git
// @lc code=end

