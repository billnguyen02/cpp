CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: mainwin

debug: CXXFLAGS += -g
debug: mainwin

mainwin: main.o mainwin.o Store.o Customer.o Desktop.o Options.o Order.o entrydialog.o Ram.o cpu.o
	$(CXX) $(CXXFLAGS) main.o mainwin.o Store.o Customer.o Desktop.o Options.o Order.o entrydialog.o Ram.o cpu.o $(GTKFLAGS) -o mainwin

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o

Store.o: Store.cpp *.h
	$(CXX) $(CXXFLAGS) Store.cpp -c -o Store.o 

entrydialog.o: entrydialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c entrydialog.cpp $(GTKFLAGS) -o entrydialog.o 

Customer.o: Customer.cpp *.h
	$(CXX) $(CXXFLAGS) Customer.cpp -c -o Customer.o

Desktop.o: Desktop.cpp *.h
	$(CXX) $(CXXFLAGS) Desktop.cpp -c -o Desktop.o 

Options.o: Options.cpp *.h
	$(CXX) $(CXXFLAGS) Options.cpp -c -o Options.o 

Order.o: Order.cpp *.h
	$(CXX) $(CXXFLAGS) Order.cpp -c -o Order.o 

Ram.o: Ram.cpp *.h
	$(CXX) $(CXXFLAGS) Ram.cpp -c -o Ram.o

cpu.o: cpu.cpp *.h
	$(CXX) $(CXXFLAGS) cpu.cpp -c -o cpu.o	
clean:
	rm -f *.o *.gch mainwin
