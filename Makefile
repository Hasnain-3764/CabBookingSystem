# Compiler settings
CXX = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS = -lsqlite3 -pthread

# Directories
SRC_DIR = src
INCLUDE_DIR = include

# Source and object files
SRC = ./main.cpp $(SRC_DIR)/User.cpp $(SRC_DIR)/Rider.cpp $(SRC_DIR)/Driver.cpp $(SRC_DIR)/database.cpp $(SRC_DIR)/Ride.cpp $(SRC_DIR)/RideManager.cpp
OBJ = $(SRC:.cpp=.o)

# Output executable
TARGET = cab_booking

# Default target to build the executable
all: $(TARGET)

# Rule to link the object files to create the executable
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Rule to create .o from .cpp files in the src directory
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@
	@echo "Compiled: $< -> $@"  # Debugging: Prints each object file being compiled

# Clean up the build files
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
