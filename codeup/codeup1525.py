def safe(a, b) :
  return ((0<=a and a<10)and(0<=b and b<10))

ck = [[0 for _ in range(20)] for _ in range(20)]
d = [[0 for _ in range(20)] for _ in range(20)]
for i in range(10) :
  a = list(map(int, input().split()))
  for j in range(10) :
    d[i][j] = a[j]

for i in range(10) :
  for j in range(10) :
    if d[i][j] >= 1 :
     # print(d[i][j])
      t = d[i][j]
      for k in range(t+1) :
        if(d[i][j+k]==-1)or(not safe(i, j+k)) :
          break
        else :
          ck[i][j+k] = -2
          
      for k in range(t+1) :
        if(d[i][j-k]==-1)or(not safe(i, j-k)) :
          break
        else :
          ck[i][j-k] = -2

      for k in range(t+1) :
        if(d[i+k][j]==-1)or(not safe(i+k, j)) :
          break
        else :
          ck[i+k][j] = -2
          
      for k in range(t+1) :
        if(d[i-k][j]==-1)or(not safe(i-k, j)) :
          break
        else :
          ck[i-k][j] = -2

for i in range(10) :
  for j in range(10) :
    if(d[i][j]==-1) :
      ck[i][j] = d[i][j]

N = int(input())
ans = [0 for _ in range(10)]
for i in range(N) :
  x, y = map(int, input().split())
  x, y = x-1, y-1
  if(ck[x][y]==-2) :
    ans[i] = 1
  else :
    ck[x][y] = (i+1)

for i in range(10) :
  for j in range(10) :
    print(ck[i][j], end=" ")
  print("")
print("Character Information")
for i in range(N) :
  print("player", i+1, end=" ")
  if(ans[i]==1) :
    print("dead")
  else :
    print("survive")
