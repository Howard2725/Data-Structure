#include <iostream>  

#define M 256  

int ELFhash(const char* key) {
    unsigned long h = 0;
    while (*key) {
        h = (h << 4) + *key++; // 将h左移4位（乘以16），并加上当前字符的ASCII值  
        unsigned long g = h & 0xF0000000L; // 提取h的最高8位（即第24位到第31位）  
        if (g) h ^= g >> 24; // 如果g不为0，则将h的最低8位与g的最高8位（右移24位后）进行异或操作  
        h &= ~g; // 清除h的最高8位
    }
    return h % M;
}

int main() {
    const char* testKey = "hello";
    int hashValue = ELFhash(testKey);
    printf("Hash value of '%s' is %d\n", testKey, hashValue);
    return 0;
}