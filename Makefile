CC=gcc
SRC=epinew.c
ENTRY=main.c
CFLAGS=-Wall -Wextra -Werror -Wdeprecated -ansi -pedantic -O3
LDFLAGS=-Iinclude
OUTPUT=epinew
INSTALL_PATH=/usr/local/bin/$(OUTPUT)

all: install clean

install: build $(OUTPUT) ; mv $(OUTPUT) INSTALL_PATH

uninstall: $(INSTALL_PATH) ; rm -f $(INSTALL_PATH)

build: new.o main.o ; $(CC) $(CFLAGS) *.o -o $(OUTPUT)

new.o: $(SRC) ; $(CC) $(CFLAGS) $(LDFLAGS) -c $(SRC)

main.o: $(ENTRY) ; $(CC) $(CFLAGS) $(LDFLAGS) -c $(ENTRY)

clean: ; rm -rf *.o

.PHONY: all install uninstall build clean
