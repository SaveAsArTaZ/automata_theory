#include <bits/stdc++.h>
using namespace std;

void showMenu();
int menu(string &, float &, int, int, bool);
bool accept(string);
void ReciveProduct();

map<int, int> items;
vector<pair<string, pair<int, float>>> item = {
    {"Cake", {20, 2.5}},
    {"Peach juice", {30, 2.345}},
    {"chips", {10, 2.345}},
    {"Chocolate cake", {5, 2.65}},
    {"Banana juice", {30, 3.5}},
    {"Orange juice", {30, 5}},
    {"Fruit juice", {30, 4.3}},
    {"T. Tab", {30, 4.7}}
};

int main()
{
    string sentence = "";
    float cost = 0;
    int tmp = 2;
    char c;
    while (1)
    {
        if(tmp == 2 || tmp == 1)
        {
            showMenu();
            sentence += 'a';
            cout << "\ncheck string (y : yes n : no) : ";
            cin >> c;
            if(c == 'y')
                cout << (accept(sentence) ? "Accept\n" : "Reject\n") << endl;
        }
        while(1)
        {
            int kind, number;
            cout << "\nProduct number : ";
            cin >> kind;
            sentence += 'b';
            cout << "\ncheck string (y : yes n : no) : ";
            cin >> c;
            if(c == 'y')
                cout << (accept(sentence) ? "Accept\n" : "Reject\n") << endl;
            if(kind == -1)
                return 0;

            cout << "Number of products : ";
            cin >> number;
            sentence += 'b';
            cout << "\ncheck string (y : yes n : no) : ";
            cin >> c;
            if(c == 'y')
                cout << (accept(sentence) ? "Accept\n" : "Reject\n") << endl;
            tmp = menu(sentence, cost, kind, number, true);
            if(tmp == 1 || tmp == 2)
                break;
        }
        if(tmp == 2 || tmp == 1)
            system("pause");
    }
    return 0;
}

void showMenu()
{
    system("cls");
    cout << "Menu : " << endl;
    for(int i = 0 ; i < item.size(); i++)
    {
        cout << '(' << i + 1 << ") " << item[i].first;
        for(int j = 0; j < 20 - item[i].first.size(); j++)
            cout << ' ';
        cout << item[i].second.second << '$' << "\t\t" << item[i].second.first << endl;
    }
    cout << "(-1)Exit" << endl;
}

int menu(string &sentence, float &cost,int kind, int number, bool add)
{
    int num;
    char c;
    cout << "\n(1)Continue\n(2)Checkout\n(3)Clean\nEnter a number : ";
    cin >> num;
    if(num == 1)
    {
        if(kind <= 0 || kind > item.size() || number <= 0 ||number > (items.find(kind - 1) != items.end() ? item[kind - 1].second.first - items[kind - 1] : item[kind - 1].second.first))
        {
            cout << "Error" << endl;
            sentence += 'c';
            cout << "\ncheck string (y : yes n : no) : ";
            cin >> c;
            if(c == 'y')
                cout << (accept(sentence) ? "Accept\n" : "Reject\n") << endl;
        }
        else
        {
            sentence += 'd';
            cout << "\ncheck string (y : yes n : no) : ";
            cin >> c;
            if(c == 'y')
                cout << (accept(sentence) ? "Accept\n" : "Reject\n") << endl;
            cost += item[kind - 1].second.second * number;
            if (items.find(kind - 1) == items.end())
                items[kind - 1] = number;
            else
                items[kind - 1] = items[kind - 1] + number;
        }
        return 0;
    }
    if(num == 3)
    {
        sentence += 'a';
        cout << "\ncheck string (y : yes n : no) : ";
        cin >> c;
        if(c == 'y')
            cout << (accept(sentence) ? "Accept\n" : "Reject\n") << endl;
        items.clear();
        cost = 0;
        sentence += 'a';
        cout << "\ncheck string (y : yes n : no) : ";
        cin >> c;
        if(c == 'y')
            cout << (accept(sentence) ? "Accept\n" : "Reject\n") << endl;
        return 1;
    }
    if(num == 2)
    {
        if(add)
        {
            if(kind <= 0 || kind > item.size() || number <= 0 ||number > (items.find(kind - 1) != items.end() ? item[kind - 1].second.first - items[kind - 1] : item[kind - 1].second.first))
            {
                cout << "Error" << endl;
            }
            else
            {
                cost += item[kind - 1].second.second * number;
                if (items.find(kind - 1) == items.end())
                    items[kind - 1] = number;
                else
                    items[kind - 1] = items[kind - 1] + number;
            }
        }
        sentence += 'b';
        cout << "\ncheck string (y : yes n : no) : ";
        cin >> c;
        if(c == 'y')
            cout << (accept(sentence) ? "Accept\n" : "Reject\n") << endl;
        cout << "\n\nCost = " << cost << endl;
        sentence += 'a';
        cout << "\ncheck string (y : yes n : no) : ";
        cin >> c;
        if(c == 'y')
            cout << (accept(sentence) ? "Accept\n" : "Reject\n") << endl;
        string card, password;
        cout << "card number : " << endl;
        cin.ignore();
        getline(cin, card);
        if(card.size() == 16)
        {
            sentence += 'a';
            cout << "\ncheck string (y : yes n : no) : ";
            cin >> c;
            if(c == 'y')
                cout << (accept(sentence) ? "Accept\n" : "Reject\n") << endl;
        }
        else
        {
            sentence += 'b';
            cout << "\ncheck string (y : yes n : no) : ";
            cin >> c;
            if(c == 'y')
                cout << (accept(sentence) ? "Accept\n" : "Reject\n") << endl;
            return menu(sentence, cost, kind, number, false);
        }
        cout << "Card password : " << endl;
        cin.ignore();
        getline(cin, password);
        if(password.size() == 4)
        {
            sentence += 'a';
            cout << "check string (y : yes n : no) : ";
            cin >> c;
            if(c == 'y')
                cout << (accept(sentence) ? "Accept\n" : "Reject\n") << endl;
        }
        else
        {
            sentence += 'b';
            cout << "check string (y : yes n : no) : ";
            cin >> c;
            if(c == 'y')
                cout << (accept(sentence) ? "Accept\n" : "Reject\n") << endl;
            return menu(sentence, cost, kind, number, false);
        }
        if(card == "1234567890123456" && password == "1111")
        {
            sentence += 'c';
            cout << "check string (y : yes n : no) : ";
            cin >> c;
            if(c == 'y')
                cout << (accept(sentence) ? "Accept\n" : "Reject\n") << endl;
            ReciveProduct();
            sentence += 'c';
            cout << "\ncheck string (y : yes n : no) : ";
            cin >> c;
            if(c == 'y')
                cout << (accept(sentence) ? "Accept\n" : "Reject\n") << endl;
            return 2;
        }
        else
        {
            sentence += 'b';
            return menu(sentence, cost, kind, number, false);
        }
    }
    return 1;
}

void ReciveProduct()
{
    cout << endl;
    for(auto it = items.cbegin(); it != items.end(); ++it)
    {
        cout << item[it->first].first;
        for(int j = 0; j < 20 - item[it->first].first.size(); j++)
            cout << ' ';
        cout << it->second << endl;
        item[it->first].second.first -= it->second;
    }
    cout << endl;
}

bool accept(string sentence)
{
    cout << sentence << endl;
    if(sentence.size() >= 3  && sentence.substr(0, 3) == "abb")
    {
        sentence.erase(0,1);
        sentence.erase(0,1);
        sentence.erase(0,1);
    }
    else
        return false;
    reverse(sentence.begin(), sentence.end());
label:
    while (sentence.size() >= 1 && sentence.back() != 'b')
    {
        if(sentence.size() <= 3 || !((sentence.back() == 'c' || sentence.back() == 'd')))
            return false;
        while(sentence.size() >= 3 && (sentence.back() == 'c' || sentence.back() == 'd'))
        {
            sentence.pop_back();
            sentence.pop_back();
            sentence.pop_back();
        }
        while (sentence.size() >= 5 && (sentence.back() == 'a'))
        {
            sentence.pop_back();
            sentence.pop_back();
            sentence.pop_back();
            sentence.pop_back();
            sentence.pop_back();
        }
    }
    if(sentence.size() == 0)
        return false;
    sentence.pop_back();
    int i = 0;
    while(sentence.size() >= 1 && i++ < 3 && sentence.back() == 'a')
        sentence.pop_back();
    if(sentence.size() == 0)
        return false;
    if(i != 4)
    {
        sentence.pop_back();
        goto label;
    }
    if(sentence.size() == 1 && sentence == "c")
        return true;
    sentence.pop_back();
    if(sentence.size() == 1 && sentence == "c")
        return false;
    if(sentence.size() >= 3 && sentence.substr(sentence.size() - 3) == "abb")
    {
        sentence.pop_back();
        sentence.pop_back();
        sentence.pop_back();
        goto label;
    }
    return false;
}
