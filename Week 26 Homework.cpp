#include <windows.h>
#include <iostream>
#include <string>   // getline()

using namespace std;


class Telescope
{
private:
    char* brand = nullptr;           // �������� �� �����
    char* model = nullptr;           // �������� �� ������
    char* opticalDesign = nullptr;   // �������� �� ������� �����������
    char* aperture = nullptr;        // �������� �� ������ ��'������
    char* focalLength = nullptr;     // �������� �� ������� �������
    char* mountType = nullptr;       // �������� �� ��� ����������
    char* eyepiece = nullptr;        // �������� �� ���� �������
    char* filter = nullptr;          // �������� �� �����������
    char* skyObject = nullptr;       // �������� �� ������� ���
    bool isAimed;    // �� �������� �������� �� ��'���?
    bool isFocused;  // �� �������� �����������?

    // ��������� ����� ����������� ��� �����������
    void InitTelescope(const string& brand = "Celestron",
        const string& model = "PowerSeeker 70 AZ",
        const string& opticalDesign = "���������",
        const string& aperture = "70 ��",
        const string& focalLength = "70 ��",
        const string& mountType = "�����������",
        const string& eyepiece = "20 �� (35x), 1,25\"",
        const string& filter = "³������",
        const string& skyObject = "̳����")
    {
        this->brand = new char[brand.length() + 1];
        // https://en.cppreference.com/w/c/string/byte/strcpy
        strcpy_s(this->brand, brand.length() + 1, brand.c_str());
        // https://cplusplus.com/reference/string/string/c_str/

        this->model = new char[model.length() + 1];
        strcpy_s(this->model, model.length() + 1, model.c_str());

        this->opticalDesign = new char[opticalDesign.length() + 1];
        strcpy_s(this->opticalDesign, opticalDesign.length() + 1,
            opticalDesign.c_str());

        this->aperture = new char[aperture.length() + 1];
        strcpy_s(this->aperture, aperture.length() + 1, aperture.c_str());

        this->focalLength = new char[focalLength.length() + 1];
        strcpy_s(this->focalLength, focalLength.length() + 1,
            focalLength.c_str());

        this->mountType = new char[mountType.length() + 1];
        strcpy_s(this->mountType, mountType.length() + 1, mountType.c_str());

        this->eyepiece = new char[eyepiece.length() + 1];
        strcpy_s(this->eyepiece, eyepiece.length() + 1, eyepiece.c_str());

        this->filter = new char[filter.length() + 1];
        strcpy_s(this->filter, filter.length() + 1, filter.c_str());

        this->skyObject = new char[skyObject.length() + 1];
        strcpy_s(this->skyObject, skyObject.length() + 1, skyObject.c_str());

        isAimed = false;
        isFocused = false;
    }

public:

    // ����������� �� �������������
    Telescope()
    {
        InitTelescope();
    }


    // ����������� �� �����������
    Telescope(const string& brand, const string& model,
        const string& opticalDesign, const string& aperture,
        const string& focalLength, const string& mountType,
        const string& eyepiece, const string& filter, const string& skyObject)
    {
        InitTelescope(brand, model, opticalDesign, aperture, focalLength,
            mountType, eyepiece, filter, skyObject);
    }


    // ����������� ���������
    Telescope(const Telescope& other)
    {
        InitTelescope(other.brand, other.model, other.opticalDesign,
            other.aperture, other.focalLength, other.mountType,
            other.eyepiece, other.filter, other.skyObject);
        this->isAimed = other.isAimed;
        this->isFocused = other.isFocused;
    }


    // ����������
    ~Telescope()
    {
        delete[] brand;
        delete[] model;
        delete[] opticalDesign;
        delete[] aperture;
        delete[] focalLength;
        delete[] mountType;
        delete[] eyepiece;
        delete[] filter;
        delete[] skyObject;
    }


    // ������� ��� ���������

    void SetBrand(const string& brand)
    {
        if (brand.empty()) throw string("������ ��������� ����� ���������!");
        delete[] this->brand;
        this->brand = new char[brand.length() + 1];
        strcpy_s(this->brand, brand.length() + 1, brand.c_str());
    }

    void SetModel(const string& model)
    {
        if (model.empty()) throw string("������ ��������� ������ ���������!");
        delete[] this->model;
        this->model = new char[model.length() + 1];
        strcpy_s(this->model, model.length() + 1, model.c_str());
    }

    void SetOpticalDesign(const string& opticalDesign)
    {
        if (opticalDesign.empty()) throw string("��������� �� ���������?..");
        delete[] this->opticalDesign;
        this->opticalDesign = new char[opticalDesign.length() + 1];
        strcpy_s(this->opticalDesign, opticalDesign.length() + 1,
            opticalDesign.c_str());
    }

    void SetAperture(const string& aperture)
    {
        if (aperture.empty())
            throw string("���� �����, ������ ������ ��'������ � ��������");
        delete[] this->aperture;
        this->aperture = new char[aperture.length() + 1];
        strcpy_s(this->aperture, aperture.length() + 1, aperture.c_str());
    }

    void SetFocalLength(const string& focalLength)
    {
        if (focalLength.empty())
            throw string("���� �����, ������ ������� ������� ��������� "
                "� ��������, �����������, ������!..");
        delete[] this->focalLength;
        this->focalLength = new char[focalLength.length() + 1];
        strcpy_s(this->focalLength, focalLength.length() + 1,
            focalLength.c_str());
    }

    void SetMountType(const string& mountType)
    {
        if (mountType.empty())
            throw string("���������� �����������, ������������, �������, "
                "���������, ������������-�����������?..");
        delete[] this->mountType;
        this->mountType = new char[mountType.length() + 1];
        strcpy_s(this->mountType, mountType.length() + 1, mountType.c_str());
    }

    void SetEyepiece(const string& eyepiece)
    {
        if (eyepiece.empty()) throw string("��������� � ����������� ��������");
        delete[] this->eyepiece;
        this->eyepiece = new char[eyepiece.length() + 1];
        strcpy_s(this->eyepiece, eyepiece.length() + 1, eyepiece.c_str());
        this->isFocused = false;
    }

    void SetterFilter(const string& filter)
    {
        if (filter.empty())
            throw string("����������� ��� ����� ���� ������������.");
        delete[] this->filter;
        this->filter = new char[filter.length() + 1];
        strcpy_s(this->filter, filter.length() + 1, filter.c_str());
    }

    void SetSkyObject(const string& skyObject)
    {
        if ((skyObject == "�����" || skyObject == "The Sun" ||
            skyObject == "Sun") && strcmp(this->filter, "��������") != 0)
            // https://en.cppreference.com/w/c/string/byte/strcmp.html
            throw string("ͳ���� �� ������� �� ����� ��� ������������ "
                "��������� ������������ � �� ���� ����������!"
                " �������� � �������������� ����� ������� �� �����.");
        delete[] this->skyObject;
        this->skyObject = new char[skyObject.length() + 1];
        strcpy_s(this->skyObject, skyObject.length() + 1, skyObject.c_str());
    }


    void SetIsAimed(bool isAimed = true)
    {
        this->isAimed = isAimed;
    }

    void SetIsFocused(bool isFocused = true)
    {
        this->isFocused = isFocused;
    }


    // ������� ��� ���������

    string GetBrand() const { return string(brand); }

    string GetModel() const { return string(model); }

    string GetOpticalDesign() const { return string(opticalDesign); }

    string GetAperture() const { return string(aperture); }

    string GetFocalLength() const { return string(focalLength); }

    string GetMountType() const { return string(mountType); }

    string GetEyepiece() const { return string(eyepiece); }

    string GetFilter() const { return string(filter); }

    string GetSkyObject() const { return string(skyObject); }

    bool GetIsAimed() const { return this->isAimed; }

    bool GetIsFocused() const { return this->isFocused; }


    // ����� ��� ������������ ������������� ���������
    void InputTelescopeData()
    {
        system("cls");
        cout << "\t�������������: ����� �� ������в��� ������ ����\n\n";

        string input;  // �������� ����� ��� ���������� ��������� ������

        cout << "���� ��������? ������ �����: ";
        getline(cin, input);
        if (!input.empty()) SetBrand(input);

        cout << "������ ������ ���������: ";
        getline(cin, input);
        if (!input.empty()) SetModel(input);

        cout << "������ ������� ������� �����������: ";
        getline(cin, input);
        if (!input.empty()) SetOpticalDesign(input);

        cout << "������ ������ ��'������ (�������� �������): ";
        getline(cin, input);
        if (!input.empty()) SetAperture(input);

        cout << "������ ������� ������� (�������� �������): ";
        getline(cin, input);
        if (!input.empty()) SetFocalLength(input);

        cout << "������ ��� ����������: ";
        getline(cin, input);
        if (!input.empty()) SetMountType(input);
    }


    // ����� ��� ��������� �� ������������ ��'���
    void AimAtObject(const string& skyObject)
    {
        SetSkyObject(skyObject);
        this->isAimed = true;
    }


    // ����� ��� �����������
    void FocusTelescope()
    {
        if (this->isAimed) this->isFocused = true;
    }


    // ����� ��� ����� �������
    void ChangeEyepiece(const string& otherEyepiece)
    {
        delete[] this->eyepiece;
        this->eyepiece = new char[otherEyepiece.length() + 1];
        strcpy_s(this->eyepiece, otherEyepiece.length() + 1,
            otherEyepiece.c_str());
        isFocused = false;
    }


    // ����� ��� ������������ ������������
    void SetFilter(const string& newFilter)
    {
        delete[] this->filter;
        this->filter = new char[newFilter.length() + 1];
        strcpy_s(this->filter, newFilter.length() + 1, newFilter.c_str());
    }


    // ����� ��� ��������� �񳺿 ���������� �� ����� ��
    void PrintInfo(const string& comment) const
    {
        system("cls");
        cout << "\t�������� - ������ ������������ �������� ����\n\n";
        cout << "��������: " << GetBrand() << " " << GetModel() << "\n";
        cout << "������� �����������: " << GetOpticalDesign() << "\n";
        cout << "ĳ����� ��'������: " << GetAperture() << "\n";
        cout << "������� �������: " << GetFocalLength() << "\n";
        cout << "��� ����������: " << GetMountType() << "\n";
        cout << "\n������: " << GetEyepiece() << "\n";
        cout << "�����������: " << GetFilter() << "\n";
        cout << "\n�������� " << (GetIsAimed() ? "�������� �� " +
            GetSkyObject() + "." :
            "�� �� ��������, ������������� �������!") << "\n";
        cout << "����������� " << (GetIsFocused() ? "��������!" :
            "�� �� ��������!") << "\n";
        cout << "\n\n��������: " << comment << "\n";
    }
};


class WaterBottle
{
private:

    string* brand;               // �������� �� �����
    string* producer;            // �������� �� �����-��������
    float* capacity;             // �������� �� ��'�� ������
    float* currentVolume;        // �������� �� �������� ����� ����
    string* expirationDate;      // �������� �� ������ ���� ����������
    string* mineralization;      // �������� �� ����������� ����
    string* material;            // �������� �� ������� ������
    bool isExpired = false;      // �� ����� ���������� ���������?
    bool isOpened = false;       // �� �������� ������?
    bool isBeingPoured = false;  // �� ���������� ����?
    bool isWiped = false;        // �� ������ ��� ��������� ���������?

    // ��������� ����� ����������� ��� �����������
    void InitWaterBottle(const string& brand = "����������",
        const string& producer = "����������� ����� ���������� ��� \"�����\"",
        const float& capacity = 6.0f,
        const float& currentVolume = 6.0f,
        const string& expirationDate = "02.11.25",
        const string& mineralization = "0,1-0,4 �/�",
        const string& material = "�������")
    {
        this->brand = new string(brand);
        this->producer = new string(producer);
        this->capacity = new float(capacity);
        this->currentVolume = new float(currentVolume);
        this->expirationDate = new string(expirationDate);
        this->mineralization = new string(mineralization);
        this->material = new string(material);
        isExpired = false;
        isOpened = false;
        isBeingPoured = false;
        isWiped = false;
    }


public:

    // ����������� �� �������������
    WaterBottle()
    {
        InitWaterBottle();
    }


    // ����������� �� �����������
    WaterBottle(const string& brand, const string& producer,
        const float& capacity, const float& currentVolume,
        const string& expirationDate, const string& mineralization,
        const string& material)
    {
        InitWaterBottle(brand, producer, capacity, currentVolume,
            expirationDate, mineralization, material);
    }


    // ����������� ���������
    WaterBottle(const WaterBottle& other)
    {
        InitWaterBottle(*other.brand, *other.producer, *other.capacity,
            *other.currentVolume, *other.expirationDate,
            *other.mineralization, *other.material);
        this->isExpired = other.isExpired;
        this->isOpened = other.isOpened;
        this->isBeingPoured = other.isBeingPoured;
        this->isWiped = other.isWiped;
    }


    // ����������
    ~WaterBottle()
    {
        delete brand;
        delete producer;
        delete capacity;
        delete currentVolume;
        delete expirationDate;
        delete mineralization;
        delete material;
    }


    // ������� ��� ���������

    void SetBrand(const string& brand)
    {
        if (!brand.empty()) *this->brand = brand;
    }

    void SetProducer(const string& producer)
    {
        if (!producer.empty()) *this->producer = producer;
    }

    void SetCapacity(float capacity)
    {
        if (capacity < 1.0 || capacity > 25.0)
            throw string("��'�� ������ �� ���� � ����� 1 - 25 ����!");
        *this->capacity = capacity;
        if (*this->currentVolume > *this->capacity)
            *this->currentVolume = *this->capacity;
    }

    void SetCurrentVolume(float currentVolume)
    {
        if (currentVolume < 0 || currentVolume > *this->capacity)
            throw string("�������� ��'�� ���� � ����� �� ���� � ����� "
                "�� 0 �� ����������� ������ ������!");
        *this->currentVolume = currentVolume;
    }

    void SetExpirationDate(const string& expirationDate)
    {
        if (expirationDate.length() != 8 || expirationDate[2] != '.' ||
            expirationDate[5] != '.')
            throw string("���� �� ���� ������� ���������� � ������"
                " ��.��.�� �� ��������� ����� ��������!");
        *this->expirationDate = expirationDate;
    }

    void SetMineralization(const string& mineralization)
    {
        if (!mineralization.empty()) *this->mineralization = mineralization;
    }

    void SetMaterial(const string& material)
    {
        if (material != "�������" && material != "�������" &&
            material != "����" && material != "����" &&
            material != "��������� �����" && material != "��������� �����" &&
            material != "�������� �������" && material != "�������� �������")
            throw string("������� ��������� ������� ��� ��������� ����!");
        *this->material = material;
    }


    void SetIsExpired(bool isExpired = true)
    {
        this->isExpired = isExpired;
    }

    void SetIsOpened(bool isOpened = true)
    {
        this->isOpened = isOpened;
    }

    void SetIsBeingPoured(bool isBeingPoured = true)
    {
        this->isBeingPoured = isBeingPoured;
    }

    void SetIsWiped(bool isWiped = true)
    {
        this->isWiped = isWiped;
    }


    // ������� ��� ���������

    string GetBrand() const { return *this->brand; }

    string GetProducer() const { return *this->producer; }

    float GetCapacity() const { return *this->capacity; }

    float GetCurrentVolume() const { return *this->currentVolume; }

    string GetExpirationDate() const { return *this->expirationDate; }

    string GetMineralization() const { return *this->mineralization; }

    string GetMaterial() const { return *this->material; }

    bool GetIsExpired() const { return isExpired; }

    bool GetIsOpened() const { return isOpened; }

    bool GetIsBeingPoured() const { return isBeingPoured; }

    bool GetIsWiped() const { return isWiped; }


    // ����� ��� �������� ������������� ������
    void InputBottleData()
    {
        system("cls");
        cout << "\t�������������: ����� ����\n\n";

        string input;

        cout << "������ ������ �����: ";
        getline(cin, input);
        if (!input.empty()) SetBrand(input);

        cout << "������ �����-��������: ";
        getline(cin, input);
        if (!input.empty()) SetProducer(input);

        cout << "������ ��'�� ������: ";
        cin >> *this->capacity;
        cin.ignore();

        cout << "������ ������ ���� ���������� � ������ ��.��.��: ";
        getline(cin, input);
        if (!input.empty()) SetExpirationDate(input);

        cout << "�������� ����� ����������� ����: ";
        getline(cin, input);
        if (!input.empty()) SetMineralization(input);

        cout << "�������� ������� ������: ";
        getline(cin, input);
        if (!input.empty()) SetMaterial(input);
    }


    // ����� ��� �������� ������ ����������
    void CheckExpiration()
    {
        // �������� �������� ��� � �������� � 1970-01-01 (epoch time)
        time_t now = time(nullptr);
        // https://learn.microsoft.com/ru-ru/cpp/c-runtime-library/reference/time-time32-time64?view=msvc-170
        // ������������ ������� ����� � ��������� ���
        struct tm localTime;
        localtime_s(&localTime, &now);
        // https://learn.microsoft.com/ru-ru/cpp/c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s?view=msvc-170

        // ������ �� ���������� ���� - ������ ����, �����, ��:
        int todayDay = localTime.tm_mday;
        int todayMonth = localTime.tm_mon + 1; // tm_mon ���������� � 0
        int todayYear = localTime.tm_year + 1900; // ���� � 1900

        // ������������ ������ ���� ����������, �������������� ����� ���
        // ��������� ������� �� ������� ��� ������������ ����� �� �����
        int day = stoi(expirationDate->substr(0, 2));
        int month = stoi(expirationDate->substr(3, 2));
        int year = stoi(expirationDate->substr(6, 2)) + 2000;

        // ��������� ������ ����� "�����������"
        this->isExpired = year < todayYear ||
            (year == todayYear && month < todayMonth) ||
            (year == todayYear && month == todayMonth && day < todayDay + 2);
    }


    // ����� ��� ���������� ������
    void OpenBottle()
    {
        if (!this->isExpired) this->isOpened = true;
    }


    // ����� ��� �������� ������
    void CloseBottle()
    {
        this->isBeingPoured = false;
        this->isOpened = false;
    }


    // ����� ��� ��������� ���� (�� 3 � �� ���)
    void PourWater()
    {
        if (this->isOpened && *this->currentVolume >= 3.0)
        {
            this->isBeingPoured = true;
            *this->currentVolume -= 3.0;
        }
        else
        {
            this->isBeingPoured = false;
            cout << "���� ����� ����!" << "\n";
        }
    }


    // ����� ��� ���������� ������ ���������
    void WipeBottle()
    {
        this->isWiped = true;
    }


    // ����� ��� ��������� ���������� ��� ������
    void PrintInfo(const string& comment) const
    {
        system("cls");
        cout << "\t���� ������ ����\n\n";
        cout << "����� ���� ��� ��������� ��������: " << *this->brand << "\n";
        cout << "��������: " << *this->producer << "\n";
        cout << "��'��: " << *this->capacity << "\n";
        cout << "����� ��: " << *this->expirationDate << "\n";
        cout << "̳���������� ����: " << *this->mineralization << "\n";
        cout << "������� ������: " << *this->material << "\n";
        cout << "\n������ " << (this->isWiped ?
            "��������� ������� ���������!" : "�� �� ���������") << "\n";
        cout << (this->isExpired ? "����� ���������� ���������!" :
            "����� ���������� �� �� ���������") << "\n";
        cout << "������ " << (this->isOpened ? "��������!" :
            "��������") << "\n";
        cout << "�������� ����� ����: " << *this->currentVolume << " �\n";
        cout << (this->isBeingPoured ? "�������� ����!" : "") << "\n";
        cout << "\n��������: " << comment << "\n";
    }
};


class GetterShowCaseTask
{
public:

    static void DisplayTelescopeFields(const Telescope* telescope)
    {
        if (!telescope) {
            cout << "��'��� Telescope �� �������� �� �������� �������!\n";
            return;
        }

        cout << "\n\n\n\t==== Telescope Object State ====\n\n";
        cout << "class Telescope\n";
        cout << "{\n";
        cout << "private:\n";
        cout << "\tstring brand = \"" << telescope->GetBrand() << "\";\n";
        cout << "\tstring model = \"" << telescope->GetModel() << "\";\n";
        cout << "\tstring opticalDesign = \""
            << telescope->GetOpticalDesign() << "\";\n";
        cout << "\tstring aperture = \""
            << telescope->GetAperture() << "\";\n";
        cout << "\tstring focalLength = \""
            << telescope->GetFocalLength() << "\";\n";
        cout << "\tstring mountType = \""
            << telescope->GetMountType() << "\";\n";
        cout << "\tstring eyepiece = \""
            << telescope->GetEyepiece() << "\";\n";
        cout << "\tstring filter = \"" << telescope->GetFilter() << "\";\n";
        cout << "\tbool isAimed = "
            << (telescope->GetIsAimed() ? "true" : "false") << ";\n";
        cout << "\tbool isFocused = "
            << (telescope->GetIsFocused() ? "true" : "false") << ";\n";
        cout << "\tstring skyObject = \""
            << telescope->GetSkyObject() << "\";\n";
    }


    static void DisplayWaterBottleFields(const WaterBottle* waterbottle)
    {
        if (!waterbottle) {
            cout << "��'��� WaterBottle �� �������� �� �������� �������!\n";
            return;
        }

        cout << "\n\n\n\t==== WaterBottle Object State ====\n\n";
        cout << "class WaterBottle\n";
        cout << "{\n";
        cout << "private:\n";
        cout << "\tstring brand = \"" << waterbottle->GetBrand() << "\";\n";
        cout << "\tstring producer = \""
            << waterbottle->GetProducer() << "\";\n";
        cout << "\tfloat capacity = " << waterbottle->GetCapacity() << ";\n";
        cout << "\tfloat currentVolume = "
            << waterbottle->GetCurrentVolume() << ";\n";
        cout << "\tstring expirationDate = \""
            << waterbottle->GetExpirationDate() << "\";\n";
        cout << "\tstring mineralization = \""
            << waterbottle->GetMineralization() << "\";\n";
        cout << "\tstring material = \""
            << waterbottle->GetMaterial() << "\";\n";
        cout << "\tbool isExpired = "
            << (waterbottle->GetIsExpired() ? "true" : "false") << ";\n";
        cout << "\tbool isOpened = "
            << (waterbottle->GetIsOpened() ? "true" : "false") << ";\n";
        cout << "\tbool isBeingPoured = "
            << (waterbottle->GetIsBeingPoured() ? "true" : "false") << ";\n";
        cout << "\tbool isWiped = "
            << (waterbottle->GetIsWiped() ? "true" : "false") << ";\n";
    }
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ������������ ������������ �� ������������� ��� Telescope
    Telescope myTelescope;
    myTelescope.InputTelescopeData();
    myTelescope.PrintInfo("ϳ�������� ���������"); Sleep(20000);
    myTelescope.AimAtObject("̳����");
    myTelescope.PrintInfo("���������� � ���� ����"); Sleep(20000);
    myTelescope.FocusTelescope();
    myTelescope.PrintInfo("������������� � ����� ����������"); Sleep(20000);
    myTelescope.ChangeEyepiece("4 �� (175�), 1,25\"");
    myTelescope.SetFilter("̳������ ������");
    myTelescope.PrintInfo("������������ ���������"); Sleep(20000);
    myTelescope.FocusTelescope();
    myTelescope.PrintInfo("������������� � ������� ����������"); Sleep(30000);

    // ������������ ������� ��� Telescope
    Telescope newTelescope;
    try {
        newTelescope.SetBrand("Celestron");
        newTelescope.SetModel("AstroMaster 130");
        newTelescope.SetOpticalDesign("��������� �������");
        newTelescope.SetAperture("130 ��");
        newTelescope.SetFocalLength("750 ��");
        newTelescope.SetMountType("������������ � �������������");
        newTelescope.SetEyepiece("����������� ������ 10 ��");
        newTelescope.SetterFilter("�����-������");
        newTelescope.SetIsAimed();
        newTelescope.SetIsFocused();
        newTelescope.SetSkyObject("̳���� ��� �������, �������, ����� � "
            "�����");
        newTelescope.PrintInfo("����������� ��������");
        GetterShowCaseTask::DisplayTelescopeFields(&newTelescope);
        Sleep(15000);
        system("cls");

        newTelescope.SetIsAimed(false);
        newTelescope.SetIsFocused(false);
        newTelescope.SetFilter("��������");
        newTelescope.SetSkyObject("�����");
        newTelescope.FocusTelescope();
        newTelescope.PrintInfo("DANGER");
        GetterShowCaseTask::DisplayTelescopeFields(&newTelescope);
        Sleep(30000);
    }
    catch (const string& message) {
        cerr << "\n" << message << "\n";
    }

    // ������������ ������������ � ����������� ��� Telescope
    try {
        Telescope customTelescope("Celestron", "AstroMaster 130",
            "��������� �������", "130 ��", "750 ��",
            "������������ � �������������", "����������� ������ 10 ��",
            "�����-������", "̳���� ��� �������, �������, ����� � �����");
        customTelescope.PrintInfo("�������� �������� �� �������� �����������");
        GetterShowCaseTask::DisplayTelescopeFields(&customTelescope);
        Sleep(15000);
        system("cls");
    }
    catch (const string& message) {
        cerr << "\n" << message << "\n";
    }

    // ������������ ������������ ��������� ��� Telescope
    try {
        Telescope copiedTelescope(myTelescope);
        copiedTelescope.SetSkyObject("����");
        copiedTelescope.PrintInfo("���������� ��������");
        GetterShowCaseTask::DisplayTelescopeFields(&copiedTelescope);
        Sleep(15000);
        system("cls");
    }
    catch (const string& message) {
        cerr << "\n" << message << "\n";
    }


    // ������������ ������������ �� ������������� ��� WaterBottle
    WaterBottle oneBottle;
    oneBottle.InputBottleData();
    oneBottle.PrintInfo("����� ������"); Sleep(10000);
    oneBottle.CheckExpiration();
    oneBottle.PrintInfo("��������� ����"); Sleep(10000);
    oneBottle.WipeBottle();
    oneBottle.PrintInfo("����� �������� �� ����"); Sleep(10000);
    oneBottle.OpenBottle();
    oneBottle.PrintInfo("³�������� ������"); Sleep(10000);
    oneBottle.PourWater();
    oneBottle.PrintInfo("�������� 3 �"); Sleep(10000);
    oneBottle.CloseBottle();
    oneBottle.PrintInfo("��������� �������"); Sleep(10000);
    oneBottle.OpenBottle();
    oneBottle.PrintInfo("³�������� ������"); Sleep(10000);
    oneBottle.PourWater();
    oneBottle.PrintInfo("�������� 3 �"); Sleep(10000);
    oneBottle.CloseBottle();
    oneBottle.PrintInfo("��������� �������"); Sleep(10000);
    oneBottle.OpenBottle();
    oneBottle.PrintInfo("³�������� ������"); Sleep(10000);
    oneBottle.PourWater();
    oneBottle.PrintInfo("� ������ ��������"); Sleep(10000);
    oneBottle.CloseBottle();
    oneBottle.PrintInfo("��������� �������"); Sleep(30000);

    // ������������ ������� ��� WaterBottle
    WaterBottle anotherBottle;
    try {
        GetterShowCaseTask::DisplayWaterBottleFields(&anotherBottle);
        Sleep(15000);
        system("cls");

        anotherBottle.SetBrand("AquaLife");
        anotherBottle.SetProducer("������������� ����� ���������� ���");
        anotherBottle.SetCapacity(5.0f);
        anotherBottle.SetCurrentVolume(5.0f);
        anotherBottle.SetExpirationDate("05.06.26");
        anotherBottle.SetMineralization("300-500 ��/�");
        anotherBottle.SetMaterial("�������� �������");
        anotherBottle.SetIsExpired(false);
        anotherBottle.SetIsOpened(false);
        anotherBottle.SetIsBeingPoured(false);
        anotherBottle.SetIsWiped(false);
        anotherBottle.PrintInfo("�������� � ��������");
        GetterShowCaseTask::DisplayWaterBottleFields(&anotherBottle);
        Sleep(20000);
        system("cls");

        anotherBottle.CheckExpiration();
        anotherBottle.WipeBottle();
        anotherBottle.PrintInfo("�� ��� ��������� ����, ��������");
        GetterShowCaseTask::DisplayWaterBottleFields(&anotherBottle);
        Sleep(20000);
        system("cls");
    }
    catch (const string& message) {
        cerr << "\n" << message << "\n";
    }

    // ������������ ������������ � ����������� ��� WaterBottle
    try {
        WaterBottle customBottle("AquaLife",
            "������������� ����� ���������� ���", 5.0f, 5.0f,
            "05.06.26", "300-500 ��/�", "�������� �������");
        customBottle.PrintInfo("�������� ������ �� �������� �����������");
        GetterShowCaseTask::DisplayWaterBottleFields(&customBottle);
        Sleep(15000);
        system("cls");

        customBottle.CheckExpiration();
        customBottle.WipeBottle();
        customBottle.OpenBottle();
        customBottle.PourWater();
        customBottle.PrintInfo("�������� ���� � ������ ������");
        GetterShowCaseTask::DisplayWaterBottleFields(&customBottle);
        Sleep(15000);
        system("cls");
    }
    catch (const string& message) {
        cerr << "\n" << message << "\n";
    }

    // ������������ ������������ ��������� ��� WaterBottle
    try {
        WaterBottle copiedBottle(oneBottle);
        copiedBottle.SetBrand("ϳ��� ���� ������");
        copiedBottle.PrintInfo("���������� ������ � ������ �����");
        GetterShowCaseTask::DisplayWaterBottleFields(&copiedBottle);
        Sleep(15000);
        system("cls");
    }
    catch (const string& message) {
        cerr << "\n" << message << "\n";
    }

    return 0;
}