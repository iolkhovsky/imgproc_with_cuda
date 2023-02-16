CC = clang++
CFLAGS = -fPIC -std=c++17
LDFLAGS = -I. -lm -lpthread 

LIBFILTER2D_SOURCES = src/single_thread_filter2d.cpp

build: libfilter2d.dylib

libfilter2d.dylib: filter2d.o
	$(CC) $(CFLAGS) -shared $(LDFLAGS) lib/single_thread_filter2d.o -o lib/libfilter2d.dylib

filter2d.o: libfolder
	$(CC) $(CFLAGS) -c $(LDFLAGS) src/single_thread_filter2d.cpp -o lib/single_thread_filter2d.o

libfolder:
	mkdir lib

clean:
	rm -rf lib
