import sys

input = sys.stdin.readline

a = int(input())
b = int(input())
c = a * b

for i in range(0, 3) :
    print(a * (b % 10))
    b //= 10

print(c)