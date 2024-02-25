N = input()
arr = list(map(int, input().split()))
flag = True
for n in arr:
  if n % 2 == 0 and not (n % 3 * n % 5 == 0):
    print("DENIED")
    flag = False
    break
    
if flag:
  print("APPROVED")
