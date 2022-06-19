#include <stdio.h>
#include <time.h> /* execution time */
#include <stack>
#include <algorithm> /* swap */
using namespace std;

int a, b, memo[10000010], m, mt, cnt;

int main()
{
  scanf("%d%d", &a, &b);
  if(a>b) swap(a, b);

  double st = clock();

  for(int i=a; i<=b; i++)
  {
    long long int k = (long long int)i;
    stack<long long int> S;
    while(k!=1)
    {
      if(k<10000000 && memo[k]!=0)
      {
        cnt = memo[k];
        break;
      }
      S.push(k);
      if(k%2==1) k = 3*k+1;
      else k = k/2;
    }

    while(!S.empty())
    {
      if(S.empty()) break;
      cnt += 1;
      if(S.top()<10000000)
      {
        memo[S.top()] = cnt;
      }
      S.pop();
    }

    if(mt<cnt+1)
    {
      mt = cnt+1;
      m = (int)i;
    }
    cnt = 0;
  }

  double et = clock();

  printf("%d %d\n", m, mt);

  printf("execution time : %.3lf(sec)\n", (et-st)/CLOCKS_PER_SEC);

  return 0;
}
