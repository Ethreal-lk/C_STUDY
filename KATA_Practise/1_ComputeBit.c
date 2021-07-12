/*
 * @Author: your name
 * @Date: 2021-07-06 16:04:42
 * @LastEditTime: 2021-07-12 14:18:48
 * @LastEditors: Please set LastEditors
 * @Description:计算给出的数字二进制中1的个数
 * @FilePath: \C\.vscode\KATA_Practise\1_ComputeBit.c
 */
 
 #include <stdio.h>

 #include <math.h>


 unsigned int CountBits(unsigned int  value);

 unsigned int CountBits1(unsigned int  value);

 void pyramid( int n );
 int PrimeSum( int m, int n ) ;
int prime( int p );
int CountDigit( int number, int digit );
 int main ()
 {

   int flag = 0 ;

  flag = prime( 18 );
  if (flag) printf ("yes");
  else  printf("no");  

  PrimeSum(-1, 5);

 }


//好的方法，通过移位来计算
 unsigned int CountBits(unsigned int  value)
 {
   unsigned int count = 0 ;

   for (; value ;value = value >> 1)
    if (value & 1 )
    {
      count ++;
    }
    return count;
 }

 /**
  * @description:自己做的方法 
  * @param {*}
  * @return {*}
  */
unsigned int CountBits1(unsigned int  value)

{
  int count = 0;

  while (value >0 )
  {
    if (value % 2 == 1 )
    {
      count ++;
    }
    value /= 2;
  }
  return count;
}
void pyramid( int n )
{
  int i , j;
  for ( j = 1 ; j <= n; j ++ ){
    for( i = j ; i < n ; i++ ){
      printf(" ");
    }
    for (i = 0 ; i < j ; i++ ) {
      printf("%d ", j);
    }

    printf("\n");

  }
}
int even( int n )
{
  return  n % 2 == 0 ? 1 : 0;
}

int OddSum( int List[], int N )
{
  int i ;
  int sum  = 0;


  for (i = 0 ; i < N ; i++)
  {
    if (List[i] % 2 != 0)
    {
      sum += List[i];
    }
    
  }
  return sum ;
}

double dist( double x1, double y1, double x2, double y2 )
{
  return sqrt( (x2- x1) * (x2 - x1) + (y2 - y1 ) * (y2 - y1 ));
}


int prime( int p )
{ 
  if (p > 2 )
{
  for (int i = 2 ; i < p/2 ; i ++ ) {
    if (p % i == 0)
    {
      return 0;
    } else if(i >= p/2) {
      return 1;
    }
  }
}else if (p == 2) {
  return 1;
}else return 0 ;

return 1;

}
int PrimeSum( int m, int n ) {
  int sum = 0;

  for ( ; m <= n; m++ ){
    if (prime(m))
    {
      sum += m;
    }
    
  }
  return sum ;
}

int CountDigit( int number, int digit ) {


  int num = 0 ;
  int temp ;

  while (number)
  {
    temp = number % 10 ;
    if (temp == digit) 
    {
      num ++;
    } 
    number /= 10;
  }
  return num;
  
}