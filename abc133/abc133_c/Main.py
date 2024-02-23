L, R = map(int, input().split())
# min = float("inf")
# for i in range(L, R + 1):
# 	for j in range(i + 1, R + 1):
# 		mod = ((i % 2019) * (j % 2019)) % 2019
# 		if min > mod:
# 			min = mod

# 2019 = 3 * 673

if R - L >= 2019:
	print(0)
else:
	R %= 2019
	L %= 2019
	if L > R:
		R += 2019
	min = float("inf")
	for i in range(L, R + 1):
		for j in range(i + 1, R + 1):
			mod = ((i % 2019) * (j % 2019)) % 2019
			if min > mod:
				min = mod
	print(min)

# 2020 2040 -> 1 21
# 2010 2030 -> 2010 11
