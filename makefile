#makefile LogInDetails Class
CC= g++
LoginApp: Login.o LoginDetails.o
	$(CC) Login.o LogInDetails.o -o LoginApp

Login.o:Login.cpp
	$(CC) -c Login.cpp

LogInDetails.o : LogInDetails.cpp LogInDetails.h
	$(CC) -c LogInDetails.h
	$(CC) -c LogInDetails.cpp

clean:
	rm -rf *o LogInDetails
