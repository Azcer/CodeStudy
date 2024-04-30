places_I_want_to_go = ['Germany','Singapore','London','Alaska','New York','Scotland','Spain ']
print(sorted(places_I_want_to_go))#sorted函数不改变原列表
print(places_I_want_to_go)
print(sorted(places_I_want_to_go,reverse=True))#reverse为倒序属性
print(places_I_want_to_go)
places_I_want_to_go.reverse()#reverse方法将列表的元素排序颠倒
print(places_I_want_to_go)
places_I_want_to_go.reverse()
print(places_I_want_to_go)
places_I_want_to_go.sort()#sort方法将列表的元素排序
print(places_I_want_to_go)
places_I_want_to_go.sort(reverse=True)
print(places_I_want_to_go)
#用for循环遍历列表
for place_I_want_to_go in places_I_want_to_go:      
    print(f"{place_I_want_to_go} is so beautiful!")