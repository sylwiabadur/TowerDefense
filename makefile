TARGET_EXEC ?= a.exe
CC = g++
BUILD_DIR ?= ./build
SRC_DIRS ?= ./src


SRCS := $(wildcard ./src/**/*.cpp) $(wildcard ./src/*.cpp)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := SFML-2.5.0\include
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

LIB_DIRS = SFML-2.5.0\lib 
LIB_FLAGS := $(addprefix -L,$(LIB_DIRS))

LDFLAGS = -lmingw32 -lsfml-graphics-d -lsfml-audio-d -lsfml-window-d -lsfml-system-d


CPPFLAGS ?= -static-libgcc -static-libstdc++ $(INC_FLAGS) $(LIB_FLAGS) -g # -Wl,-subsystem,windows

$(TARGET_EXEC): $(OBJS)
	$(MKDIR_P) $(BUILD_DIR)
	$(CC) $(OBJS) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o $@

# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS)  -c $< $(LDFLAGS) -o $@ 


.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p