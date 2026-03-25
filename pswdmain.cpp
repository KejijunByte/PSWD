#include "PSWD.h"
#include <iostream>

int main() {
    Password pwd;
    
    std::cout << "=== 跨平台密码输入测试 ===" << std::endl;
    pwd.input(); // 输入密码，显示星号，支持退格
    
    std::cout << "\n[隐藏模式] ";
    pwd.display(false); // 只显示星号
    
    std::cout << "[明文模式] ";
    pwd.display(true);  // 显示真实密码
    
    std::cout << "\n获取的密码字符串: " << pwd.getPassword() << std::endl;
    
    return 0;
}