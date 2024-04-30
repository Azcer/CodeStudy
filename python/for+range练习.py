#使用for循环打印数1~20（含）
for i in range(1,21):
    print(i)

#创建一个包含数1~1000000的列表，在使用一个for循环将这些数打印出来。
numbers = [i for i in range(1,1_000_001)]
for i in numbers:
   print(i)

#创建一个包含数1~1000000的列表，在使用min()和max()核实该列表确实是从1开始、到1000000结束的。另外，对这个列表调用sum()函数，看看python将一百万个数相加需要多长时间。
print(f"min={min(numbers)}")
print(f"max={max(numbers)}")
print(f"sum={sum(numbers)}")

#通过给函数range()指定第三个参数来创建一个列表，其中包含1~20的奇数，再使用一个for循环将这些数打印出来。
odd_number = [i for i in range(1,20,2)]
for i in odd_number:
    print(i) 

#创建一个列表，其中包含3~30能被3整除的数，再使用一个for循环将这个列表中的数打印出来
multiple_of_3 = [i for i in range(3,31,3)]
for i in multiple_of_3:
    print(i)

#创建一个列表，其中包含前10个整数的立方，在使用一个for循环讲这些立方数打印出来。
cubic_number = [i**3 for i in range(1,11)]
for i in cubic_number:
    print(i)
