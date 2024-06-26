###############################################################################
#  University of Hawaii, College of Engineering
#  Lab D - Lucky Cat - EE 205 (Object Oriented Programming) - Spr 2024
#
#  Cats make their own luck
#
## Build and test a lottery simulation program
##
## @see     https://www.gnu.org/software/make/manual/make.html
##
## @file   Makefile
## @author Mark Nelson <marknels@hawaii.edu>
###############################################################################

TARGET = boost_tests

all:  $(TARGET)

CXX       = clang++
# Boost tests compile-run faster without -DBOOST_TEST_DYN_LINK
# CXXFLAGS  = -std=c++17 -Wall -Wextra -Werror -march=native -mtune=native -DTARGET=\"$(TARGET)\" $(DEBUG_FLAGS)
CXXFLAGS  = -std=c++17 -Wall -Wextra -march=native -mtune=native -DTARGET=\"$(TARGET)\" $(DEBUG_FLAGS)
LDLIBS    = -lboost_system -lboost_thread -lboost_unit_test_framework
LINT      = clang-tidy
LINTFLAGS = --quiet -extra-arg=-std=c++17

debug: DEBUG_FLAGS = -g -DDEBUG -O0
debug: clean $(TARGET)

test:     CXXFLAGS += -DTESTING
valgrind: CXXFLAGS += -DTESTING -g -O0 -fno-inline -march=x86-64 -mtune=generic

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
TEST_OBJS = $(filter-out ../Sim.o, $(wildcard ../*.o))

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $<

$(TARGET): $(OBJ) $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(TEST_OBJS) $(LDLIBS)

lint: $(TARGET)
	$(LINT) $(LINTFLAGS) $(SRC) --

test: $(TARGET)
	sudo ./$(TARGET) --build_info --color_output --show_progress --report_format=HRF --report_level=short

valgrind: $(TARGET)
	sudo DEBUGINFOD_URLS="https://debuginfod.archlinux.org"                    \
	valgrind --leak-check=full --track-origins=yes --error-exitcode=1 --quiet  \
	./$(TARGET) --build_info --color_output --show_progress --report_format=HRF --report_level=short

clean:
	rm -f $(TARGET) *.o
