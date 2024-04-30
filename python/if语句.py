users = ['admin','ada','solo','ice','rob']
if users:
    for user in users:
        if user == 'admin':
            print("Hello admin, would you like to see a status report?")
        else:
            print(f"Hello {user}, think you for logging in again.")
else:
    print("We need to find some users!")

print("\n")

current_users = users[:]
new_users = ['ada','solo','young','sicdul','pisn']
for new_user in new_users:
    if new_user in current_users:
        print(f"{new_user}这个名字已经被使用了")
    else:
        print(f"{new_user}这个名字可以使用")

print("\n")

numbers = [i for i in range(1,10)]
for number in numbers:
    if number == 1:
        print("1st")
    elif number == 2:
        print('2ed')
    elif number == 3:
        print('3rd')
    else:
        print(f"{number}th")