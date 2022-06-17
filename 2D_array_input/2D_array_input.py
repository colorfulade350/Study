d = []
for i in range(19) :
  a = list(map(int, input().split()))
  d.append(a)

n = int(input())
for i in range(n) :
  x, y = input().split()
  x = int(x)-1
  y = int(y)-1
  for j in range(19) :
    if d[j][y]==1 :
      d[j][y] = 0
    else :
      d[j][y] = 1

  for j in range(19) :
    if d[x][j]==1 :
      d[x][j] = 0
    else :
      d[x][j] = 1

for i in range(19) :
  for j in range(19) :
    print(d[i][j], end=" ")
  print("")
