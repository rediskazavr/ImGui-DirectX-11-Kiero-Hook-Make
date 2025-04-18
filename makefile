TARGET = ./build/injector.exe

SRC = \
	./src/main.cpp

$(TARGET):
	g++ $(SRC) -o $(TARGET)