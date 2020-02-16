s = str(input())

ALPH = ["A", "B", "C"]
count = [0, 0, 0]
seq = [0, 0, 0]

for i in range(3):
	prev = ""
	for c in s:
		if c == ALPH[i]:
			count[i] += 1
			if prev == c:
				seq[i] += 1
		prev = c

# print(count)
	
max_i = 0
for i, n in enumerate(seq):
	if seq[max_i] < n:
		max_i = i

ret = ""
prev = ""
for c in s:
	if c == ALPH[max_i] and prev == c:
		pass
	else:
		ret += c
	prev = c

print(ret)
