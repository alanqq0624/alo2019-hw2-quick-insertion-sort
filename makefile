CC := g++ -std=c++11
CXXFLAGS += -O3 -Wall

QUICK := quick_sort
INSERT := insert_sort
MIX := mix_quick_insert_sort

ASTYLE := astyle --style=kr --indent=spaces=4 --suffix=none
ASTYLEFLAGS := --style=kr --indent=spaces=4 --suffix=none
CPPCHECK := cppcheck -I. --error-exitcode=1 .

$(PRE):
	$(CPPCHECK)
	astyle $(ASTYLEFLAGS) $(QUICK).cpp
	astyle $(ASTYLEFLAGS) $(INSERT).cpp
	astyle $(ASTYLEFLAGS) $(MIX).cpp

all: 
	$(PRE)
	$(CC) -o $(QUICK) $(CXXFLAGS) $(QUICK).cpp
	$(CC) -o $(INSERT) $(CXXFLAGS) $(INSERT).cpp
	$(CC) -o $(MIX) $(CXXFLAGS) $(MIX).cpp

debug:
	$(PRE)
	$(CC) -o $(QUICK) $(CXXFLAGS) -g $(QUICK).cpp
	$(CC) -o $(INSERT) $(CXXFLAGS) -g $(INSERT).cpp
	$(CC) -o $(MIX) $(CXXFLAGS) -g $(MIX).cpp

style: $(SOURCES:.cpp=.astyle-check-stamp)
	$(PRE)

.PHONY: clean

clean:
	rm -rf $(QUICK) $(INSERT) $(MIX)