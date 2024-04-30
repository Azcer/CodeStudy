my_foods = ['pizza','falafel','carrot cake']
friend_foods = my_foods[:]
friend_foods.append('ice cream')
print(f"This is my food:{my_foods}")
print(f"This is my fridend's food:{friend_foods}")
for food in my_foods:
    print(food)
for food in friend_foods:
    print(food)