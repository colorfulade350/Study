from vpython import *

scene.title = "<b>Author : 31305 김서현</b>"

N = 243 # try else : 3, 9, 27, 81, 243, 749

def f(x, y, h, w) :
  a, b = int(h//3), int(w//3)
  if (h*w)==1 :
    return
  for i in range(x+a, x+a*2) :
    for j in range(y+b, y+b*2) :
      box(pos=vector(i*45-20, j*45-20, 0), size=vector(60, 60, 1), color=color.yellow)
  f(x, y, a, b)
  f(x, y+b, a, b)
  f(x, y+b*2, a, b)
  f(x+a, y, a, b)
  f(x+a, y+b*2, a, b)
  f(x+a*2, y, a, b)
  f(x+a*2, y+b, a, b)
  f(x+a*2, y+b*2, a, b)

f(0, 0, N, N)
