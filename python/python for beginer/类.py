class Dog:
    def __init__(self, name, age, color):
        self.name = name
        self.age = age
        self.color = color
    
    def sit(self):
        print(f"{self.name} is now sitting.")

    def roll_over(self):
        print(f"{self.name} rolled over!!")

xiaohuang = Dog('xiaohuang', 17, 'yellow')
xiaohuang.roll_over()

class Restaurant:
    def __init__(self, restaurant_name, cuisine_type):
        self.restaurant_name = restaurant_name
        self.cuisine_type = cuisine_type

    def describe_restaurant(self):
        print(f"{self.restaurant_name} is a {self.cuisine_type} restaurant")
    
    def open_restaurant(self):
        print(f"{self.restaurant_name} is opening!")

restaurant = Restaurant('ahe', 'chuancai')
restaurant.describe_restaurant()
restaurant.open_restaurant()
