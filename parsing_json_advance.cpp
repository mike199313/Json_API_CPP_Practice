#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    // Read the JSON file into a JSON object
    auto file = std::ifstream("example.json");
    if (!file.is_open()) {
        std::cerr << "Unable to open the file" << std::endl;
        return 1;
    }

    json j;
    file >> j;

    // Extract data using modern C++ features
    const auto& name = j.at("name").get_ref<const std::string&>();
    int age = j.at("age").get<int>();
    bool is_student = j.at("is_student").get<bool>();

    const auto& courses = j.at("courses");
    const auto& address = j.at("address");

    // Output the data
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Is Student: " << (is_student ? "Yes" : "No") << std::endl;

    std::cout << "Courses:" << std::endl;
    for (const auto& course : courses) {
        const auto& course_name = course.at("name").get_ref<const std::string&>();
        const auto& course_grade = course.at("grade").get_ref<const std::string&>();
        std::cout << "  Course Name: " << course_name << ", Grade: " << course_grade << std::endl;
    }

    std::cout << "Address:" << std::endl;
    const auto& street = address.at("street").get_ref<const std::string&>();
    const auto& city = address.at("city").get_ref<const std::string&>();
    const auto& zip = address.at("zip").get_ref<const std::string&>();
    std::cout << "  Street: " << street << std::endl;
    std::cout << "  City: " << city << std::endl;
    std::cout << "  ZIP: " << zip << std::endl;

    return 0;
}

