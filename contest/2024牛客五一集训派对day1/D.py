import sys

n, m = map(int, input().split())
a = [0] * n
b = [0] * n

for i in range(n):
    a[i], b[i] = map(int, input().split())
    
def exgcd(a, b):
    if b == 0:
        return 1, 0, a
    x, y, d = exgcd(b, a % b)
    return y, x - (a // b) * y, d

a1 = a[0]
r1 = b[0]
for i in range(1, n):
    a2 = a[i]
    r2 = b[i]
    k1, k2, d = exgcd(a1, a2)
    c = r2 - r1
    t = a2 // d
    if(c % d != 0):
        print("he was definitely lying")
        sys.exit()
    k1 = c // d * k1
    k1 = (k1 % t + t) % t
    r1 = k1 * a1 + r1
    a1 = a1 // d * a2

res = (r1 % a1 + a1) % a1
if(res > m):
    print("he was probably lying")
else:
    print(int(res))
    