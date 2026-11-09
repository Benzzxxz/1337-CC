import time
import pyautogui

pyautogui.FAILSAFE = False  # avoid exceptions if the cursor ends up in a screen corner

INTERVAL = 2  # seconds

print("Running. Press Ctrl+C to stop.")
try:
    while True:
        pyautogui.moveRel(1, 0)   # 1 pixel right
        time.sleep(INTERVAL)
        pyautogui.moveRel(-1, 0)  # 1 pixel back left
        time.sleep(INTERVAL)
except KeyboardInterrupt:
    print("Stopped.")			