from math import sqrt
from functools import reduce

def dist(l1, l2):
	if len(l1) != len(l2):
		return False
	sqr_diff = []
	for i in range(len(l1)):
		sqr_diff.append((l1[i] - l2[i]) * (l1[i] - l2[i]))
	return sqrt(reduce(lambda p, c: p + c, sqr_diff))

n, d = map(int, input().split())
x = [[] for j in range(n)]
for i in range(n):
	x[i] = list(map(int, input().split()))

count = 0
for i in range(n):
	for j in range(i + 1, n):
		distance = dist(x[i], x[j])
		# print(distance, int(distance))
		if distance == int(distance):
			count += 1
print(count)
