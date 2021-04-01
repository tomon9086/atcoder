N_str = input()
N = int(N_str)
dig = len(N_str)
count = 0
for i in range(int(dig / 2)):
  zeros = i
  n = int("1" + "".join(list(map(lambda n: "0", range(zeros)))) + "1")
  nd = len(str(n))
  for j in range(min(n - 2, int(N / n))):
    jj = 10 ** (nd - 2)
    hoge = n * (jj + j)
    hoge_str = str(hoge)
    l = len(hoge_str)
    if hoge > N:
      break
    elif hoge_str[0:int(l/2)] == hoge_str[int(l/2):]:
      count += 1 

print(count)
