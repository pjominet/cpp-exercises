class ClPerson {
private:
    char vorname[100];
    char nachname[100];
    char patronym[100];
    char middlename[100];
    char titel[100];
    char herkunft;

public:
    void askEnglish(ClPerson *partner);

    void frageDeutsch(ClPerson *partner);

    void greetEnglish(ClPerson *partner);

    void gruesseDeutsch(ClPerson *partner);
};




