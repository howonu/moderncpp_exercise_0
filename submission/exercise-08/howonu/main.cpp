//#include <iostream>
//
////POD 클래스 MyApplication을 정의하고, 모든 특수 멤버 함수 호출 시에 현재 함수의 signature를 출력하도록 합니다. 
//
//class MyApplication {
//
//
////};
//
//int main() {
//	
//	//print : MyApplication::MyApplication()
//	MyApplication a;
//	//print : MyApplication::MyApplication(const MyApplication)
//	MyApplication b = a;
//
//	//print : MyApplication::~MyApplication() (b destroyed)
//	//print : MyApplication::~MyApplication() (a destroyed)
//	return 0;
//}

#include <iostream>

class MyApplication {
public:
    // 기본 생성자
    MyApplication() {
        std::cout << "MyApplication::MyApplication()" << std::endl;
    }

    // 복사 생성자
    MyApplication(const MyApplication&) {
        std::cout << "MyApplication::MyApplication(const MyApplication&)" << std::endl;
    }

    // 소멸자
    ~MyApplication() {
        std::cout << "MyApplication::~MyApplication()" << std::endl;
    }
};

int main() {
    // 기본 생성자 호출
    MyApplication a;
    // 복사 생성자 호출
    MyApplication b = a;

    // 소멸자 호출 (b, 그 다음 a 파괴)
    return 0;
}
