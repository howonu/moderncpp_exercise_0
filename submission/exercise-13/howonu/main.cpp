#include <memory>
#include <iostream>
#include <utility>

// 카운터 변수 선언
int default_constructor_count = 0;
int copy_constructor_count = 0;
int move_constructor_count = 0;
int copy_assignment_count = 0;
int move_assignment_count = 0;
int destructor_count = 0;

class MyApplication {
public:
    // 기본 생성자
    MyApplication() {
        ++default_constructor_count;
    }

    // 복사 생성자
    MyApplication(const MyApplication&) {
        ++copy_constructor_count;
    }

    // 이동 생성자
    MyApplication(MyApplication&&) noexcept {
        ++move_constructor_count;
    }

    // 복사 대입 연산자
    MyApplication& operator=(const MyApplication&) {
        ++copy_assignment_count;
        return *this;
    }

    // 이동 대입 연산자
    MyApplication& operator=(MyApplication&&) noexcept {
        ++move_assignment_count;
        return *this;
    }

    // 소멸자
    ~MyApplication() {
        ++destructor_count;
    }
};

void TestUniquePtr() {
    auto p = std::make_unique<MyApplication>();
    auto p2 = std::move(p);
}

void TestSharedPtr() {
    auto p = std::make_shared<MyApplication>();
    auto p2 = p;
    p2.reset();
    std::weak_ptr<MyApplication> weak_p = p;
    auto lock = weak_p.lock();
    if (lock) {
        std::cout << "Acquired ownership\n";
    }
}

int main() {
    TestUniquePtr();
    std::cout << "기본 생성자 호출 횟수: " << default_constructor_count << '\n';
    std::cout << "복사 생성자 호출 횟수: " << copy_constructor_count << '\n';
    std::cout << "이동 생성자 호출 횟수: " << move_constructor_count << '\n';
    std::cout << "복사 대입 연산자 호출 횟수: " << copy_assignment_count << '\n';
    std::cout << "이동 대입 연산자 호출 횟수: " << move_assignment_count << '\n';
    std::cout << "소멸자 호출 횟수: " << destructor_count << '\n';

    TestSharedPtr();
    std::cout << "기본 생성자 호출 횟수 (TestSharedPtr 후): " << default_constructor_count << '\n';
    std::cout << "복사 생성자 호출 횟수 (TestSharedPtr 후): " << copy_constructor_count << '\n';
    std::cout << "이동 생성자 호출 횟수 (TestSharedPtr 후): " << move_constructor_count << '\n';
    std::cout << "복사 대입 연산자 호출 횟수 (TestSharedPtr 후): " << copy_assignment_count << '\n';
    std::cout << "이동 대입 연산자 호출 횟수 (TestSharedPtr 후): " << move_assignment_count << '\n';
    std::cout << "소멸자 호출 횟수 (TestSharedPtr 후): " << destructor_count << '\n';

    return 0;
}
