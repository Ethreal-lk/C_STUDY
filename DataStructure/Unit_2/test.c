/*
 * @Author: foreveryoung 1243288336@qq.com
 * @Date: 2022-08-13 18:05:06
 * @LastEditors: foreveryoung 1243288336@qq.com
 * @LastEditTime: 2022-08-13 18:35:41
 * @FilePath: \undefinede:\opensource\DataStructure\Unit_2\test.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *p = NULL;
    char *q = NULL;

    char str[] = "This is test";
    p = (char *)malloc(10 * sizeof(char));
    q = strcpy(p, str);
    if (q == NULL) {
        printf("strcpy fail");
    }
    printf("%s\n",q);
    printf("strcpy sucess!");
    return 0;
}