def isLunlun(n):
  s = str(n)
  prev = ""
  for c in s:
    if prev == "" or abs(int(c) - int(prev)) <= 1:
      pass
    else:
      return False
    prev = c
  return True


def lunlunN(k):
  n = 0
  count = 0
  i = 1
  while True:
    if isLunlun(i):
      n = i
      count += 1
    i += 1
    if count >= k:
      return n

K = int(input())
print(lunlunN(K))
