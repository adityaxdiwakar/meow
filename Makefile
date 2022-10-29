.PHONY: help

.DEFAULT_GOAL: build

build:
	g++ src/*.cpp -lncurses -o meow

run:
	./meow

dev: build run
