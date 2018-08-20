all: 
ifeq ($(no), )
	@echo Usage "make no=[leetcode question number]".
else
	@go build $(no).go
endif

.PHONY: run
run: all
	@./$(no)
	@rm $(no)
