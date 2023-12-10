#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

enum class Gender { Male, Female };

struct Person {
    std::string name;
    int age;
    std::string gender;

    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        return os << person.name << ',' << person.age << ',' << person.gender;
    }

    friend std::istream& operator>>(std::istream& is, Person& person) {
        std::string line;
        if (std::getline(is, line)) {
            std::istringstream obj(line);
            obj >> person.name >> person.age >> person.gender;
        }
        return is;
    }
};

void serializePersons(const std::vector<Person>& persons, std::ostream& os) {
    for (const auto& person : persons) {
        os << person << "\n";
    }
}

std::vector<Person> deserializePersons(std::istream& is) {
    std::vector<Person> persons;
    Person p;
    while (is >> p) {
        persons.push_back(p);
    }
    return persons;
}

int main() {
    std::vector<Person> persons;
    std::string name;
    int age;
    std::string genderInput;

    int numberOfPeople;
    std::cout << "Enter the number of people: ";
    std::cin >> numberOfPeople;

    for (int i = 0; i < numberOfPeople; ++i) {
        std::cout << "Enter name: ";
        std::cin >> name;

        std::cout << "Enter age: ";
        std::cin >> age;

        std::cout << "Enter gender (M/F): ";
        std::cin >> genderInput;

        persons.push_back({ name, age, genderInput });
    }

    std::ofstream outFile("persons.csv");
    serializePersons(persons, outFile);
    outFile.close();

    std::ifstream inFile("persons.csv");
    auto deserializedPersons = deserializePersons(inFile);

    return 0;
}