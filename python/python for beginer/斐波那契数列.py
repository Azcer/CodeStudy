n = int(input("n:"))
a, b = 1, 1
for i in range(0,n):
    print(f"{a}", end=" ")
    t = a
    a = b
    b = t + a