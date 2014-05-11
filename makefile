CXX = g++
# Update these paths to match your installation
# You may also need to update the linker option rpath, which sets where to look for
# the SDL2 libraries at runtime to match your install
SDL_LIB = -L/usr/lib -lSDL2 -Wl,-rpath=/usr/lib -lSDL2_image
SDL_INCLUDE = -I/usr/include
# You may need to change -std=c++11 to -std=c++0x if your compiler is a bit older
CXXFLAGS = -g -Wall -c -std=c++11 $(SDL_INCLUDE)
LDFLAGS = $(SDL_LIB)
EXE = BtS
CPP_FILES := $(wildcard ./*.cpp)
OBJ_FILES := $(addprefix ./,$(notdir $(CPP_FILES:.cpp=.o)))

all: $(EXE)

$(EXE):  $(OBJ_FILES)
	g++ $^ $(LDFLAGS) -o $@

./%.o: ./%.cpp
	g++ $(CXXFLAGS) -c -o $@ $<

clean:
	rm *.o && rm $(EXE)
