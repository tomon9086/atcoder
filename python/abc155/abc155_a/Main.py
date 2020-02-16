arr = list(map(int, input().split()))
found = []
for n in arr:
  flag = True
  for f in found:
    if n == f:
      flag = False
  if flag:
    found.append(n)

print("Yes" if len(found) == 2 else "No")
