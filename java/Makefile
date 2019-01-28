# Build an executable file named by argument "no" and remove .o file
all:
ifeq ($(no), )
	@echo Usage "make no=[leetcode question number]".
else
	@javac $(no).java
endif

# Run .java files like python scripts
# Compile, build, and run a .java file and remove the executable file.
.PHONY: run
run: all
	@java $(no)
	@rm $(no).class

.PHONY: clean
clean:
	@rm *.class
