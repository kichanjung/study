#include <iostream>

class String {
private:
    char* str;
    size_t length;

public:
    // 기본 생성자
    String() : str(nullptr), length(0) {}

    // 문자열을 받아들이는 생성자
    String(const char* s) {
        length = std::strlen(s);
        str = new char[length + 1];
        std::strcpy(str, s);
    }

    // 복사 생성자
    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        std::strcpy(str, other.str);
    }

    // 대입 연산자 오버로딩
    String& operator=(const String& other) {
        if (this == &other) {
            return *this;
        }
        delete[] str;
        length = other.length;
        str = new char[length + 1];
        std::strcpy(str, other.str);
        return *this;
    }

    // 소멸자
    ~String() {
        delete[] str;
    }

    // 문자열 연결 연산자 오버로딩
    String operator+(const String& other) const {
        char* newStr = new char[length + other.length + 1];
        std::strcpy(newStr, str);
        std::strcat(newStr, other.str);
        String newString(newStr);
        delete[] newStr;
        return newString;
    }

    // 문자열 연결 및 대입 연산자 오버로딩
    String& operator+=(const String& other) {
        char* newStr = new char[length + other.length + 1];
        std::strcpy(newStr, str);
        std::strcat(newStr, other.str);
        delete[] str;
        str = newStr;
        length += other.length;
        return *this;
    }

    // 문자열 비교 연산자 오버로딩
    bool operator==(const String& other) const {
        return std::strcmp(str, other.str) == 0;
    }

    // 출력 연산자 오버로딩
    friend std::ostream& operator<<(std::ostream& os, const String& s) {
        os << s.str;
        return os;
    }

    // 입력 연산자 오버로딩
    friend std::istream& operator>>(std::istream& is, String& s) {
        char buffer[1000];
        is >> buffer;
        s.length = std::strlen(buffer);
        delete[] s.str;
        s.str = new char[s.length + 1];
        std::strcpy(s.str, buffer);
        return is;
    }
};

int main() {
    String str1 = "I like";
    String str2 = "string class";
    String str3 = str1 + str2;
    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;
    std::cout << str3 << std::endl;
    str1 += str2;
    if (str1 == str3) {
        std::cout << "동일 문자열!" << std::endl;
    } else {
        std::cout << "동일하지 않는 문자열" << std::endl;
    }
    String str4;
    std::cout << "문자열 입력: ";
    std::cin >> str4;
    std::cout << "입력한 문자열: " << str4 << std::endl;
    return 0;
}