#ver http://www.gnu.org/software/make/manual/make.html#Automatic-Variables
CC=g++
CFLAGS=-Wall -g -std=c++11
#
# define any directories containing header files other than /usr/include
#
INCLUDES = -I./include
DEPS = cycle.h

test_hash_map.exe: test_hash_map.o
	$(CC) -o $@ $^

hello.exe: hello.o
	$(CC) -o $@ $^

unordered_map.exe: unordered_map.o
	$(CC) -o $@ $^

timemap.exe: timemap.o
	$(CC) -o $@ $^

%.o: %.cc
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) *.o test_hash_map.exe hello.exe timemap.exe
                           
all: hello.exe test_hash_map.exe unordered_map.exe timemap.exe

#all:
#	g++ hello.cc