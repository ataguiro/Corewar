from itertools import izip
import sys
import os

file1 = sys.argv[1]
file2 = sys.argv[2]

fd1 = open(file1)
fd2 = open(file2)

for x, y in izip(fd1, fd2):
    s1 = list(x)
    s2 = list(y)
    i = 0
    while i < len(s1):
        if s1[i] == s2[i]:
            print str(s1[i]),
        else:
            print "\033[1;31m" + str(s2[i]) + "\033[0m"
        i += 1
