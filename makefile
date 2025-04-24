TARGET = ./build/injector.exe

SRC = \
	./src/shell/main.cpp \
	./src/dll_inject.cpp \
	./src/shell/cmd/line.cpp \
	./src/shell/func/colors.cpp \
	./src/shell/func/design.cpp \

HDRS = \
	./src/dll_inject.hpp \
	./src/shell/cmd/line.hpp \
	./src/shell/func/colors.hpp \
	./src/shell/func/design.hpp \

$(TARGET):
	g++ $(SRC) -I $(HDRS) -o $(TARGET)