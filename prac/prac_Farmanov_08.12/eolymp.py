a, m = (int(i) for i in input().split())
n = 0

while m != 0:
    n += 1
    if m == 2 * a:
        break
    m -= a
    a += 1
print(n)