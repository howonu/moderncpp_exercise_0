//#include <iostream>
//
////POD Ŭ���� MyApplication�� �����ϰ�, ��� Ư�� ��� �Լ� ȣ�� �ÿ� ���� �Լ��� signature�� ����ϵ��� �մϴ�. 
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
    // �⺻ ������
    MyApplication() {
        std::cout << "MyApplication::MyApplication()" << std::endl;
    }

    // ���� ������
    MyApplication(const MyApplication&) {
        std::cout << "MyApplication::MyApplication(const MyApplication&)" << std::endl;
    }

    // �Ҹ���
    ~MyApplication() {
        std::cout << "MyApplication::~MyApplication()" << std::endl;
    }
};

int main() {
    // �⺻ ������ ȣ��
    MyApplication a;
    // ���� ������ ȣ��
    MyApplication b = a;

    // �Ҹ��� ȣ�� (b, �� ���� a �ı�)
    return 0;
}
