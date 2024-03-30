
CC = gcc
CFLAGS = -Wvla 
LDFLAGS =
RM = /bin/rm


run : build
	./265inventory

view : 265inventory.h 265inventory.c databaseInteraction.h databaseInteraction.c commandParse.h commandParse.c commandProcess.h commandProcess.c
	less -x4 265inventory.h 265inventory.c databaseInteraction.h databaseInteraction.c commandParse.h commandParse.c commandProcess.h commandProcess.c

build : 265inventory.o commandParse.o commandProcess.o databaseInteraction.o
	$(CC) $(CFLAGS) 265inventory.o commandParse.o commandProcess.o databaseInteraction.o -o 265inventory

265inventory.o : 265inventory.c databaseInteraction.h
	$(CC) $(CFLAGS) -c 265inventory.c

commandParse.o : commandParse.c commandParse.h 265inventory.h
	$(CC) $(CFLAGS) -c commandParse.c

commandProcess.o : commandProcess.c commandProcess.h 265inventory.h
	$(CC) $(CFLAGS) -c commandProcess.c

databaseInteraction.o: databaseInteraction.c databaseInteraction.h commandParse.h commandProcess.h 265inventory.h
	$(CC) $(CFLAGS) -c databaseInteraction.c

.PHONY : clean cleanall

clean :
	-$(RM) *.o

cleanall : clean
	-$(RM) 265inventory
