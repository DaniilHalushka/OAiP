#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i, pos, size, max, ind, num;
    size = max = pos = ind = 0;
    string stroka;
    getline(cin, stroka);
    stroka[stroka.size() - 1] = ' ';
    for (i = 0; i < stroka.size(); i++) {
        if (stroka[i] != ' ') size++;
        else  if (size > 0) {
            ind++;
            if (size > max) {
                max = size;
                pos = i - max + 1;
                num = ind;
            }
            size = 0;
        }
    }
    cout << "Number of word with max length = " << num << endl;
    cout << "Start position of this word is = " << pos;
}