import mss
import numpy as np
import cv2
import pyautogui
import win32gui
import win32con
import time

# 获取窗口的位置信息
def get_window_info(hwnd):
    # 获取窗口的边界框
    left, top, right, bottom = win32gui.GetWindowRect(hwnd)
    print(f"窗口位置: 左={left}, 上={top}, 右={right}, 下={bottom}")
    return left, top, right - left, bottom - top

# 截取窗口截图
def capture_window(hwnd, left, top, width, height):
    with mss.mss() as sct:
        monitor = {'top': top, 'left': left, 'width': width, 'height': height}
        screenshot = sct.grab(monitor)
        img = np.array(screenshot)
        img_bgr = cv2.cvtColor(img, cv2.COLOR_RGBA2BGR)  # 转换为BGR格式
        # 显示图像
        cv2.imshow("Captured Window", img_bgr)
        # 等待20秒查看图像
        time.sleep(20)
        return img_bgr

# 模板匹配
def match_image(template_image, screen_image):
    result = cv2.matchTemplate(screen_image, template_image, cv2.TM_CCOEFF_NORMED)
    min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(result)
    return max_loc, max_val

# 主程序
def main():
    hwnd = win32gui.FindWindow(None, "MuMu模拟器121")  # 模拟器窗口
    left, top, width, height = get_window_info(hwnd)

    # 截取窗口截图并加载模板图像
    screen_image = capture_window(hwnd, left, top, width, height)
    # template_image = cv2.imread("template.png", cv2.IMREAD_GRAYSCALE)

    # # 进行图像匹配
    # max_loc, max_val = match_image(template_image, screen_image)
    # print(f"匹配位置: {max_loc}, 匹配值: {max_val}")

if __name__ == "__main__":
    main()