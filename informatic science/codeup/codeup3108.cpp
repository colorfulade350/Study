#include <stdio.h>
#include <algorithm>
using namespace std;

int N, t;
struct point {
  int c;
  char s[10], v[20];
} d[110];

bool cmp(point a, point b) { return a.c<b.c; }

int main()
{
  scanf("%d", &N);
  for(int i=0; i<N; i++)
  {
    point m;
    scanf(" %s %d %s", m.s, &m.c, m.v);
    if(m.s[0]=='I')
      d[t++] = m;
    else
    {
      int a = 0, b = 0;
      point mt[110];
      while(a!=t)
      {
        if(d[a].c==m.c) a++;
        else mt[b++] = d[a++];
      }
      for(int j=0; j<N; j++)
        d[j] = mt[j];
      t = b;
    }
  }

  sort(d, d+t, cmp);

  int mt;
  for(int i=0; i<5; i++)
  {
    scanf("%d", &mt);
    printf("%d %s\n", d[mt-1].c, d[mt-1].v);
  }

  return 0;
}
