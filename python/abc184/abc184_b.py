N, X = list(map(int, input().split()))
S = input()

point = X

for c in S:
  if c == "o":
    point += 1
  elif c == "x" and point > 0:
    point -= 1
  else:
    pass

print(point)
