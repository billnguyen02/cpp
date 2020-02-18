
CXXFLAGS = --std=c++17 
all: coin
debug: CXXFLAGS += -g
debug: coin

logger: CXXFLAGS += -DLOGGER
logger: coin


coin: main.o coin.o 
	$(CXX) $(CXXFLAGS)  main.o coin.o -o coin
main.o:main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp  -o main.o
coin.o: coin.cpp
	$(CXX) $(CXXFLAGS) -c coin.cpp   -o coin.o
coin.gch: coin.h
	$(CXX) $(CXXFLAGS) -c coin.h -o coin.gch
logger.gch: logger.h
	$(CXX) $(CXXFLAGS) -c logger.h -o logger.gch
clean:
	rm -f *.o *.gch ~* a.out coin