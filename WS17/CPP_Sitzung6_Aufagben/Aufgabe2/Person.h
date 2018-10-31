class Person{
private:
    std::string name;
    std::string lastName;
    int age;

public:
    Person();

    void setName(std::string name);

    std::string getName();
};