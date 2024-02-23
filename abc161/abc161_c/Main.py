N, K = list(map(int, input().split()))

print(min(N % K, abs(N % (-1 * K))))
