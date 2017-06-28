from subprocess import Popen, PIPE, check_output, call
import signal
import os
import sys

def pc_handler(signum, frame):
        raise Exception("timeout")

signal.signal(signal.SIGALRM, pc_handler)

if len(sys.argv) != 2:
    print("Usage : python tester.py [file_to_randomize]")
    sys.exit(1)

while 1:
    signal.alarm(5)
    try:
        os.system("cat " + sys.argv[1] + " | radamsa > test.s")
        out = call(["./asm", "test.s"])
    except:
        pass
    if out > 1 or out < 0:
        print("SEGFAULT !")
        sys.exit(1)
