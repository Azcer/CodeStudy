guest_list = ["Solomon","Lisa","Tim"]
print(f"这次聚会我们将邀请的嘉宾为{guest_list}")
print(f"{guest_list[-1]}无法赴约！")
guest_list[-1] = "Ted"
print(f"新的嘉宾名单为{guest_list}")
print("我们找到了一个更大的餐桌")
board = []#餐桌
board.insert(0,guest_list[0])
board.insert(1,guest_list[1])
board.append(guest_list[2])
print(f"该餐桌上的人为{board}")
print("由于新的餐桌没有到达，所以我们需要减少邀请的嘉宾")
pop_guest_list = guest_list.pop(2)
print(f"最新的嘉宾名单为{guest_list},总计{len(guest_list)}人")
print(f"抱歉以下朋友这次 无法加入我们\n{pop_guest_list}")
print("下面将清空嘉宾名单")
del guest_list[0]
del guest_list[0]
print(guest_list)
