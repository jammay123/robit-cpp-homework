#include <iostream>
#include <string>

using namespace std;

// 기본 클래스 Animal
class Animal {
public:
    int age;
    string name;

    Animal() : age(0), name("") {}
    virtual ~Animal() {}

    virtual void makeSound() const = 0;
    virtual void showInfo() const {
        cout << "이름: " << name << ", 나이: " << age << endl;
    }
};

// Dog 클래스
class Dog : public Animal {
public:
    void makeSound() const { cout << "Bark! Bark! Bark!" << endl; }
};

// Cat 클래스
class Cat : public Animal {
public:
    void makeSound() const { cout << "Meow! Meow! Meow!" << endl; }
};

// Bird 클래스
class Bird : public Animal {
public:
    void makeSound() const { cout << "Chirp! Chirp! Chirp!" << endl; }
};

Animal* PlusDog = nullptr;
Animal* PlusCat = nullptr;
Animal* PlusBird = nullptr;

int main() {
    while (1) {
        int choice1;

        cout << "1. 동물 생성" << endl;
        cout << "2. 동물 검색" << endl;
        cout << "3. 종료" << endl;
        cout << "메뉴를 선택해주세요: ";
        cin >> choice1;
        cin.ignore();

        if (choice1 == 1) {
            int choice2;
            cout << "1. 개 생성" << endl;
            cout << "2. 고양이 생성" << endl;
            cout << "3. 새 생성" << endl;
            cout << "메뉴를 선택해주세요: ";
            cin >> choice2;
            cin.ignore();

            switch (choice2) {
            case 1:
                PlusDog = new Dog;
                cout << "개 나이 설정: ";
                cin >> PlusDog->age;
                cin.ignore();
                cout << "개 이름 설정: ";
                getline(cin, PlusDog->name);
                break;

            case 2:
                PlusCat = new Cat;
                cout << "고양이 나이 설정: ";
                cin >> PlusCat->age;
                cin.ignore();
                cout << "고양이 이름 설정: ";
                getline(cin, PlusCat->name);
                break;

            case 3:
                PlusBird = new Bird;
                cout << "새 나이 설정: ";
                cin >> PlusBird->age;
                cin.ignore();
                cout << "새 이름 설정: ";
                getline(cin, PlusBird->name);
                break;

            default:
                cout << "잘못된 선택입니다." << endl;
                break;
            }
        }
        else if (choice1 == 2) {
            string findName;
            cout << "이름으로 검색: ";
            getline(cin, findName);

            if (PlusDog && findName == PlusDog->name) {
                PlusDog->showInfo();
                PlusDog->makeSound();
            } else if (PlusCat && findName == PlusCat->name) {
                PlusCat->showInfo();
                PlusCat->makeSound();
            } else if (PlusBird && findName == PlusBird->name) {
                PlusBird->showInfo();
                PlusBird->makeSound();
            } else {
                cout << "동물을 찾을 수 없습니다." << endl;
            }
        }
        else if (choice1 == 3) {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        else {
            cout << "잘못된 선택입니다." << endl;
        }
    }

    delete PlusDog;
    delete PlusCat;
    delete PlusBird;

    return 0;
}
