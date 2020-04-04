N, M = list(map(int, input().split()))
a = list(map(int, input().split()))

s = sum(a)

count = 0
for n in a:
  if n >= s / 4 / M:
    count += 1

print("Yes" if count >= M else "No")
