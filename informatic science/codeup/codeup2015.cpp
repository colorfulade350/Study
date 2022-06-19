#include <cstdio>

int d[20], ck[20]; //F,O,R,T,Y,E,N,S,I,X
bool flag;

void f(int k)
{
  if(flag) return;
  if(k==10)
  {
    int a = d[0]*10000+d[1]*1000+d[2]*100+d[3]*10+d[4];
    int b = d[3]*100 + d[5]*10 + d[6];
    int c = d[7]*10000+d[8]*1000+d[9]*100+d[3]*10+d[4];
    if((a+2*b)==c)
    {
      printf("%d+%d+%d=%d\n", a, b, b, c);
      flag = 1;
    }
    return;
  }

  for(int i=0; i<=9; i++)
  {
    if((k==0 || k==3 || k==7)&&(i==0)) continue;
    if(ck[i]==0)
    {
      ck[i] = 1; d[k] = i;
      f(k+1);
      ck[i] = 0; d[k] = 0;
    }
  }
}

int main()
{
  f(0);

  return 0;
}
