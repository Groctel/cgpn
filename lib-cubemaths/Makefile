# Directories

makedir = .

bin = $(makedir)/bin
doc = $(makedir)/doc
glb = $(makedir)/global
src = $(makedir)/src
tst = $(makedir)/tests
vec = $(makedir)/vecx

# Compiler options

includelist = -I$(makedir)
cxxcommon   = -std=c++17 $(includelist)
CXXFLAGS    = $(cxxcommon) -O3

ifdef dev
	CXXFLAGS = $(cxxcommon) -g -Wall -Wextra -Wpedantic -Wfloat-equal
endif

# GoogleTest options --> https://github.com/google/googletest

gtest      = /usr/include/gtest
gtestlibs  = /usr/lib/libgtest.so
gtestflags = -I$(gtest) $(gtestlibs)

# Phony rules

.PHONY: \
	all \
	build \
	clean \
	dev \
	directories \
	doc \
	full \
	test

all: directories build

build:
	@echo "TODO: Build library file."

clean:
	-@rm $(bin)/*
	-@find . -name "*.o" -exec rm {} +
	-@rm -r $(doc)/html
	-@rm -r $(doc)/latex

directories:
	@mkdir -p $(bin)

doc:
	@mkdir -p $(doc)
	@doxygen

full: clean directories test build

test: directories $(bin)/tests
	@$(bin)/tests --gtest_color=yes

# Building rules

$(bin)/tests: tests.cpp \
		$(glb)/functions.hpp \
		$(tst)/vec3.hpp $(vec)/vec3.tpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(gtestflags)
