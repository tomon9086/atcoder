N = int(input())
arr = []
for i in range(N):
  arr.append(input())
found = {}

# print(found, arr)

for candidate in arr:
  try:
    found[candidate] += 1
  except KeyError:
    found[candidate] = 1

s = sorted(found.items(), key=lambda n: n[1])
max = s[len(s) - 1][1]
s = list(filter(lambda t: t[1] == max, s))
s = sorted(s, key=lambda c: c[0])

print("\n".join(list(map(lambda t: t[0], s))))
