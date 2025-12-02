# -*- coding: utf-8 -*-
import ctypes
import win32gui
import pyautogui
import numpy as np
import cv2
import mss
import time
import random

# 1. DPI 感知
ctypes.windll.user32.SetProcessDPIAware()

# 2. 找到窗口
def find_window(title):
    hwnd = win32gui.FindWindow(None, title)
    if hwnd == 0:
        # 修改此行，避免无效字符
        raise Exception("窗口未找到")
    return hwnd

# 3. 获取窗口的位置信息
def get_window_info(hwnd):
    # 获取窗口的边界框
    left, top, right, bottom = win32gui.GetWindowRect(hwnd)
    return left, top, right - left, bottom - top

# 4. 截取窗口截图并用 OpenCV 进行图像匹配
def capture_window(hwnd, left, top, width, height):
    with mss.mss() as sct:
        monitor = {'top': top, 'left': left, 'width': width, 'height': height}
        screenshot = sct.grab(monitor)
        return np.array(screenshot)
# 5. 识别屏幕中的特定图标或区域
def match_image(template_image, screen_image):
    result = cv2.matchTemplate(screen_image, template_image, cv2.TM_CCOEFF_NORMED)
    min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(result)
    return max_loc, max_val

# # 6. 执行按键操作
# def press_key(key):
#     pyautogui.press(key)

# 主函数
def main():
    # 找到模拟器窗口
    hwnd = find_window("MuMu模拟器121")
    left, top, width, height = get_window_info(hwnd)
    print(f"Window position: Left={left}, Top={top}, Width={width}, Height={height}")
    # 截取窗口并加载要识别的模板图像
    screen_image = capture_window(hwnd, left, top, width, height)
    template_image = cv2.imread(r"E:\Study\C_STUDY\Python_file\test.png", cv2.IMREAD_GRAYSCALE)
    if template_image is None:
        raise Exception("模板图像未找到或无法加载")

    # 转换为灰度图像进行匹配
    screen_gray = cv2.cvtColor(screen_image, cv2.COLOR_BGR2GRAY)

    # 进行图像匹配
    location, confidence = match_image(template_image, screen_gray)
    print(f"Match location: {location}, Confidence: {confidence}")
    # 获取屏幕的分辨率
    screen_width, screen_height = pyautogui.size()
    print(f"fenbianlv: {screen_width}x{screen_height}")

    # If the confidence is high enough, perform a click operation
    if confidence > 0.8:  # You can adjust the threshold
        print("Target location found, clicking!")
        win32gui.SetForegroundWindow(hwnd)
        time.sleep(2)  # 等待窗口激活
        h,w = template_image.shape[:2]
        center_x = location[0] + w // 2
        center_y = location[1] + h // 2
        pyautogui.click(left + center_x, top + center_y)
        # 获取当前鼠标的位置
        mouse_x, mouse_y = pyautogui.position()
        print(f"Current mouse position: X={mouse_x}, Y={mouse_y}")
    else:
        print("Target icon not found")

if __name__ == "__main__":
    main()