#include <stdio.h>
#include <time.h> /* execution time */

int a, b, memo[10000010], ck[10000010], m, mi;

int f(long long int k)
{
  if(k==1) return 1;
  if(k<10000000)
  {
    if(ck[k]!=0) return memo[k]; /* memoization */
    ck[k] = 1;

    if(k%2==1) return memo[k] = f(3*k+1)+1;
    else return memo[k] = f(k/2)+1;
  }
  else
  {
    if(k%2==1) return f(3*k+1)+1;
    else return f(k/2)+1;
  }
}

int main()
{
  scanf("%d%d", &a, &b);

  double st = clock();

  for(int i=a; i<=b; i++)
  {
    int t = f((long long int)i);
    if(m<t)
    {
      m = t;
      mi = i;
    }
  }

  double et = clock();

  printf("%d %d\n", mi, m);

  printf("execution time : %.3lf(sec)\n", (et-st)/CLOCKS_PER_SEC);

  return 0;
}
