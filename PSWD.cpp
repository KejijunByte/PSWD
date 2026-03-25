// ====================== PSWD.cpp ======================
// 这是 PSWD.h 中 Password 类的实现文件
// 实现了跨平台的密码输入功能，支持 Windows 和 Linux 系统
//Copyright (c) 2026 KARINSOFT , All Rights Reserved.
// ====================================================

#include <iostream>
#include "PSWD.h"

// ====================== 跨平台按键宏定义 ======================
// Windows 使用 conio.h 的 _getch()
#ifdef _WIN32
    #include <conio.h>
    #define ENTER_KEY '\r'       // Windows 回车 = \r
    #define BACKSPACE_KEY '\b'    // Windows 退格 = \b
#elif defined(__linux__)
    #include <termios.h>
    #include <unistd.h>
    #define ENTER_KEY '\n'       // Linux 回车 = \n
    #define BACKSPACE_KEY 127    // Linux 退格 = 127

    // Linux 实现 _getch
    char _getch(void) {
        struct termios oldattr, newattr;
        char ch;
        tcgetattr(STDIN_FILENO, &oldattr);
        newattr = oldattr;
        newattr.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
        return ch;
    }
#else
    #error "Unsupported platform"
#endif
// ==============================================================

// 输入密码，支持退格删除，并显示为星号
void Password::input() {
    pwd.clear();
    char ch;
    std::cout << "Enter password: ";

    while ((ch = _getch()) != ENTER_KEY) {
        if (ch == BACKSPACE_KEY) {
            if (!pwd.empty()) {
                pwd.pop_back();
                std::cout << "\b \b";
            }
        } else {
                pwd += ch;
                std::cout << '*';
        }
    }

        std::cout << std::endl;
}

// 显示密码，默认显示为星号
void Password::display(bool show) {
    if (show)
        std::cout << "Password: " << pwd << std::endl;
    else
        std::cout << "Password: " << std::string(pwd.size(), '*') << std::endl;
}

// 获取密码字符串
std::string Password::getPassword() const {
    return pwd;
}
// 清除密码
void Password::clear() {
    pwd.clear();
}