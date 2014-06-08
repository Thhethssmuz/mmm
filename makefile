# build test executable to run unittests
TARGET   = tests

# dependencies
DEP1     = deps/backward-cpp
DEP1SRC  = $(DEP1)/backward.cpp
DEP1INC  = -I$(DEP1) 
DEP1FLGS = -ldw -DBACKWARD_HAS_DW=1

# directories
SRCDIRS  = $(shell find test -type d)
OBJDIRS  = $(SRCDIRS:test%=obj%)
INCDIRS  = -Isrc -Itest $(DEP1INC)

# files
SRC      = $(shell find test -name *.cpp)
OBJ      = $(SRC:test/%.cpp=obj/%.o) $(DEP1SRC)
DEP      = $(SRC:test/%.cpp=obj/%.d)

# Compiler and compile flags
CXX       = clang++
CXXFLAGS  = -std=c++11 -g -pedantic -MMD -Wall -W $(INCDIRS)

# Linker and link flags
LINKER   = clang++
LFLAGS   = $(DEP1FLGS)

all: $(TARGET)
	@echo "make: done"

$(TARGET): $(OBJ)
	@echo "make: linking $(TARGET)"
	@$(LINKER) $(LFLAGS) $(OBJ) -o $@

$(OBJDIRS):
	@echo "make: creating object folder $(subst obj/,,$@)"
	@mkdir -p $@

obj/%.d: test/%.cpp | $(OBJDIRS)
	@echo "make: generating dependencies for $(patsubst obj/%.d,%,$@)"
	@$(CXX) $(CXXFLAGS) -MM -MT '$(patsubst test/%.cpp,obj/%.o,$<)' $< -MF $@

ifeq (0, $(words $(findstring $(MAKECMDGOALS), "run")))
-include $(DEP)
endif

obj/%.o: test/%.cpp obj/%.d test/%.hpp
	@echo "make: compiling $(patsubst obj/%.o,%,$@)"
	@$(CXX) $(CXXFLAGS) -c -o $@ $<

obj/%.o: test/%.cpp obj/%.d
	@echo "make: compiling $(patsubst obj/%.o,%,$@)"
	@$(CXX) $(CXXFLAGS) -c -o $@ $<


# Make options
LONETEST = obj/swizzle/opr/asig.o

run_tests: obj/main.o obj/unittest.o $(LONETEST)
	@echo "make: linking $(TARGET)"
	@$(LINKER) $(LFLAGS) obj/main.o obj/unittest.o $(LONETEST) -o $(TARGET)

run: 
	@echo "make: running $(TARGET)"
	@echo
	@./$(TARGET)
	@echo
	@echo "make: done"
