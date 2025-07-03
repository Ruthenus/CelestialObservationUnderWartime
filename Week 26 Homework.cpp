#include <windows.h>
#include <iostream>
#include <string>   // getline()

using namespace std;


class Telescope
{
private:
    char* brand = nullptr;           // покажчик на бренд
    char* model = nullptr;           // покажчик на модель
    char* opticalDesign = nullptr;   // покажчик на оптичну конструкцію
    char* aperture = nullptr;        // покажчик на діаметр об'єктива
    char* focalLength = nullptr;     // покажчик на фокусну відстань
    char* mountType = nullptr;       // покажчик на тип монтування
    char* eyepiece = nullptr;        // покажчик на опис окуляра
    char* filter = nullptr;          // покажчик на світлофільтр
    char* skyObject = nullptr;       // покажчик на небесне тіло
    bool isAimed;    // чи наведено телескоп на об'єкт?
    bool isFocused;  // чи виконано фокусування?

    // Приватний метод ініціалізації для делегування
    void InitTelescope(const string& brand = "Celestron",
        const string& model = "PowerSeeker 70 AZ",
        const string& opticalDesign = "Рефрактор",
        const string& aperture = "70 мм",
        const string& focalLength = "70 см",
        const string& mountType = "Азимутальне",
        const string& eyepiece = "20 мм (35x), 1,25\"",
        const string& filter = "Відсутній",
        const string& skyObject = "Місяць")
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

    // Конструктор за замовчуванням
    Telescope()
    {
        InitTelescope();
    }


    // Конструктор із параметрами
    Telescope(const string& brand, const string& model,
        const string& opticalDesign, const string& aperture,
        const string& focalLength, const string& mountType,
        const string& eyepiece, const string& filter, const string& skyObject)
    {
        InitTelescope(brand, model, opticalDesign, aperture, focalLength,
            mountType, eyepiece, filter, skyObject);
    }


    // Конструктор копіювання
    Telescope(const Telescope& other)
    {
        InitTelescope(other.brand, other.model, other.opticalDesign,
            other.aperture, other.focalLength, other.mountType,
            other.eyepiece, other.filter, other.skyObject);
        this->isAimed = other.isAimed;
        this->isFocused = other.isFocused;
    }


    // Деструктор
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


    // Сеттери для покажчиків

    void SetBrand(const string& brand)
    {
        if (brand.empty()) throw string("Бажано зазначити бренд телескопа!");
        delete[] this->brand;
        this->brand = new char[brand.length() + 1];
        strcpy_s(this->brand, brand.length() + 1, brand.c_str());
    }

    void SetModel(const string& model)
    {
        if (model.empty()) throw string("Бажано зазначити модель телескопа!");
        delete[] this->model;
        this->model = new char[model.length() + 1];
        strcpy_s(this->model, model.length() + 1, model.c_str());
    }

    void SetOpticalDesign(const string& opticalDesign)
    {
        if (opticalDesign.empty()) throw string("Рефрактор чи рефлектор?..");
        delete[] this->opticalDesign;
        this->opticalDesign = new char[opticalDesign.length() + 1];
        strcpy_s(this->opticalDesign, opticalDesign.length() + 1,
            opticalDesign.c_str());
    }

    void SetAperture(const string& aperture)
    {
        if (aperture.empty())
            throw string("Будь ласка, вкажіть діаметр об'єктива в міліметрах");
        delete[] this->aperture;
        this->aperture = new char[aperture.length() + 1];
        strcpy_s(this->aperture, aperture.length() + 1, aperture.c_str());
    }

    void SetFocalLength(const string& focalLength)
    {
        if (focalLength.empty())
            throw string("Будь ласка, вкажіть фокусну відстань телескопа "
                "в міліметрах, сантиметрах, метрах!..");
        delete[] this->focalLength;
        this->focalLength = new char[focalLength.length() + 1];
        strcpy_s(this->focalLength, focalLength.length() + 1,
            focalLength.c_str());
    }

    void SetMountType(const string& mountType)
    {
        if (mountType.empty())
            throw string("Монтування азимутальне, екваторіальне, Добсона, "
                "виделкове, екваторіально-азимутальне?..");
        delete[] this->mountType;
        this->mountType = new char[mountType.length() + 1];
        strcpy_s(this->mountType, mountType.length() + 1, mountType.c_str());
    }

    void SetEyepiece(const string& eyepiece)
    {
        if (eyepiece.empty()) throw string("Спробуйте з комплектним окуляром");
        delete[] this->eyepiece;
        this->eyepiece = new char[eyepiece.length() + 1];
        strcpy_s(this->eyepiece, eyepiece.length() + 1, eyepiece.c_str());
        this->isFocused = false;
    }

    void SetterFilter(const string& filter)
    {
        if (filter.empty())
            throw string("Передивіться свій новий набір світлофільтрів.");
        delete[] this->filter;
        this->filter = new char[filter.length() + 1];
        strcpy_s(this->filter, filter.length() + 1, filter.c_str());
    }

    void SetSkyObject(const string& skyObject)
    {
        if ((skyObject == "Сонце" || skyObject == "The Sun" ||
            skyObject == "Sun") && strcmp(this->filter, "Сонячний") != 0)
            // https://en.cppreference.com/w/c/string/byte/strcmp.html
            throw string("Ніколи не дивіться на Сонце без спеціального "
                "сонячного світлофільтра — це дуже небезпечно!"
                " Найкраще — використовуйте метод проєкції на екран.");
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


    // Геттери для покажчиків

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


    // Метод для встановлення характеристик телескопа
    void InputTelescopeData()
    {
        system("cls");
        cout << "\tАБСТРАГУВАННЯ: ДАВНО НЕ СПОСТЕРІГАВ ЗОРЯНЕ НЕБО\n\n";

        string input;  // допоміжна змінна для збереження введеного тексту

        cout << "Маєте телескоп? Введіть бренд: ";
        getline(cin, input);
        if (!input.empty()) SetBrand(input);

        cout << "Введіть модель телескопа: ";
        getline(cin, input);
        if (!input.empty()) SetModel(input);

        cout << "Введіть різновид оптичної конструкції: ";
        getline(cin, input);
        if (!input.empty()) SetOpticalDesign(input);

        cout << "Введіть діаметр об'єктива (зазначте одиницю): ";
        getline(cin, input);
        if (!input.empty()) SetAperture(input);

        cout << "Введіть фокусну відстань (зазначте одиницю): ";
        getline(cin, input);
        if (!input.empty()) SetFocalLength(input);

        cout << "Введіть тип монтування: ";
        getline(cin, input);
        if (!input.empty()) SetMountType(input);
    }


    // Метод для наведення на астрономічний об'єкт
    void AimAtObject(const string& skyObject)
    {
        SetSkyObject(skyObject);
        this->isAimed = true;
    }


    // Метод для фокусування
    void FocusTelescope()
    {
        if (this->isAimed) this->isFocused = true;
    }


    // Метод для заміни окуляра
    void ChangeEyepiece(const string& otherEyepiece)
    {
        delete[] this->eyepiece;
        this->eyepiece = new char[otherEyepiece.length() + 1];
        strcpy_s(this->eyepiece, otherEyepiece.length() + 1,
            otherEyepiece.c_str());
        isFocused = false;
    }


    // Метод для встановлення світлофільтра
    void SetFilter(const string& newFilter)
    {
        delete[] this->filter;
        this->filter = new char[newFilter.length() + 1];
        strcpy_s(this->filter, newFilter.length() + 1, newFilter.c_str());
    }


    // Метод для виведення всієї інформації та стану дій
    void PrintInfo(const string& comment) const
    {
        system("cls");
        cout << "\tПрограма - журнал спостережень зоряного неба\n\n";
        cout << "Телескоп: " << GetBrand() << " " << GetModel() << "\n";
        cout << "Оптична конструкція: " << GetOpticalDesign() << "\n";
        cout << "Діаметр об'єктива: " << GetAperture() << "\n";
        cout << "Фокусна відстань: " << GetFocalLength() << "\n";
        cout << "Тип монтування: " << GetMountType() << "\n";
        cout << "\nОкуляр: " << GetEyepiece() << "\n";
        cout << "Світлофільтр: " << GetFilter() << "\n";
        cout << "\nТелескоп " << (GetIsAimed() ? "наведено на " +
            GetSkyObject() + "." :
            "ще не наведено, скористайтесь шукачем!") << "\n";
        cout << "Фокусування " << (GetIsFocused() ? "виконано!" :
            "ще не виконано!") << "\n";
        cout << "\n\nКОМЕНТАР: " << comment << "\n";
    }
};


class WaterBottle
{
private:

    string* brand;               // покажчик на бренд
    string* producer;            // покажчик на завод-виробник
    float* capacity;             // покажчик на об'єм бутеля
    float* currentVolume;        // покажчик на поточний рівень води
    string* expirationDate;      // покажчик на кінцеву дату споживання
    string* mineralization;      // покажчик на мінералізацію води
    string* material;            // покажчик на матеріал бутеля
    bool isExpired = false;      // чи термін споживання закінчився?
    bool isOpened = false;       // чи відкритий бутель?
    bool isBeingPoured = false;  // чи наливається вода?
    bool isWiped = false;        // чи бутель був протертий серветкою?

    // Приватний метод ініціалізації для делегування
    void InitWaterBottle(const string& brand = "Моршинська",
        const string& producer = "Моршинський завод мінеральних вод \"Оскар\"",
        const float& capacity = 6.0f,
        const float& currentVolume = 6.0f,
        const string& expirationDate = "02.11.25",
        const string& mineralization = "0,1-0,4 г/л",
        const string& material = "Пластик")
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

    // Конструктор за замовчуванням
    WaterBottle()
    {
        InitWaterBottle();
    }


    // Конструктор із параметрами
    WaterBottle(const string& brand, const string& producer,
        const float& capacity, const float& currentVolume,
        const string& expirationDate, const string& mineralization,
        const string& material)
    {
        InitWaterBottle(brand, producer, capacity, currentVolume,
            expirationDate, mineralization, material);
    }


    // Конструктор копіювання
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


    // Деструктор
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


    // Сеттери для покажчиків

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
            throw string("Об'єм бутеля має бути в межах 1 - 25 літрів!");
        *this->capacity = capacity;
        if (*this->currentVolume > *this->capacity)
            *this->currentVolume = *this->capacity;
    }

    void SetCurrentVolume(float currentVolume)
    {
        if (currentVolume < 0 || currentVolume > *this->capacity)
            throw string("Поточний об'єм води в літрах має бути в межах "
                "від 0 до максимальної ємності бутеля!");
        *this->currentVolume = currentVolume;
    }

    void SetExpirationDate(const string& expirationDate)
    {
        if (expirationDate.length() != 8 || expirationDate[2] != '.' ||
            expirationDate[5] != '.')
            throw string("Дата має бути вказана щонайменше у форматі"
                " ДД.ММ.РР та проходити повну валідацію!");
        *this->expirationDate = expirationDate;
    }

    void SetMineralization(const string& mineralization)
    {
        if (!mineralization.empty()) *this->mineralization = mineralization;
    }

    void SetMaterial(const string& material)
    {
        if (material != "Пластик" && material != "пластик" &&
            material != "Скло" && material != "скло" &&
            material != "Нержавіюча сталь" && material != "нержавіюча сталь" &&
            material != "Харчовий пластик" && material != "харчовий пластик")
            throw string("Виберіть придатний матеріал для зберігання води!");
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


    // Геттери для покажчиків

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


    // Метод для введення характеристик бутеля
    void InputBottleData()
    {
        system("cls");
        cout << "\tАБСТРАГУВАННЯ: НЕМАЄ ВОДИ\n\n";

        string input;

        cout << "Введіть відомий бренд: ";
        getline(cin, input);
        if (!input.empty()) SetBrand(input);

        cout << "Введіть завод-виробник: ";
        getline(cin, input);
        if (!input.empty()) SetProducer(input);

        cout << "Введіть об'єм бутеля: ";
        cin >> *this->capacity;
        cin.ignore();

        cout << "Введіть кінцеву дату споживання у форматі ЧЧ.ММ.РР: ";
        getline(cin, input);
        if (!input.empty()) SetExpirationDate(input);

        cout << "Визначте рівень мінералізації води: ";
        getline(cin, input);
        if (!input.empty()) SetMineralization(input);

        cout << "Зазначте матеріал бутеля: ";
        getline(cin, input);
        if (!input.empty()) SetMaterial(input);
    }


    // Метод для перевірки терміну придатності
    void CheckExpiration()
    {
        // Отримуємо поточний час у секундах з 1970-01-01 (epoch time)
        time_t now = time(nullptr);
        // https://learn.microsoft.com/ru-ru/cpp/c-runtime-library/reference/time-time32-time64?view=msvc-170
        // Перетворюємо часовий штамп у локальний час
        struct tm localTime;
        localtime_s(&localTime, &now);
        // https://learn.microsoft.com/ru-ru/cpp/c-runtime-library/reference/localtime-s-localtime32-s-localtime64-s?view=msvc-170

        // Доступ до компонентів дати - поточні день, місяць, рік:
        int todayDay = localTime.tm_mday;
        int todayMonth = localTime.tm_mon + 1; // tm_mon починається з 0
        int todayYear = localTime.tm_year + 1900; // відлік з 1900

        // Перетворюємо кінцеву дату споживання, використовуючи метод для
        // отримання підрядка та функцію для перетворення рядка на число
        int day = stoi(expirationDate->substr(0, 2));
        int month = stoi(expirationDate->substr(3, 2));
        int year = stoi(expirationDate->substr(6, 2)) + 2000;

        // Оновлюємо булеву змінну "прострочено"
        this->isExpired = year < todayYear ||
            (year == todayYear && month < todayMonth) ||
            (year == todayYear && month == todayMonth && day < todayDay + 2);
    }


    // Метод для відкривання бутеля
    void OpenBottle()
    {
        if (!this->isExpired) this->isOpened = true;
    }


    // Метод для закриття бутеля
    void CloseBottle()
    {
        this->isBeingPoured = false;
        this->isOpened = false;
    }


    // Метод для наливання води (по 3 л за раз)
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
            cout << "Води більше немає!" << "\n";
        }
    }


    // Метод для протирання бутеля серветкою
    void WipeBottle()
    {
        this->isWiped = true;
    }


    // Метод для виведення інформації про бутель
    void PrintInfo(const string& comment) const
    {
        system("cls");
        cout << "\tСТАН БУТЕЛЯ ВОДИ\n\n";
        cout << "Бренд води для щоденного вживання: " << *this->brand << "\n";
        cout << "Виробник: " << *this->producer << "\n";
        cout << "Об'єм: " << *this->capacity << "\n";
        cout << "Вжити до: " << *this->expirationDate << "\n";
        cout << "Мінералізація води: " << *this->mineralization << "\n";
        cout << "Матеріал бутеля: " << *this->material << "\n";
        cout << "\nБутель " << (this->isWiped ?
            "протертий вологою серветкою!" : "ще не протертий") << "\n";
        cout << (this->isExpired ? "Термін споживання закінчився!" :
            "Термін споживання ще не закінчився") << "\n";
        cout << "Бутель " << (this->isOpened ? "відкритий!" :
            "закритий") << "\n";
        cout << "Поточний рівень води: " << *this->currentVolume << " л\n";
        cout << (this->isBeingPoured ? "Наливаємо воду!" : "") << "\n";
        cout << "\nКОМЕНТАР: " << comment << "\n";
    }
};


class GetterShowCaseTask
{
public:

    static void DisplayTelescopeFields(const Telescope* telescope)
    {
        if (!telescope) {
            cout << "Об'єкт Telescope не знайдено за вказаною адресою!\n";
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
            cout << "Об'єкт WaterBottle не знайдено за вказаною адресою!\n";
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

    // Використання конструктора за замовчуванням для Telescope
    Telescope myTelescope;
    myTelescope.InputTelescopeData();
    myTelescope.PrintInfo("Підготовка телескопа"); Sleep(20000);
    myTelescope.AimAtObject("Місяць");
    myTelescope.PrintInfo("Захоплення в поле зору"); Sleep(20000);
    myTelescope.FocusTelescope();
    myTelescope.PrintInfo("Спостереження з малим збільшенням"); Sleep(20000);
    myTelescope.ChangeEyepiece("4 мм (175х), 1,25\"");
    myTelescope.SetFilter("Місячний фільтр");
    myTelescope.PrintInfo("Установлення аксесуарів"); Sleep(20000);
    myTelescope.FocusTelescope();
    myTelescope.PrintInfo("Спостереження з великим збільшенням"); Sleep(30000);

    // Використання сеттерів для Telescope
    Telescope newTelescope;
    try {
        newTelescope.SetBrand("Celestron");
        newTelescope.SetModel("AstroMaster 130");
        newTelescope.SetOpticalDesign("Рефлектор Ньютона");
        newTelescope.SetAperture("130 мм");
        newTelescope.SetFocalLength("750 мм");
        newTelescope.SetMountType("Екваторіальне з автостеженням");
        newTelescope.SetEyepiece("Стандартний окуляр 10 мм");
        newTelescope.SetterFilter("Світло-жовтий");
        newTelescope.SetIsAimed();
        newTelescope.SetIsFocused();
        newTelescope.SetSkyObject("Місяць біля Сатурна, Нептуна, Урана і "
            "Плеяд");
        newTelescope.PrintInfo("Встановлено телескоп");
        GetterShowCaseTask::DisplayTelescopeFields(&newTelescope);
        Sleep(15000);
        system("cls");

        newTelescope.SetIsAimed(false);
        newTelescope.SetIsFocused(false);
        newTelescope.SetFilter("Сонячний");
        newTelescope.SetSkyObject("Сонце");
        newTelescope.FocusTelescope();
        newTelescope.PrintInfo("DANGER");
        GetterShowCaseTask::DisplayTelescopeFields(&newTelescope);
        Sleep(30000);
    }
    catch (const string& message) {
        cerr << "\n" << message << "\n";
    }

    // Використання конструктора з параметрами для Telescope
    try {
        Telescope customTelescope("Celestron", "AstroMaster 130",
            "Рефлектор Ньютона", "130 мм", "750 мм",
            "Екваторіальне з автостеженням", "Стандартний окуляр 10 мм",
            "Світло-жовтий", "Місяць біля Сатурна, Нептуна, Урана і Плеяд");
        customTelescope.PrintInfo("Створено телескоп із заданими параметрами");
        GetterShowCaseTask::DisplayTelescopeFields(&customTelescope);
        Sleep(15000);
        system("cls");
    }
    catch (const string& message) {
        cerr << "\n" << message << "\n";
    }

    // Використання конструктора копіювання для Telescope
    try {
        Telescope copiedTelescope(myTelescope);
        copiedTelescope.SetSkyObject("Марс");
        copiedTelescope.PrintInfo("Скопійовано телескоп");
        GetterShowCaseTask::DisplayTelescopeFields(&copiedTelescope);
        Sleep(15000);
        system("cls");
    }
    catch (const string& message) {
        cerr << "\n" << message << "\n";
    }


    // Використання конструктора за замовчуванням для WaterBottle
    WaterBottle oneBottle;
    oneBottle.InputBottleData();
    oneBottle.PrintInfo("Стоїть бутель"); Sleep(10000);
    oneBottle.CheckExpiration();
    oneBottle.PrintInfo("Перевіримо дату"); Sleep(10000);
    oneBottle.WipeBottle();
    oneBottle.PrintInfo("Треба протерти від пилу"); Sleep(10000);
    oneBottle.OpenBottle();
    oneBottle.PrintInfo("Відкриваємо бутель"); Sleep(10000);
    oneBottle.PourWater();
    oneBottle.PrintInfo("Наливаємо 3 л"); Sleep(10000);
    oneBottle.CloseBottle();
    oneBottle.PrintInfo("Закриваємо кришкою"); Sleep(10000);
    oneBottle.OpenBottle();
    oneBottle.PrintInfo("Відкриваємо бутель"); Sleep(10000);
    oneBottle.PourWater();
    oneBottle.PrintInfo("Наливаємо 3 л"); Sleep(10000);
    oneBottle.CloseBottle();
    oneBottle.PrintInfo("Закриваємо кришкою"); Sleep(10000);
    oneBottle.OpenBottle();
    oneBottle.PrintInfo("Відкриваємо бутель"); Sleep(10000);
    oneBottle.PourWater();
    oneBottle.PrintInfo("А бутель спорожнів"); Sleep(10000);
    oneBottle.CloseBottle();
    oneBottle.PrintInfo("Закриваємо кришкою"); Sleep(30000);

    // Використання сеттерів для WaterBottle
    WaterBottle anotherBottle;
    try {
        GetterShowCaseTask::DisplayWaterBottleFields(&anotherBottle);
        Sleep(15000);
        system("cls");

        anotherBottle.SetBrand("AquaLife");
        anotherBottle.SetProducer("Миргородський завод мінеральних вод");
        anotherBottle.SetCapacity(5.0f);
        anotherBottle.SetCurrentVolume(5.0f);
        anotherBottle.SetExpirationDate("05.06.26");
        anotherBottle.SetMineralization("300-500 мг/л");
        anotherBottle.SetMaterial("Харчовий пластик");
        anotherBottle.SetIsExpired(false);
        anotherBottle.SetIsOpened(false);
        anotherBottle.SetIsBeingPoured(false);
        anotherBottle.SetIsWiped(false);
        anotherBottle.PrintInfo("Принесли з магазину");
        GetterShowCaseTask::DisplayWaterBottleFields(&anotherBottle);
        Sleep(20000);
        system("cls");

        anotherBottle.CheckExpiration();
        anotherBottle.WipeBottle();
        anotherBottle.PrintInfo("Ще раз перевірили дату, протремо");
        GetterShowCaseTask::DisplayWaterBottleFields(&anotherBottle);
        Sleep(20000);
        system("cls");
    }
    catch (const string& message) {
        cerr << "\n" << message << "\n";
    }

    // Використання конструктора з параметрами для WaterBottle
    try {
        WaterBottle customBottle("AquaLife",
            "Миргородський завод мінеральних вод", 5.0f, 5.0f,
            "05.06.26", "300-500 мг/л", "Харчовий пластик");
        customBottle.PrintInfo("Створено бутель із заданими параметрами");
        GetterShowCaseTask::DisplayWaterBottleFields(&customBottle);
        Sleep(15000);
        system("cls");

        customBottle.CheckExpiration();
        customBottle.WipeBottle();
        customBottle.OpenBottle();
        customBottle.PourWater();
        customBottle.PrintInfo("Наливаємо воду з нового бутеля");
        GetterShowCaseTask::DisplayWaterBottleFields(&customBottle);
        Sleep(15000);
        system("cls");
    }
    catch (const string& message) {
        cerr << "\n" << message << "\n";
    }

    // Використання конструктора копіювання для WaterBottle
    try {
        WaterBottle copiedBottle(oneBottle);
        copiedBottle.SetBrand("Пізно пити Боржомі");
        copiedBottle.PrintInfo("Скопійовано бутель і змінено бренд");
        GetterShowCaseTask::DisplayWaterBottleFields(&copiedBottle);
        Sleep(15000);
        system("cls");
    }
    catch (const string& message) {
        cerr << "\n" << message << "\n";
    }

    return 0;
}