#include <iostream>
#include <fstream>
#include <string>

int main() {
  // 파일 쓰기 준비
  std::ofstream out("test.txt");

  std::string s;
  if (out.is_open()) {
    out << "이걸 쓰자~~";
  }

  return 0;
}