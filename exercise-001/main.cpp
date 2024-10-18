#include <fmt/chrono.h>
#include <fmt/format.h>
#include <vector>
#include <random>
#include <iostream>

#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());

    /* INSERT YOUR CODE HERE */

    CLI::App app{"Random number generator"};
    int count = 20;

try
{
    app.add_option("-c,--count", count, "Number of random values")->default_val(20);

    app.parse(argc, argv);
     
}
catch (const CLI::ParseError &e)
{
    return app.exit(e);
}

    // Der Wert von count wird hier verwendet
    std::cout << "Count: " << count << std::endl;

    std::vector<int> values(count);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

    for (auto& value : values) {
        value = dist(gen);
    }

    // Zufallswerte ausgeben
    for (const auto& value : values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;


    
    return 0; /* exit gracefully*/
}


