test = int(input())
while (test > 0):
	test = test - 1
	string = input().split()
	if "machula" in string[0]:
		string[0] = int(string[4]) - int(string[2])
	elif "machula" in string[2]:
		string[2] = int(string[4]) - int(string[0])
	elif "machula" in string[4]:
		string[4] = int(string[0]) + int(string[2])
	print (str(string[0]) + ' + ' + str(string[2]) + ' = ' + str(string[4]))