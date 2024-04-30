x = int(input("x="))
y = int(input("y="))
# 求最大公因数
if x >= y:
    ma = x
    mi = y
else:
    ma = y
    mi = x
for i in range(mi, 0, -1):
    if x % i == 0 and y % i == 0:
        print("最大公因数为：" + str(i))
        break
for i in range(ma, x * y + 1):
    if i % x == 0 and i % y == 0:
        print("最小公背数为：" + str(i))
        break
