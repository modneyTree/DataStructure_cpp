#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 1. char → int
    char ch1 = '7';
    int num1 = ch1 - '0';
    cout << "char '7' → int: " << num1 << "\n"; // 7

    // 2. int → char
    int num2 = 5;
    char ch2 = num2 + '0';
    cout << "int 5 → char: " << ch2 << "\n"; // '5'

    // 3. string → int
    string s1 = "123";
    int num3 = stoi(s1);
    cout << "string \"123\" → int: " << num3 << "\n"; // 123

    // 4. int → string
    int num4 = 42;
    string s2 = to_string(num4);
    cout << "int 42 → string: " << s2 << "\n"; // "42"

    // 5. string → double
    string s3 = "3.14";
    double d1 = stod(s3);
    cout << "string \"3.14\" → double: " << d1 << "\n"; // 3.14

    // 6. double → int (절삭)
    double d2 = 9.81;
    int num5 = static_cast<int>(d2);
    cout << "double 9.81 → int (절삭): " << num5 << "\n"; // 9

    // 7. char → 아스키 코드값
    char ch3 = 'A';
    int ascii1 = ch3;
    cout << "char 'A' → 아스키값: " << ascii1 << "\n"; // 65

    // 8. 아스키 코드값 → char
    int ascii2 = 66;
    char ch4 = static_cast<char>(ascii2);
    cout << "아스키값 66 → char: " << ch4 << "\n"; // 'B'

    return 0;
}
