CC = g++
LINK.o = $(LINK.cc)
CXXFLAGS = -std=c++14 -Wall
LIB = kvstore.o memtable.o skiplist.o levelmanager.o sstable.o bits.o bloomfilter.o

all: correctness persistence analysis

correctness: $(LIB) correctness.o

persistence: $(LIB) persistence.o

analysis: $(LIB) analysis.o

.PHONY: clean

clean:
	-rm -f *.o *.exe correctness persistence analysis
