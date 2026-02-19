CXX       = g++
CXXFLAGS  = -std=c++17 -Wall -Wextra -O2
INCLUDES  = -Isrc -Isrc/algorithms -Isrc/utils

SRCS      = $(wildcard src/*.cpp) \
            $(wildcard src/algorithms/*.cpp) \
            $(wildcard src/utils/*.cpp)
BUILD_DIR = build
OBJS      = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))
TARGET    = sorting

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)
	rm -f input.txt output.txt input_*.txt

.PHONY: all clean
