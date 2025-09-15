#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {

    // 1) Проверка IP
    cout << "1) Проверка IP" << endl;
    string ip;
    cout << "Введите строку (IP): ";
    getline(cin, ip);

    int dotCount=0;
    string tmpNum="";
    bool ok = true;
    for (int i=0;i<ip.size();i++){
        char c = ip[i];
        if (c=='.') {
            dotCount++;
            if (tmpNum=="" || stoi(tmpNum)<0 || stoi(tmpNum)>255) ok=false;
            tmpNum="";
        } else if (isdigit(c)) {
            tmpNum+=c;
        } else {
            ok=false;
        }
    }
    if (tmpNum!="" && (stoi(tmpNum)<0 || stoi(tmpNum)>255)) ok=false;
    if (dotCount!=3) ok=false;

    if (ok) cout << "Корректный IP" << endl;
    else cout << "Некорректный IP" << endl;


    // 2) Сортировка фамилий
    cout << "\n2) Сортировка фамилий" << endl;
    vector<string> surnames;
    string s;
    for (int i=0;i<5;i++){
        cout << "Фамилия " << i+1 << ": ";
        getline(cin, s);
        surnames.push_back(s);
    }
    sort(surnames.begin(), surnames.end(), greater<string>());
    cout << "Отсортированные фамилии (по убыванию):\n";
    for (auto x: surnames) cout << x << endl;


    // 3) Подсчёт символа
    cout << "\n3) Подсчёт символа" << endl;
    string line;
    cout << "Введите строку: ";
    getline(cin, line);
    char ch;
    cout << "Введите символ: ";
    cin >> ch; 
    cin.ignore();
    int cntt=0;
    for (int i=0;i<line.size();i++){
        if (line[i]==ch) cntt++;
    }
    cout << "Символ встречается " << cntt << " раз(а)" << endl;


    // 4) Самое длинное слово
    cout << "\n4) Самое длинное слово" << endl;
    string strline;
    cout << "Введите строку: ";
    getline(cin, strline);
    stringstream ss(strline);
    string word, longest="";
    while (ss >> word){
        if (word.size() > longest.size()) longest=word;
    }
    cout << "Самое длинное слово: " << longest << endl;


    // 5) Замена слова
    cout << "\n5) Замена слова" << endl;
    string text;
    cout << "Введите строку: ";
    getline(cin, text);
    string oldWord, newWord;
    cout << "Что ищем? ";
    cin >> oldWord;
    cout << "На что меняем? ";
    cin >> newWord;
    size_t pos=text.find(oldWord);
    while (pos!=string::npos){
        text.replace(pos, oldWord.size(), newWord);
        pos=text.find(oldWord, pos+newWord.size());
    }
    cout << "Результат: " << text << endl;
    cin.ignore();


    // 6) Палиндром?
    cout << "\n6) Палиндром?" << endl;
    string check;
    cout << "Введите строку: ";
    getline(cin, check);
    string rev=check;
    reverse(rev.begin(), rev.end());
    if (check==rev) cout << "Палиндром" << endl;
    else cout << "Не палиндром" << endl;


    // 7) Следующая буква укр. алфавита
    cout << "\n7) Следующая буква укр. алфавита" << endl;
    string alphabet="АБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ";
    char ukr;
    cout << "Введите букву: ";
    cin >> ukr;
    int posi=-1;
    for (int i=0;i<alphabet.size();i++){
        if (alphabet[i]==ukr) { posi=i; break; }
    }
    if (posi==-1) cout << "Такой буквы нет" << endl;
    else if (posi==alphabet.size()-1) cout << "Далі букв немає" << endl;
    else cout << "Следующая буква: " << alphabet[posi+1] << endl;

    return 0;
}
