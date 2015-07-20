f = [1 for i in range(101)]

f[0] = 1
f[1] = 1

for i in range (1,101):
	f[i] = f[i-1] * i

t = int(input())

for i in range(t):
	n = int(input())
	print f[n]
