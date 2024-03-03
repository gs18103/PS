import sys
input = sys.stdin.readline

def gcd(a, b) :
    if b == 0 :
        return a
    return gcd(b, a % b)

q = int(input())

for i in range(0, q) :
    a, b = map(int, input().split())
    print(a * b // gcd(a, b))