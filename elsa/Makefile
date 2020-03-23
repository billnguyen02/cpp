CXXFLAGS+= --std=c++17

all: elsa


elsa: main.o Store.o Customer.o Desktop.o Options.o Order.o *.h
	$(CXX) $(CXXFLAGS) main.o Store.o Customer.o Desktop.o Options.o Order.o -o elsa

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) main.cpp -c -o main.o

Store.o: Store.cpp *.h
	$(CXX) $(CXXFLAGS) Store.cpp -c -o Store.o 

Customer.o: Customer.cpp *.h
	$(CXX) $(CXXFLAGS) Customer.cpp -c -o Customer.o

Desktop.o: Desktop.cpp *.h
	$(CXX) $(CXXFLAGS) Desktop.cpp -c -o Desktop.o 

Options.o: Options.cpp *.h
	$(CXX) $(CXXFLAGS) Options.cpp -c -o Options.o 

Order.o: Order.cpp *.h
	$(CXX) $(CXXFLAGS) Order.cpp -c -o Order.o 

clean:
	-rm -f *.o *.gch 