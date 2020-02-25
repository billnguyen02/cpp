CXXFLAGS = --std=c++17

all: store

store: main.o product.o tax.o taxfree.o
	$(CXX) $(CXXFLAGS) main.o product.o tax.o taxfree.o -o store

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) main.cpp -c -o main.o

product.o: product.cpp *.h
	$(CXX) $(CXXFLAGS)  product.cpp -c -o product.o

tax.o: tax.cpp *.h
	$(CXX) $(CXXFLAGS) tax.cpp -c -o tax.o

taxfree.o: taxfree.cpp *.h
	$(CXX) $(CXXFLAGS) taxfree.cpp -c -o taxfree.o

clean:
	rm -f *.o *.gch ~* a.out store
