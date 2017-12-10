headFileTestDrive: headFileTest.o headFileTestDrive.o
	gcc headFileTest.o headFileTestDrive.o -o headFileTestDrive

headFileTest.o: headFileTest.c headFileTest.h
	gcc -c headFileTest.c -o headFileTest.o

headFileTestDrive.o: headFileTestDrive.c
	gcc -c headFileTestDrive.c -o headFileTestDrive.o

