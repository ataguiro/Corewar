#!/usr/bin/python

import os
import sys

if len(sys.argv) < 2:
    sys.exit(1)
for i in range(1, len(sys.argv)):
    f = sys.argv[i]
    print "\n\033[1;33m TESTING : %s\033[0m\n" % f
    print "\033[1;33mMy asm output : \033[0m"
    os.system("./asm " + f)
    os.system("xxd " + f[:-2] + ".cor" + " > t1 2>&-")
    print "\033[1;33mZaz asm output : \033[0m"
    os.system("./asm_zaz " + f)
    os.system("xxd " + f[:-2] + ".cor" + " > t2 2>&-")
    os.system("diff t1 t2")
    os.system("rm *.cor 2>&-")
