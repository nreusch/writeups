#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Printer
{
    public:
    void print(string x)
    {
       cout << x << endl;
    }
};

class Encryptor
{
    private:
    unsigned char amount = 0;

    public:
    unsigned char add(char x) {
        unsigned char ret = x + this->amount;
        this->amount = ret;
        return ret;
    }

    unsigned char sub(char x) {
        unsigned char ret = x - this->amount;
        this->amount = ret;
        return ret;
    }

    unsigned char xorr(char x) {
        unsigned char ret = x ^ this->amount;
        this->amount = ret;
        return ret;
    }
};

int main()
{
    Printer p;
    Encryptor e;

    unsigned char input [43];
    unsigned char hash[16];
    vector<int> ops{
        42, 90, 36, 36, 61, 84, 76, 13, 49, 82, 22, 16, 31, 85, 36, 27, 24, 3, 88, 89, 74, 24, 17, 42, 76, 62, 82, 79, 78, 25, 92, 54, 62, 65, 34, 37, 32, 92, 94, 18, 31, 91
    };


    p.print("Please enter the flag:");
    scanf("%42s", input);

    /*
    printf("Input:\n");
    for (int i = 0; i < 42; i++) {
        printf("%02x", input[i]);
    }
    printf("\n");
    */

    for (int i = 0; i < 42; i++) {
        if (ops[i] % 3 == 0)
        {
            input[i] = e.add(input[i]);
        }
        else if (ops[i] % 3 == 1)
        {
            input[i] = e.sub(input[i]);
        }
        else if (ops[i] % 3 == 2)
        {
            input[i] = e.xorr(input[i]);
        }
    }
    
    /*
    printf("Encrypted:\n");
    for (int i = 0; i < 42; i++) {
        printf("%02x", input[i]);
    }
    printf("\n");
    */

    unsigned char goal[] = {
        0x44,0x88,0xcb,0x46,0x31,0x99,0xe0,0x7f,0xe5,0x4b,0x14,0x65,0xcb,0xaa,0x09,0x71,0xa5,0x1b,0x18,0x47,0x33,0x63,0x3c,0xa9,0x8a,0xf9,0x7a,0xe5,0x5a,0x16,0x49,0xb6,0xcf,0x90,0xd3,0x8c,0xef,0xdf,0x85,0xea,0x55,0x28
    };

    /*
    for (int j = 0; j < 16; j++) {
        printf("%02x", goal[j]);
    }
    printf("\n");
    */

    bool win = true;
    for (int j = 0; j < 42; j++) {
        if(input[j] != goal[j])
        {
            win = false;
        }
    }


    if (win)
    {
        p.print("You win!");
    }
    else
    {
        p.print("You lose :(");
    }
}



