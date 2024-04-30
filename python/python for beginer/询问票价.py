active = True
while active:
    age = input("请输入你的年龄来查询票价(输入close关闭程序)：")
    if age == 'close':
        active = False
    else:
        if int(age) < 3:
            print("你将免费观看。")
        elif (int(age) >= 3) and (int(age) <= 12):
            print("你的票价为10美元")
        elif int(age) > 12:
            print("你的票价为15美元")
