FILE=test_all.cc test_all2.cc test_all3.cc
CXX=g++
CXXFLAGS=-W -Wall -std=c++0x
LFLAGS=
LIB_SRC=../junction.h
INCLUDE=-I ..
EXE=$(FILE:.cc=)
OBJ=$(FILE:.cc=.o)

all: $(EXE)


$(EXE): $(OBJ)
	$(CXX) $(LFLAGS) -o $@ $@.o

.cc.o: $(LIB_SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c -o $@ $<

clean:
	rm $(OBJ)

distclean: clean
	rm $(EXE)
