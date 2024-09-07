#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    // Open the JSON file
    std::ifstream file("example.json");
    if (!file.is_open()) {
        std::cerr << "Unable to open the file" << std::endl;
        return 1;
    }

    // Parse the JSON file
    json j;
    file >> j;

    // Accessing the data
    std::string name = j["name"];
    int age = j["age"];
    bool is_student = j["is_student"];
    auto courses = j["courses"];
    auto address = j["address"];

    // Output the data
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Is Student: " << (is_student ? "Yes" : "No") << std::endl;

    std::cout << "Courses:" << std::endl;
    for (const auto& course : courses) {
        std::cout << "  Course Name: " << course["name"] << ", Grade: " << course["grade"] << std::endl;
    }

    std::cout << "Address:" << std::endl;
    std::cout << "  Street: " << address["street"] << std::endl;
    std::cout << "  City: " << address["city"] << std::endl;
    std::cout << "  ZIP: " << address["zip"] << std::endl;

    return 0;
}

