all:
	g++ -std=c++0x -Wall -Wextra heapuaf.cpp -o heapuaf

test: all 
	netcat -e ./heapuaf -v -l -p 4444
	
