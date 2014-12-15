CC = g++
CFLAGS = -I ../include/
BMP = ../include/EasyBMP/EasyBMP.cpp
SOURCE_DIR = src/

all: tesla

tesla: tesla.cpp scene.o object.o sphere.o bbox.o
	$(CC) $(CFLAGS) tesla.cpp scene.o object.o sphere.o bbox.o $(BMP) -o tesla

scene.o: scene.cpp object.o sphere.o bbox.o
	$(CC) $(CFLAGS) -c scene.cpp object.o sphere.o bbox.o

sphere.o: sphere.cpp bbox.o object.o
	$(CC) $(CFLAGS) -c sphere.cpp bbox.o object.o

object.o: object.cpp bbox.o
	$(CC) $(CFLAGS) -c object.cpp bbox.o

bbox.o:
	$(CC) $(CFLAGS) -c bbox.cpp

clean:
	rm -rf *.o *.out tesla output.bmp *.log