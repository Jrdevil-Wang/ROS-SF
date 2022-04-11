LLVM_CONFIG=llvm-config-10
CXX=clang++

ifndef VERBOSE
QUIET:=@
endif

LDFLAGS+=$(shell $(LLVM_CONFIG) --ldflags) -lpthread -lncurses -lz
COMMON_FLAGS=-Wall -Wextra
CXXFLAGS+=$(COMMON_FLAGS) $(shell $(LLVM_CONFIG) --cxxflags)
CPPFLAGS+=$(shell $(LLVM_CONFIG) --cppflags) -I$(SRC_DIR)

TARGETS=sfm_conv
DEPS=

default: $(TARGETS)

%.o: %.cpp $(DEPS)
	@echo Compiling $*.cpp
	$(QUIET)$(CXX) -w -c $(CPPFLAGS) $(CXXFLAGS) $<

sfm_conv: sfm_conv.o
	@echo Linking $@
	$(QUIET)$(CXX) -o $@ $(CXXFLAGS) $(LDFLAGS) $^ `$(LLVM_CONFIG) --libs bitreader core support nativecodegen`

.PHONY:clean
clean:
	$(QUIET)rm -f *.o $(TARGETS)

