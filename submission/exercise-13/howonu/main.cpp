#include <memory>
#include <iostream>
#include <utility>

// ī���� ���� ����
int default_constructor_count = 0;
int copy_constructor_count = 0;
int move_constructor_count = 0;
int copy_assignment_count = 0;
int move_assignment_count = 0;
int destructor_count = 0;

class MyApplication {
public:
    // �⺻ ������
    MyApplication() {
        ++default_constructor_count;
    }

    // ���� ������
    MyApplication(const MyApplication&) {
        ++copy_constructor_count;
    }

    // �̵� ������
    MyApplication(MyApplication&&) noexcept {
        ++move_constructor_count;
    }

    // ���� ���� ������
    MyApplication& operator=(const MyApplication&) {
        ++copy_assignment_count;
        return *this;
    }

    // �̵� ���� ������
    MyApplication& operator=(MyApplication&&) noexcept {
        ++move_assignment_count;
        return *this;
    }

    // �Ҹ���
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
    std::cout << "�⺻ ������ ȣ�� Ƚ��: " << default_constructor_count << '\n';
    std::cout << "���� ������ ȣ�� Ƚ��: " << copy_constructor_count << '\n';
    std::cout << "�̵� ������ ȣ�� Ƚ��: " << move_constructor_count << '\n';
    std::cout << "���� ���� ������ ȣ�� Ƚ��: " << copy_assignment_count << '\n';
    std::cout << "�̵� ���� ������ ȣ�� Ƚ��: " << move_assignment_count << '\n';
    std::cout << "�Ҹ��� ȣ�� Ƚ��: " << destructor_count << '\n';

    TestSharedPtr();
    std::cout << "�⺻ ������ ȣ�� Ƚ�� (TestSharedPtr ��): " << default_constructor_count << '\n';
    std::cout << "���� ������ ȣ�� Ƚ�� (TestSharedPtr ��): " << copy_constructor_count << '\n';
    std::cout << "�̵� ������ ȣ�� Ƚ�� (TestSharedPtr ��): " << move_constructor_count << '\n';
    std::cout << "���� ���� ������ ȣ�� Ƚ�� (TestSharedPtr ��): " << copy_assignment_count << '\n';
    std::cout << "�̵� ���� ������ ȣ�� Ƚ�� (TestSharedPtr ��): " << move_assignment_count << '\n';
    std::cout << "�Ҹ��� ȣ�� Ƚ�� (TestSharedPtr ��): " << destructor_count << '\n';

    return 0;
}
