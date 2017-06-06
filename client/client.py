import socket
import readline
import os
import sys
import signal
import time
from pwn import *

# Colors

RED	= "\033[1;31m"
GREEN	= "\033[1;32m"
ORANGE	= "\033[1;33m"
GREY	= "\033[1;90m"
BLUE	= "\033[1;94m"
EOC	= "\033[0m"

# Line editing config

readline.parse_and_bind('tab: complete')
readline.parse_and_bind('set editing-mode vi')
readline.parse_and_bind('Meta-h: backward-kill-word')
readline.parse_and_bind('"\C-u": universal-argument')
readline.parse_and_bind('set horizontal-scroll-mode On')

host		= '127.0.0.1'
port		= 4243
num_players	= 4
ind_player	= 0

r		= 0

players		= [
{'ready':'no', 'connected':'no', 'id':'none', 'index':0},
{'ready':'no', 'connected':'no', 'id':'none', 'index':0},
{'ready':'no', 'connected':'no', 'id':'none', 'index':0},
{'ready':'no', 'connected':'no', 'id':'none', 'index':0}
]

def clean_exit(number, frame):
	r.send("end")
	r.close()
	print "\nClosing connection..."
	sys.exit(0)

def welcome():
	print "Connected ! Welome on the famous Corewar game."

def print_blank():
	print GREY + "-" * 25
	print "-          X"
	print "-         LOCKED"
	print "-         SLOT"
	print "-          X"
	print "-" * 25
	print EOC,

def print_norm(i):
	print BLUE + "-" * 25
	print BLUE + "- " + ORANGE + "Player number : " + GREEN + str(players[i]['index']) + (" [you]" if i == ind_player else "")
	print BLUE + "- " + ORANGE + "Connected : " + \
			(RED if players[i]['connected'] == 'no' else GREEN) + \
			players[i]['connected']
	print BLUE + "- " + ORANGE + "Ready : " + \
			(RED if players[i]['ready'] == 'no' else GREEN) + players[i]['ready']
	print BLUE + "- " + ORANGE + "ID : " + GREEN + players[i]['id']
	print BLUE + "-" * 25
	print EOC,

def print_slot(i):
	if i > num_players:
		print_blank()
	else:
		print_norm(i - 1)
	print ""

def print_infos():
	for i in range(1, 5):
		print_slot(i)

def prompt():
	while True:
		line = raw_input(ORANGE + "cwctl> " + EOC)
		arr = line.split()
		try:
			if len(arr) > 1 and arr[0] == "load":
				r.send(arr[1])
			else:
				r.send("blank")
		except:
			sys.exit(1)
		print "\033[H\033[J"
		get_info()
		print_infos()

def get_info():
	global ind_player
	global num_players
	ret = ''
	try:
		ret = r.recvline()
	except:
		pass
	if ("full" in ret):
		print "Room full : " + str(num_players) + "/" + str(num_players)
		r.close()
		sys.exit(1)
	try:
		num_players = int(ret[:-1])
		ind_player = int(r.recvline()[:-1])
		for i in range(0, 4):
			players[i]['ready'] = r.recvline()[:-1]
			players[i]['connected'] = r.recvline()[:-1]
			players[i]['id'] = r.recvline()[:-1]
			players[i]['index'] = r.recvline()[:-1]
	except:
		pass

def launch():
	global r
	signal.signal(signal.SIGINT, clean_exit)
	try:
		r = remote(host, port)
	except:
		print "I didn't find any server listening on port " + str(port)
		sys.exit(1);
	get_info()
	print_infos()
	welcome()
	prompt()

if __name__ == '__main__':
	launch()
