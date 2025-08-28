#include "../include/Astra.hpp"
using namespace std;

int main(int argc, char const *argv[]) {
     try {
          Application app("Astra Engine", 1280, 720);
          app.run();
     } catch (const std::exception& e) {
          std::cerr << e.what() << std::endl;
          return -1;
     }
     return 0;
}

// There is no editorial office