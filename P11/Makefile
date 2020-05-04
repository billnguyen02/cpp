CXXFLAGS += --std=c++17

all: cart

cart: main.o Cart.o Item.o
	$(CXX) $(CXXFLAGS) main.o Cart.o Item.o -o cart
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) main.cpp -c -o main.o
Item.o: Item.cpp *h
	$(CXX) $(CXXFLAGS) Item.cpp -c -o Item.o
Cart.o: Cart.cpp *h
	$(CXX) $(CXXFLAGS) Cart.cpp -c -o Cart.o
clean:
	rm -f *.o *.gch ~* a.out cart