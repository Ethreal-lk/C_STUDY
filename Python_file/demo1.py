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
# # 5. 识别屏幕中的特定图标或区域
# def match_image(template_image, screen_image):
#     result = cv2.matchTemplate(screen_image, template_image, cv2.TM_CCOEFF_NORMED)
#     min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(result)
#     return max_loc, max_val

def match_and_click_center(
    template_path: str,
    screen_image: np.ndarray,
    threshold: float = 0.85,
    click: bool = True,
    random_offset: int = 5
) -> tuple[int, int] | None:
    """
    模板匹配并返回中心坐标（可加随机偏移）
    
    :param template_path: 模板图像路径
    :param screen_image: 截图（灰度图）
    :param threshold: 匹配阈值，默认0.85
    :param click: 是否执行点击，默认 True
    :param random_offset: 点击位置随机偏移像素，默认 5
    :return: 模板中心坐标 (x, y)，未匹配返回 None
    """
    # 加载模板
    template = cv2.imread(template_path, cv2.IMREAD_GRAYSCALE)
    if template is None:
        raise FileNotFoundError(f"模板图像未找到或无法加载: {template_path}")
    
    if screen_image.shape[0] < template.shape[0] or screen_image.shape[1] < template.shape[1]:
        print("截图尺寸小于模板尺寸，无法匹配！")
        return None
    # 模板匹配
    result = cv2.matchTemplate(screen_image, template, cv2.TM_CCOEFF_NORMED)
    _, max_val, _, max_loc = cv2.minMaxLoc(result)

    if max_val < threshold:
        return None
    # 计算模板中心坐标
    h,w = template.shape[:2]
    center_x = max_loc[0] + w // 2
    center_y = max_loc[1] + h // 2

    #随机偏移，防检测

    if random_offset > 0:
        center_x += random.randint(-random_offset,random_offset)
        center_y += random.randint(-random_offset,random_offset)
    return (center_x,center_y)
# # 6. 执行按键操作
# def press_key(key):
#     pyautogui.press(key)

# 主函数
def main():
    # # 找到模拟器窗口
    # hwnd = find_window("MuMu模拟器121")
    # left, top, width, height = get_window_info(hwnd)
    # print(f"Window position: Left={left}, Top={top}, Width={width}, Height={height}")
    # # 截取窗口并加载要识别的模板图像
    # screen_image = capture_window(hwnd, left, top, width, height)
    # # template_image = cv2.imread(r"E:\Study\C_STUDY\Python_file\test.png", cv2.IMREAD_GRAYSCALE)
    # # if template_image is None:
    # #     raise Exception("模板图像未找到或无法加载")

    # # 转换为灰度图像进行匹配
    # screen_gray = cv2.cvtColor(screen_image, cv2.COLOR_BGR2GRAY)

    # center_x,center_y =  match_and_click_center(r"E:\Study\C_STUDY\Python_file\test.png",screen_gray)
    # pyautogui.click(left + center_x, top + center_y)
    # # 获取当前鼠标的位置
    # mouse_x, mouse_y = pyautogui.position()
    # print(f"Current mouse position: X={mouse_x}, Y={mouse_y}")
    # hwnd = find_window("MuMu模拟器121")
    # left, top, width, height = get_window_info(hwnd)
    # print(f"Window position: Left={left}, Top={top}, Width={width}, Height={height}")
    # # 截取窗口并加载要识别的模板图像
    # screen_image = capture_window(hwnd, left, top, width, height)
    # # template_image = cv2.imread(r"E:\Study\C_STUDY\Python_file\test.png", cv2.IMREAD_GRAYSCALE)
    # # if template_image is None:
    # #     raise Exception("模板图像未找到或无法加载")

    # # 转换为灰度图像进行匹配
    # screen_gray = cv2.cvtColor(screen_image, cv2.COLOR_BGR2GRAY)

    # center_x,center_y =  match_and_click_center(r"E:\Study\C_STUDY\Python_file\tupian\tansuo.png",screen_gray)
    # pyautogui.click(left + center_x, top + center_y)
    # # 获取当前鼠标的位置
    # mouse_x, mouse_y = pyautogui.position()
    # print(f"Current mouse position: X={mouse_x}, Y={mouse_y}")


    while True:
        hwnd = find_window("MuMu模拟器121")
        left, top, width, height = get_window_info(hwnd)
        # print(f"Window position: Left={left}, Top={top}, Width={width}, Height={height}")
        # 截取窗口并加载要识别的模板图像
        screen_image = capture_window(hwnd, left, top, width, height)
        # template_image = cv2.imread(r"E:\Study\C_STUDY\Python_file\test.png", cv2.IMREAD_GRAYSCALE)
        # if template_image is None:
        #     raise Exception("模板图像未找到或无法加载")

        # 转换为灰度图像进行匹配
        screen_gray = cv2.cvtColor(screen_image, cv2.COLOR_BGR2GRAY)
        center = match_and_click_center(r"E:\Study\C_STUDY\Python_file\tupian\tiaozhan.png",screen_gray)
        if center:
            pyautogui.click(left + center[0], top + center[1])
            print(f"Clicked at: X={left + center[0]}, Y={top + center[1]}")
            time.sleep(2)
        center = match_and_click_center(r"E:\Study\C_STUDY\Python_file\tupian\zhunbei.png",screen_gray)
        if center:
            pyautogui.click(left + center[0], top + center[1])
            print(f"Clicked at: X={left + center[0]}, Y={top + center[1]}")
            time.sleep(2)
        center = match_and_click_center(r"E:\Study\C_STUDY\Python_file\tupian\wancheng.png",screen_gray)
        if center:
            pyautogui.click(left + center[0], top + center[1])
            print(f"Clicked at: X={left + center[0]}, Y={top + center[1]}")
            time.sleep(2)
        center = match_and_click_center(r"E:\Study\C_STUDY\Python_file\tupian\fail.png",screen_gray)
        if center:
            pyautogui.click(left + center[0], top + center[1])
            print(f"Clicked at: X={left + center[0]}, Y={top + center[1]}")
            time.sleep(2)
    # location, confidence = match_image(template_image, screen_gray)
    # print(f"Match location: {location}, Confidence: {confidence}")
    # # If the confidence is high enough, perform a click operation
    # if confidence > 0.8:  # You can adjust the threshold
    #     print("Target location found, clicking!")
    #     win32gui.SetForegroundWindow(hwnd)
    #     time.sleep(2)  # 等待窗口激活
    #     h,w = template_image.shape[:2]
    #     center_x = location[0] + w // 2
    #     center_y = location[1] + h // 2
    #     pyautogui.click(left + center_x, top + center_y)
    #     # 获取当前鼠标的位置
    #     mouse_x, mouse_y = pyautogui.position()
    #     print(f"Current mouse position: X={mouse_x}, Y={mouse_y}")
    # else:
    #     print("Target icon not found")

if __name__ == "__main__":
    main()

