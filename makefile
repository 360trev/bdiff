# makefile

DEBUG   =@
RM      =del
CC      =gcc
ECHO    =@echo
CFLAGS  =-Wall -O3
LDFLAGS =

EXE     =bdiff.exe
SRC     =$(notdir $(foreach dir, ., $(wildcard $(dir)/*.c)))
LIBS    =

include makefile.common
