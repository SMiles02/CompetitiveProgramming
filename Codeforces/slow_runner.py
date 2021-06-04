from os import *
for _ in range(1):
	system("g++ testGen.cpp")
	A = popen("g++ slow_sol.cpp").read()
	B = popen("g++ CF13E.cpp").read()
	if A != B:
		print("rip")
		exit(0)
print("yay")