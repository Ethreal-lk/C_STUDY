/*
 * @Author: your name
 * @Date: 2021-07-07 08:58:09
 * @LastEditTime: 2021-07-07 10:02:00
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \C\.vscode\KATA_Practise\3_test.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *dna_strand(const char *dna);
char *dna_strand1(const char *dna);
int main ()
{
   const char * pTest = " ATTGC" ;
    char * ptr ;

    ptr = dna_strand (pTest);

    printf("%s", ptr);
}

//第一种方法
char *dna_strand(const  char *dna)
{
    char *result = strdup(dna); //将字符串拷贝到新建的点上；

    /**
     * @description: 创建了一个新的指向result的指针，将指针中的内容按照要求互换； 
     * @param {char} *cp
     * @return {*}
     */    
    for (char *cp = result; *cp; ++cp)
    {
        switch (*cp)
        {
        case 'A': *cp = 'T'; break;
        case 'C': *cp = 'G'; break;
        case 'G': *cp = 'C'; break;
        case 'T': *cp = 'A'; break;
        }
    }
    return result;
}

//第二种方法 ： 通过过函数分配一定的空间存放数据
char *dna_strand1(const char *dna)
{
    char *return_dna = calloc( strlen(dna) + 1, sizeof(char) ); // calloc 函数
    for(int i = 0; i < strlen(dna); i++){
        switch(dna[i]){
            case 'A' :  return_dna[i] = 'T'; break;
            case 'T' :  return_dna[i] = 'A'; break;
            case 'G' :  return_dna[i] = 'C'; break;
            case 'C' :  return_dna[i] = 'G'; break;
        }
    }
    return return_dna;
}