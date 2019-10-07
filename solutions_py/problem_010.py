'''
This problem was asked by Apple.

Implement a job scheduler which takes in a function f and an integer n, and calls f after n milliseconds.
'''
from threading import Timer

def hello_world():
    print("Hello, World!")

def scheduler(f, delay_in_ms):
    # convert milliseconds to seconds
    delay_in_s = delay_in_ms / 1000 
    t = Timer(delay_in_s, f)
    print(f"after {delay_in_s} seconds, f will be called ...")
    t.start() # after n seconds, f will be called




scheduler(hello_world, 5000)