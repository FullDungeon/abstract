/*
* ------------ STD::STRINGSTREAM ------------
? строковый поток, связывает поток ввода-вывода со строкой в памяти. Всё, что выводится в такой поток, добавляется в конец строки; всё, что считыватся из потока — извлекается из начала строки.
*/

#include <sstream>

using namespace std;

//& перевод string в int
int strToInt(string p) {
    stringstream os;
    os << p;

    int v;
    os >> v;

    return v;
}

// todo: попробовтаь перевести double в string