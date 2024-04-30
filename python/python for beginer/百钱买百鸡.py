# 公鸡(x)5元一只，母鸡(y)3元一只，小鸡(z)1元3只
cnt=0
for x in range(1,20):
    for y in range(1,33):
        z=100-x-y
        if x+y+z==100 and 5*x+3*y+(1/3)*z==100:
            cnt+=1
            print("--"*60)
            print(f"第{cnt}中方法：{x}只公鸡，{y}只母鸡，{z}只小鸡")
