// ====================== PSWD.h ======================
// 这是一个跨平台的密码输入类，支持 Windows 和 Linux 系统
// 输入时显示为星号，并支持退格删除功能
// ====================================================

#ifndef PSWD_H
#define PSWD_H

#include <string>

// ====================== 密码输入类 ======================
class Password {
private:
    // 存储密码字符串
    std::string pwd;

public:
    // 输入密码，支持退格删除，并显示为星号
    void input();
    // 显示密码，默认显示为星号
    void display(bool show = false);
    // 获取密码字符串
    std::string getPassword() const;
    // 清除密码
    void clear();
};
// =============================================================

#endif