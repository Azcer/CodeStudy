class Settings:
    """存储游戏中所有设置的类"""

    def __init__(self):
        """初始化游戏的设置"""
        # 屏幕设置
        self.screen_width = 1200
        self.screen_height = 800
        self.bg_color = (230, 230, 230)
        # 飞船设置
        self.ship_speed = 1.25
        # 子弹设置
        self.bullet_speed = 5
        self.bullet_width = 10
        self.bullet_height = 60
        self.bullet_color = (30, 144, 255)
        # 外星人设置
        self.alien_speed = 0.2
        self.fleet_drop_speed = 10
        self.fleet_direction = 1  # 1表示向右移， -1表示向左移
