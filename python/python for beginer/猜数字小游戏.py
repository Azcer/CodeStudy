import random as rd

# 生成随机数
number = rd.randint(0, 100)
cnt = 0
guess_num = int(input("请输入一个0~100的数："))
cnt += 1
while guess_num != number:
    if guess_num > number:
        guess_num = int(input("抱歉你猜大了，请再输入一个数："))
    elif guess_num < number:
        guess_num = int(input("抱歉你猜小了，请再输入一个数："))
    cnt += 1
print("恭喜你猜对了，你一共猜了" + str(cnt) + "次。")
