//uva10222

//分析:

/*存在的問題
1、如果密文中包含 q、w、a、s、z、x 則無法解析, &
    & 因為該字元已經處於標準鍵盤鍵位的最左邊，無法向左移動2位進行解析
    { 例如 -> 根據 #25行 dic中的'q'通過 dic[pos - 2]解析後會得到'-',而非自身'q' }
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string dic = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

    int N;
    cin >> N;
    cin.ignore();
    while (N--) {
        string words;
        getline(cin, words); //Cpp func
        for (int i = 0; i < words.size(); ++i) {
            if ('A' <= words[i] && words[i] <= 'Z')
                words[i] += 32; // to lower case
            int pos = dic.find(words[i]);
            if (pos != -1)
                words[i] = dic[pos - 2];
        }
        cout << words << endl;
    }

    return 0;
}