class Person {
private:
    std::string firstName;
    std::string lastName;
    std::string birthdate;
public:
    Person(std::string fn, std::string ln, std::string bd);

    const std::string &getFirstName() const;

    const std::string &getLastName() const;

    const std::string &getBirthdate() const;

    void setBirthdate(const std::string &birthdate);
};