#ifndef _CONFIG
#define _CONFIG

#include <cxxopts.hpp>
#include <yaml-cpp/yaml.h>

struct Config {
    static Config& get() {
        static Config* instance = new Config();
        return *instance;
    }

    static void parseArguments(int& argc, char**& argv) {
        cxxopts::Options options("cpp-boilerplate", "simple C++ boilerplate");
        options.add_options()  //
            ("h,help", "show usage")  //
            ("c,config", "specify YAML configuration file", cxxopts::value<std::string>());
        auto result = options.parse(argc, argv);
        if (result.count("help") > 0) {
            std::cout << options.help() << std::endl;
            exit(0);
        }
        if (result.count("config") > 0) {
            configure(result["config"].as<std::string>());
        }
    }

    YAML::Node node;

private:
    Config() {
    }
    Config(Config const&);
    Config& operator=(Config const&);

    static void configure(std::string const& config) {
        YAML::Node config_node = YAML::LoadFile(config);
        Config::get().node = config_node["data"];
    }
};

#endif  // _CONFIG
