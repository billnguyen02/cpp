#include "polynomial.h"
#include "logger.h"
#include <fstream>
#include <iomanip>
#include <chrono>
#include <thread>
int main() {
    // BONUS: Modify main() to load and solve multiple polynomials
    //    simultaneously using a set of threads for each polynomial.
    //    Note that this will break "make poly", so if you want to
    //    preserve the threadless build, handle that situation, too.

    // Working variables
    double c, e, x;
    int nthreads = 1; // number of threads
   // Polynomial f;
    int choice;
    Polynomial f;
    // Load a default polynomial if available
    std::string filename = "untitled.poly";
    std::vector < std::string> str;
    str.push_back("untitled.poly");
    str.push_back("poly2.poly");

    std::vector <Polynomial> Po;
    for(int i = 0; i < 2; i ++)
    {
        try {

                std::ifstream ifs{str.at(i)};
                if(!ifs) throw std::runtime_error{"file not found"};
                Po.push_back( Polynomial(ifs));
                std::cout << "Loaded ";
            
            
        } catch(std::exception& e) {
            std::cout << "Failed to load";
        }

        std::cout << str.at(i) << ": " << Po.at(i) << std::endl;
    }   
    
    std::string menu = R"(

   Polynomial Paradise
   ========== ========

1) Load or Enter Polynomial
2) Save Polynomial
3) Evaluate Polynomial
4) Solve Polynomial
0) Exit

==> )";

    // =============================================================
    // Main loop
    do {
        
        std::cout << menu;
        std::cin >> choice; std::cin.ignore(32767, '\n');

        if(choice == 1) {

            std::cout << "Filename (blank to enter by hand): ";
            std::getline(std::cin, filename);
            if(filename.empty()) {
                f = Polynomial{};
                do {
                    std::cout << "Enter coefficient then exponent: ";
                    std::cin >> c >> e;
                    f.add_term(c, e);
                } while(e != 0.0);
            } else {
                try {
                    std::ifstream ifs{filename};
                    f = Polynomial(ifs);
                    std::cout << "Loaded " << filename << ": " << f << std::endl;
                } catch(std::exception& e) {
                    std::cerr << "Could not load " << filename << ": " 
                      << e.what() << std::endl;
                }
            }
        } else if(choice == 2) {
            std::cout << "Filename: ";
            std::getline(std::cin, filename);
            if(filename.size()) {
                 try {
                    std::ofstream ofs{filename};
                    f.save(ofs);
                    std::cout << "Saved " << filename << ": " << f << std::endl;
                } catch(std::exception& e) {
                    std::cerr << "Could not save " << filename << ": " 
                      << e.what() << std::endl;
                }
            }
        } else if(choice == 3) {
            do {
                std::cout << "Enter x (0 exits): ";
                std::cin >> x;
                std::cout << "f(" << x << ") = " << f(x) << std::endl;
            } while (x != 0.0);
       } else if(choice == 4) {
            std::cout << "Solve between min max (== exits): ";
            std::cin >> c >> e; if(c >= e) break;
            std::cout << "Number of threads: ";
            std::cin >> nthreads;
            std::thread t[2];
            LOG("   MAIN: Ready to solve");
            for (int i = 0; i < 2; i ++)
            {
                
                    Polynomial* ptr = Po.at(i).get_ptr();
                    auto start = std::chrono::high_resolution_clock::now();                    
                    t[i] =  std::thread {[=]{ptr->solve(c, e, nthreads);}};
                    auto stop = std::chrono::high_resolution_clock::now();
                    LOG("   MAIN: Solved!");
                    std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::seconds>(stop - start).count() << " seconds\n";
                    std::vector<double> roots = Po.at(i).roots();
                
                if(roots.empty()) {
                    std::cout << "No roots found!\n";
                } else {
                    std::ios cout_state(nullptr);
                    cout_state.copyfmt(std::cout);
                    std::cout << std::fixed << std::setprecision(16);

                    std::cout << "\nx = \n";
                    for(double r : roots) {
                        std::cout << "    " << std::setw(21) << r << " f(x) = " << std::setw(21) << f(r) << std::endl;
                    }
                    std::cout.copyfmt(cout_state);
                 }
            }
            for(int i = 0; i < 2; i++)
            {
                t[i].join();
            }
        } else {
            if(choice != 0) std::cerr << "INVALID CHOICE\n";
        }
    } while(choice != 0);
}
        
