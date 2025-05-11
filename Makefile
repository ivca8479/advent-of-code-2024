CXX = g++
TARGET = day_two.exe
SRCS = day_two.cpp libraries/string_helpers.cpp libraries/array_helpers.cpp 

all:
	$(CXX) $(SRCS) -o $(TARGET)

clean:
	del /Q $(TARGET) 2>nul || exit 0
