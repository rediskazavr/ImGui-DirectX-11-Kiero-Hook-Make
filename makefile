TARGET = ./build/ImGui-DirectX-11-Kiero-Hook-Make.dll

SRC = \
    ./src/main.cpp \
    ./core/kiero/kiero.cpp \
    ./core/kiero/minhook/src/buffer.c \
    ./core/kiero/minhook/src/hook.c \
    ./core/kiero/minhook/src/trampoline.c \
    ./core/kiero/minhook/src/hde/hde32.c \
    ./core/kiero/minhook/src/hde/hde64.c \
    ./core/imgui/imgui_demo.cpp \
    ./core/imgui/imgui_draw.cpp \
    ./core/imgui/imgui_impl_dx11.cpp \
    ./core/imgui/imgui_impl_win32.cpp \
    ./core/imgui/imgui_widgets.cpp \
    ./core/imgui/imgui.cpp

HDRS = \
    ./src/includes.h \
    ./core/kiero/kiero.h \
    ./core/kiero/minhook/include/MinHook.h \
    ./core/kiero/minhook/src/buffer.h \
    ./core/kiero/minhook/src/trampoline.h \
    ./core/kiero/minhook/src/hde/hde32.h \
    ./core/kiero/minhook/src/hde/hde64.h \
    ./core/kiero/minhook/src/hde/pstdint.h \
    ./core/kiero/minhook/src/hde/table32.h \
    ./core/kiero/minhook/src/hde/table64.h \
    ./core/imgui/imconfig.h \
    ./core/imgui/imgui_impl_dx11.h \
    ./core/imgui/imgui_impl_win32.h \
    ./core/imgui/imgui_internal.h \
    ./core/imgui/imgui.h \
    ./core/imgui/imstb_rectpack.h \
    ./core/imgui/imstb_textedit.h \
    ./core/imgui/imstb_truetype.h

DEF = ./core/kiero/minhook/dll_resources/MinHook.def
RC = ./core/kiero/minhook/dll_resources/MinHook.rc

OBJS = $(SRC:.cpp=.o)
OBJS := $(OBJS:.c=.o)

CXX = g++
CC = gcc
LD = g++
WINDRES = windres

CXXFLAGS = -I./core -I./core/kiero -I./core/kiero/minhook/include -I./core/imgui -Wall -Wextra -fPIC
CFLAGS = -I./core -I./core/kiero -I./core/kiero/minhook/include -I./core/imgui -Wall -Wextra -Werror -fPIC
LDFLAGS = -shared -static-libgcc -static-libstdc++ -ld3d11 -ldxgi -ld3dcompiler -lxinput -luser32 -lgdi32 -lxinput9_1_0

all: $(TARGET)

$(TARGET): $(OBJS) $(DEF) $(RC)
	$(WINDRES) $(RC) -O coff -o MinHook.res
	$(LD) $(OBJS) MinHook.res -o $@ $(LDFLAGS) -ld3dcompiler -lxinput $(DEF)

%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) MinHook.res

.PHONY: all clean