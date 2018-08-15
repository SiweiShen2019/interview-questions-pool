CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -g


# Build an executable file named by argument "no" and remove .o file
all: print.o
ifeq ($(no), )
	@echo Usage "make no=[leetcode question number]".
else
	@make -s $(no).o
	@$(CXX) $(CXXFLAGS) $(no).o print.o -o $(no)
	@rm $(no).o  # no need to remove print.o locally
endif

# Compile .o file
$(no).o: $(no).cpp
	@$(CXX) $(CXXFLAGS) -c $(no).cpp

print.o: print.cpp
	@$(CXX) $(CXXFLAGS) -c print.cpp

# Run .cpp files like python scripts
# Compile, build, and run a .cpp file and remove the executable file. 
.PHONY: run
run: all
	@./$(no)
	@rm $(no)

.PHONY: clean
clean:
	@rm *.o