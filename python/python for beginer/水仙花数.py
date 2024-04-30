for i in range(100, 1000):
    a = i
    t1 = a % 10
    a //= 10
    t2 = a % 10
    t3 = a // 10
    if i == t1 ** 3 + t2 ** 3 + t3 ** 3:
        print(i)
