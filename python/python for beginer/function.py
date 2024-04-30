messages = ["Hello!","How are you?","Good morning!"]
sent_messages = []

def show_messages(messages):
    for message in messages:
        print(message)
show_messages(messages)
print()
def send_messages(messages,sent_messages):
    while messages:
        sent_message = messages.pop()
        print(sent_message)
        sent_messages.append(sent_message)
send_messages(messages[:],sent_messages)
print(messages)
print(sent_messages)

#传递任意数量的实参
def make_pizza(size ,*toppings):#*创建一个空元组
    print(f"\nMakeing a {size}-inch pizza with the following toppings:")
    for topping in toppings:
        print(f"-{topping}")

make_pizza(12,'pepperoni')
make_pizza(8,'mushrooms','green peppers')

#使用任意数量的关键字实参
def build_profile(first,last,**user_info):#**创建一个空字典
    user_info['first_name'] = first
    user_info['last_name'] = last
    return user_info

user_profile = build_profile('albert','einstein',location = 'princeton',field = 'physics')
print(user_profile)