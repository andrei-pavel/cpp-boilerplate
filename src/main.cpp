#include "config.hpp"

using std::string;

int main(int argc, char **argv) {
    Config::parseArguments(argc, argv);
    for (auto i : Config::get().node) {
        std::cout << i.first.as<string>() << " " << i.second.as<string>() << std::endl;
    }
    return 0;
}
