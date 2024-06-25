#include<iostream>
#include<string>
#include<cmath>

void SwapByRef(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int& RefRetFuncOne(int& ref)
{
    ref++;
    return ref;
}

int RefRetFuncTwo(int& ref)
{
    ref++;
    return ref;
}

int Adder(const int& num1, const int& num2)
{
    return num1 + num2;
}

int main01()
{
    int val1 = 10;
    int val2 = 20;

    const int* ptr1 = &val1; // ptr1은 상수 정수를 가리키는 포인터

    printf("Before changing ptr1: *ptr1 = %d\n", *ptr1); // 출력: 10

    // *ptr1 = 15; // 오류: 상수 정수를 가리키기 때문에 값을 변경할 수 없음

    ptr1 = &val2; // 포인터는 다른 주소를 가리킬 수 있음
    printf("After changing ptr1: *ptr1 = %d\n", *ptr1); // 출력: 20
    printf("After changing val2: *val2 = %d\n", val1); 

    return 0;
}

int main02()
{
    int num1 = 10, num2 = 20;

    int* p1 = &num1;
    int* p2 = &num2;

    //SwapByRef(p1, p2);

    std::cout << *p1 << "   " << *p2 << std::endl;

    return 0;
}

int main03()
{
    int num1 = 1;
    int num2 = RefRetFuncOne(num1);

    std::cout << "num1: " << num2 << std::endl;

    return 0;
}

int main04()
{
    int a = 10;
    int b = 20;

    int c = Adder(10, 20);

    std::cout << c << std::endl;
    return 0;
}

struct Car
{
    char gameID[8];
    int fuelGage;

    void ShowCarState() {
        return;
    }
};

class SimpleClass
{
private:
    int m_num;
public:
    SimpleClass(int m)
    {
        m_num = m;
    }
    int total()
    {
        return m_num * m_num;
    }
};

//class Point
//{
//private:
//    int x;
//    int y;
//public:
//    Point(const int& xpos, const int& ypos) {
//
//    }
//    int GetX() const;
//    int GetY() const;
//    bool SetX() const;
//    bool SetY() const;
//};

//class Rectangle
//{
//private:
//    // 이것 까지 객체
//    Point upLeft;
//    Point lowRight;
//public:
//    Rectangle(const int& x1, const int& y1, const int& x2, const int& y2)
//        : upLeft(x1, y1), lowRight(x2, y2)
//    {
//        std::cout << "생성자 호출" << std::endl;
//    }
//};

class SoSimple
{
private:
    int num;
public:
    SoSimple(int n) : num(n)
    {}
    SoSimple(const SoSimple& copy) : num(copy.num)
    {
        std::cout << "Called SoSimple(const SoSimple& copy)" << std::endl;
    }

    SoSimple& AddNum(int n)
    {
        num += n;
        return *this;
    }

    void ShowData()
    {
        std::cout << "num: " << num << std::endl;
    }
    ~SoSimple()
    {
        std::cout << "소멸" << std::endl;
    }
};

SoSimple SimpleFuncObj(SoSimple ob)
{
    return ob;
}

class AAA
{
public:
    static int num1;
};

int main05()
{
   /* SoSimple obj(7);
    std::cout << "함수 호출 전" << std::endl;
    SimpleFuncObj(obj);
    std::cout << "함수 호출 후" << std::endl;
    return 0;*/
    SoSimple obj(7);
    SimpleFuncObj(obj).AddNum(30).ShowData();
    obj.ShowData();
    return 0;
}

class SoSimple1
{
private:
    int simObjCnt=0;
    static int num2;
public:
    SoSimple1()
    {
        simObjCnt++;
        std::cout << simObjCnt << "번째 SoSimple 객체" << std::endl;
    }
    void aaa()
    {
        std::cout << "aaa" << std::endl;
    }
    static void test() {
        std::cout << "test function" << std::endl;
        //aaa();
    }
};

//int SoSimple1::simObjCnt = 0;

//class PermanentWorker
//{
//private:
//    char name[100];
//    int salary;
//public:
//    PermanentWorker(char* name, int money) : salary(money)
//    {
//        strcpy(this->name, name);
//    }
//};


class Gun
{
private:
    int bullet;
public:
    Gun(int bnum) : bullet(bnum)
    {}
    void Shut()
    {
        if (bullet < 1) {
            std::cout << "bullet empty" << std::endl;
            return;
        }
        std::cout << "BBANG!" << std::endl;
        bullet--;
    }
};

class Police
{
private:
    int handcuffs;
    Gun* pistol;

public:
    Police(int bnum, int bcuff) : handcuffs(bcuff)
    {
        if (bnum > 0)
            pistol = new Gun(bnum);
        else
            pistol = NULL;
    }
    void PutHandcuff()
    {
        std::cout << "SNAP!" << std::endl;
    }
    void Shut()
    {
        if (pistol == NULL)
            std::cout << "Hut BBANG!" << std::endl;
        else
            pistol->Shut();
    }
    ~Police()
    {
        if (pistol != NULL)
            delete pistol;
    }
};

class A
{
public:
    void test1()
    {
        std::cout << "test1" << std::endl;
    }
    virtual void fct2() const = 0;
};

class B : public A
{
public:
    void test1()
    {
        std::cout << "test2" << std::endl;
    }
    virtual void fct2() const
    {
        std::cout << "fct2" << std::endl;
    }
};

class C : public B
{
public:
    void test3()
    {
        std::cout << "test3" << std::endl;
    }
    virtual void fct2() const
    {
        std::cout << "fct3" << std::endl;
    }
};

class First
{
public:
    void FirstFunc() { std::cout << "FirstFunc()" << std::endl; }
    virtual void SimpleFunc() { std::cout << "First's SimpleFunc()" << std::endl; }

};

class Second : public First
{
public:
    void SecondFunc() { std::cout << "SecondFunc()" << std::endl; }
    virtual void SimpleFunc() { std::cout << "Second's SimpleFunc()" << std::endl; }
};

class Thrid : public Second
{
public:
    void ThirdFunc() { std::cout << "ThirdFunc()" << std::endl; }
    virtual void SimpleFunc() { std::cout << "Thrid's SimpleFunc()" << std::endl; }
};


int main06()
{
    Thrid obj;
    obj.FirstFunc();
    obj.SecondFunc();
    obj.ThirdFunc();
    obj.SimpleFunc();

    Second& sref = obj;
    sref.FirstFunc();
    sref.SecondFunc();
    sref.SimpleFunc();

    First& fref = obj;
    fref.FirstFunc();
    fref.SimpleFunc();
    return 0;

}

//class Point
//{
//private:
//    int xpos, ypos;
//public:
//    Point(int x=0, int y=0): xpos(x),ypos(y)
//    {}
//    void ShowPosition() const
//    {
//        std::cout << '[' << xpos << ", " << ypos << ']' << std::endl;
//    }
//    Point& operator+(const Point& ref)
//    {
//        Point pos(xpos + ref.xpos, ypos + ref.ypos);
//        return pos;
//    }
//    Point operator++()
//    {
//        xpos += 1;
//        ypos += 1;
//        return *this;
//    }
//    friend Point& operator--(Point& ref);
//};
//
//Point& operator--(Point & ref)
//{
//    ref.xpos = 1;
//    ref.ypos = 1;
//    return ref;
//}

//class Point
//{
//private:
//    int xpos, ypos;
//public:
//    Point(int x=0, int y=0): xpos(x), ypos(y){}
//    void ShowPosition() const
//    {
//        std::cout << '[' << xpos << ", " << ypos << ']' << std::endl;
//    }
//    friend std::ostream& operator<<(std::ostream&, const Point&);
//};
//
//std::ostream& operator<<(std::ostream& os, const Point& pos)
//{
//    os << '[' << pos.xpos << ", " << pos.ypos << ']' << std::endl;
//    return os;
//}

class Person
{
private:
    char* name;
    int age;
public:

};

#include <iostream>
#include <cstdlib> // for exit()

class IntArray {
private:
    int* arr;
    int arrlen;
public:
    IntArray(int len) : arrlen(len) {
        arr = new int[arrlen];
        for (int i = 0; i < arrlen; ++i) {
            arr[i] = i; // 초기값 설정
        }
    }

    ~IntArray() {
        delete[] arr;
    }

    // Const version
    int operator[] (int idx) const {
        if (idx < 0 || idx >= arrlen) {
            std::cout << "Array index out of bound exception" << std::endl;
            exit(1);
        }
        return arr[idx];
    }

    // Non-const version
    int& operator[] (int idx) {
        if (idx < 0 || idx >= arrlen) {
            std::cout << "Array index out of bound exception" << std::endl;
            exit(1);
        }
        return arr[idx];
    }
};


int main07() {
    IntArray arr(10);

    // Non-const 객체에 대한 접근
    arr[0] = 50; // arr[2] 값 수정
    std::cout << "arr[2] (after modification): " << arr[2] << std::endl;

    // Const 객체에 대한 접근
    const IntArray constArr(10);
    std::cout << "constArr[2]: " << constArr[2] << std::endl; // 값 읽기 가능, 수정 불가

    return 0;
}

class SortRule
{
public:
    virtual bool operator()(int num1, int num2) const = 0;
};

class AscendingSort : public SortRule
{
public:
    bool operator()(int num1, int num2) const
    {
        if (num1 > num2)
            return true;
        else
            return false;
    }
};

class DescendingSort : public SortRule
{
public:
    bool operator()(int num1, int num2) const
    {
        if (num1 < num2)
            return true;
        else
            return false;
    }
};

class DataStotage 
{
private:
    int* m_arr;
    int m_capacity;
    int m_size;
public:
    DataStotage(int cap) : m_capacity(cap), m_size(0) {
        m_arr = new int[m_capacity];
    }
    ~DataStotage() 
    {
        delete[] m_arr;
    }
    void addnum(int arr) {
        m_arr[m_size] = arr;
        m_size++;
    }
    void ShowData()
    {
        for (int i = 0; i < m_size; i++)
        {
            std::cout << m_arr[i] << std::endl;
        }
    }
    void SortData(const SortRule& functor)
    {
        for (int i = 0; i < (m_size-1); i++)
        {
            for(int j = 0; j < (m_size-1); j++)
            {
                if (functor(m_arr[j], m_arr[j + 1]))
                {
                    int temp = m_arr[j];
                    m_arr[j] = m_arr[j + 1];
                    m_arr[j + 1] = temp;
                }
            }
        }
    }
};

int main08()
{
    DataStotage* str = new DataStotage(10);
    str->addnum(10);
    str->addnum(15);
    str->addnum(20);
    str->addnum(25);

    AscendingSort upsort;
    DescendingSort downsort;
    str->SortData(downsort);
    str->ShowData();
    return 0;
}

class String
{
private:
    char* str;
    std::size_t lenght;
public:
    String(){}
    ~String() {}
};

int main09()
{
    std::string str1 = "I like";
    std::string str2 = "string class";
    std::string str3 = str1 + str2;
    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;
    std::cout << str3 << std::endl;
    str1 += str2;
    if (str1 == str3) {
        std::cout << "동일 문자열!" << std::endl;
    }
    else {
        std::cout << "동일하지 않는 문자열" << std::endl;
    }
    std::string str4;
    std::cout << "문자열 입력: ";
    std::cin >> str4;
    std::cout << "입력한 문자열: " << str4 << std::endl;
    return 0;
}


template <typename T>
T Add(T num1, T num2)
{
    return num1 + num2;
}

int main10()
{
    std::cout << Add<int>(15, 20) << std::endl;
    std::cout << Add<double>(2.9, 3.7) << std::endl;
    std::cout << Add<int>(3.2, 3.2) << std::endl;
    std::cout << Add<int>(3.14, 2.75) << std::endl;
    return 0;
}

template <class T1, class T2>
void ShowData(double num)
{
    std::cout << (T1)num << ", " << (T2)num << std::endl;
}

int main11()
{
    ShowData<char, int>(65);
    ShowData<char, int>(67);
    return 0;
}

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0):xpos(x),ypos(y){}
    template<class T>
    void SwapData(T& data1, T& data2)
    {
        T temp;
        data1 = temp;
        data1 = data2;
        data2 = data1;
    }
    void SetpPos(int x, int y)
    {
        xpos = x;
        ypos = y;
    }
    void ShowPosition()const
    {
        std::cout << '[' << xpos << ", " << ypos << ']' << std::endl;
    }
};
template<typename T>
T SumArray(T arr[], int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
        sum += arr[i];
    return sum;
}


//int main12()
//{
//    Point pos1(3, 4);
//    Point pos2(10, 20);
//    //pos1.SwapData(pos1, pos2);
//    int arr[] = { 10,20,30 };
//    std::cout << SumArray(arr, 3) << std::endl;
//    pos1.ShowPosition();
//    return 0;
//}

template<typename T>
class SmartPtr
{
private:
    T* posptr;
public:
       SmartPtr(T * ptr): posptr(ptr){}
       T& operator*() const { return *posptr; }
       T* operator->() const { return posptr; }
       ~SmartPtr() { delete posptr; }
};

int main13()
{
    SmartPtr<Point> sptr1(new Point(1, 2));
    SmartPtr<Point> sptr2(new Point(3, 4));
    sptr1->ShowPosition();
    sptr2->ShowPosition();
    return 0;
}

template<typename T1, typename T2>
class MySimple 
{
public:
    void WhoAreYou()
    {
        std::cout << "size of T1: " << sizeof(T1) << std::endl;
        std::cout << "size of T2: " << sizeof(T2) << std::endl;
        std::cout << "<thpename T1, typename T2>" << std::endl;
    }
};

template <>
class MySimple<int, double>
{
public:
    void WhoAreYou()
    {
        std::cout << "size of int: " << sizeof(int) << std::endl;
        std::cout << "size of double" << sizeof(double) << std::endl;
        std::cout << "<int, double>" << std::endl;
    }
};

template<typename T1>
class MySimple <T1, double>
{
public:
    void WhoAreYou()
    {
        std::cout << "size of T1: " << sizeof(T1) << std::endl;
        std::cout << "size of double" << sizeof(double) << std::endl;
        std::cout << "<T1, double>" << std::endl;
    }
};

int main14()
{
    MySimple<char, double> obj1;
    obj1.WhoAreYou();
    MySimple<int, long> obj2;
    obj2.WhoAreYou();
    MySimple<int, double> obj3;
    obj3.WhoAreYou();
    MySimple<int, int> obj4;
    obj4.WhoAreYou();
    return 0;

}

int main15()
{
    int num1, num2;
    std::cout << "두 개의 숫자 입력: ";
    std::cin >> num1 >> num2;
    try
    {
        if (num2 == 0)
            throw num2;
        std::cout << "나눗셈의 몫: " << num1 / num2 << std::endl;
        std::cout << "나눗셈의 나머지: " << num1 % num2 << std::endl;
    }
    catch (int expn)
    {
        std::cout << "제수는 " << expn << "이 될 수 없습니다." << std::endl;
        std::cout << "프로그램을 다시 실행하세요." << std::endl;
    }
    std::cout << "end of main" << std::endl;
    return 0;
}

int StoI(char* str)
{
    int len = strlen(str);
    int num = 0;

    for (int i = 0; i < len; i++)
    {
        if (str[i] < '0' || str[i]>'9')
            throw str[i];
        num += (int)(pow((double)10, (len - 1) - i) * (str[i] + (7 - '7')));
    }
    return num;
}

int main16()
{
    char str1[100];
    char str2[200];

    while (1)
    {
        std::cout << "두 개의 숫자 입력: ";
        std::cin >> str1 >> str2;

        try
        {
            std::cout << str1 << " + " << str2 << " = " << StoI(str1) + StoI(str2) << std::endl;
            break;
        }
        catch (char ch)
        {
            std::cout << "문자 " << ch << "가 입력되었습니다." << std::endl;
            std::cout << "재입력 진행합니다." << std::endl;
        }
    }
    std::cout << "프로그램을 종료합니다." << std::endl;
    return 0;
}

void SimpleFuncOne(void);
void SimpleFuncTwo(void);
void SimpleFuncThree(void);

int main()
{
    try
    {
        SimpleFuncOne();
    }
    catch (int expn)
    {
        std::cout << "예외 코드: " << expn << std::endl;
    }
    return 0;
}

void SimpleFuncOne()
{
    std::cout << "SimpleFuncOne(void)" << std::endl;
    SimpleFuncTwo();
}

void SimpleFuncTwo()
{
    std::cout << "SimpleFuncTwo(void)" << std::endl;
    SimpleFuncThree();
}

void SimpleFuncThree()
{
    std::cout << "SimpleFuncThree(void)" << std::endl;
    throw - 1;
}