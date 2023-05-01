#include <iostream>
#include <QString>
#include <QVector>
using namespace std;
void Set_Inf(QString **grph, int size)
{
    for (int i = 0 ; i < size ; i++)
    {
        for (int j = 0 ; j < size ; j++)
        {
            grph[i][j] = "INF";
        }
    }
    return;
}
bool repeated(QString *Qstr, int size)
{
    for (int i = 0 ; i < size ; i++)
    {
        if (Qstr[size][0] == Qstr[i][0])
        {
            return true;
        }
    }
    return false;
}
vector <pair<int,int>> v;
void loop(QString **grph,int curr, QString s, int start, int size)
{
    QString res = s;
    QString str = "";
    for (int j = 0 ; j < size; j++)
    {
        s = res;
        if (grph[curr][j] != "INF" && j == start)
        {
            str = grph[curr][j];
            s += str;
            grph[curr][j] = "INF";
            if (grph[start][start] == "INF")
            {
                grph[start][start] = '(' + s + ')';
            }
            else
            {
                for (int n = 0 ; n < grph[start][start].length(); n++)
                {
                    if (grph[start][start][n] != '(' || grph[start][start][n] != ')')
                    {
                        str += grph[start][start][n];
                    }
                }
                grph[start][start] = '(' + str + '+' + s + ')';
            }
            for (int i = 0 ; i < size; i++)
            {
                for (int j = 0 ; j < size + 1 ; j++)
                {
                    if (i == j && grph[i][j] != "INF" && grph[i][j] != "$")
                    {
                        int loop_state = i;
                        for (int k = 0 ; k < size + 1 ; k++)
                        {
                            if (i != k)
                            {
                                if (grph[i][k] != "INF")
                                {
                                    QString s = grph[i][k];
                                    grph[i][k] = '('+ grph[loop_state][loop_state] + '*' + s + ')';
                                }
                            }
                        }
                        grph[loop_state][loop_state] = "INF";
                    }
                }
            }
            return;
        }
        else if (grph[curr][j] != "INF")
        {
            str = grph[curr][j];
            s += str;
            loop(grph,j,s,start,size);
        }
    }
}
void find_loop(QString **grph, int size)
{
    for (int i = 0 ; i < size ; i++)
    {
        int start = i, curr = i;
        QString s = "";
        loop(grph,curr,s,start, size);
    }
}
void convert_to_re(QString **grph, int size)
{
    for (int k = 0; k < size + 1; k++) {
            for (int i = 0; i < size + 1; i++) {
                for (int j = 0; j < size + 1; j++)
                {
                    if (grph[i][k] != "INF" && grph[k][j] != "INF")
                    {
                        if (grph[i][j] == "INF")
                        {
                            grph[i][j] = grph[i][k] + grph[k][j];
                        }
                        else
                        {
                            grph[i][j] += '+' + grph[i][k] + grph[k][j];
                        }
                        grph[i][k] = "INF";
                        grph[k][j] = "INF";
                    }
                }
            }
        }
    cout << grph[0][size].toStdString() << endl;
}
void simplify(QString **grph, int size)
{
    for (int i = 0 ; i < size; i++)
    {
        for (int j = 0 ; j < size + 1 ; j++)
        {
            if (i == j && grph[i][j] != "INF" && grph[i][j] != "$")
            {
                int loop_state = i;
                for (int k = 0 ; k < size + 1 ; k++)
                {
                    if (i != k)
                    {
                        if (grph[i][k] != "INF")
                        {
                            QString s = grph[i][k];
                            grph[i][k] = '('+ grph[loop_state][loop_state] + '*' + s + ')';
                        }
                    }
                }
                grph[loop_state][loop_state] = "INF";
            }
        }
    }
    find_loop(grph,size);
    convert_to_re(grph,size);
}
void create_matrix(QString *Qstr, int n)
{
    QVector <QChar> st;
    int cnt = 0;
    for (int i = 0 ; i < n ; i++)
    {
        if (repeated(Qstr,i) == false)
        {
            st.push_back(Qstr[i][0]);
        }
    }
    QChar *variables = new QChar[st.size() + 1];
    for (auto ii = st.begin() ; ii != st.end(); ii++)
    {
        variables[cnt] = *ii;
        cnt++;
    }
    variables[cnt] = 'z';
    QString **grph = new QString *[cnt + 1];
    for (int i = 0 ; i < st.size() + 1; i++)
    {
        grph[i] = new QString[cnt + 1];
    }
    Set_Inf(grph,cnt + 1);
    for (int i = 0 ; i < cnt; i++)
    {
        for (int j = 0 ; j < cnt + 1; j++)
        {
                for (int k = 0 ; k < n ; k++)
                {
                    int len = Qstr[k].length();
                    if (Qstr[k][len - 1].isUpper() == true)
                    {
                        if (Qstr[k][0] == variables[i] && Qstr[k][len - 1] == variables[j])
                        {
                            QString s = "";
                            if (grph[i][j] != "INF")
                            {
                                s += '(';
                                s += grph[i][j];
                                s += '+';
                                for (int u = 2; u < len - 1; u++)
                                {
                                    if (Qstr[k][u] != '(' || Qstr[k][u] != ')')
                                    {
                                        s += Qstr[k][u];
                                    }
                                }
                                s += ')';
                            }
                            else
                            {
                                for (int u = 2; u < len - 1; u++)
                                {
                                    s += Qstr[k][u];
                                }
                            }
                            grph[i][j] = s;
                        }
                    }
                    else
                    {
                        if (Qstr[k][0] == variables[i] && j == cnt)
                        {
                            QString s = "";
                            if (grph[i][j] != "INF")
                            {
                                s += '(';
                                s += grph[i][j];
                                s += '+';
                                for (int u = 2; u < len; u++)// landa is $
                                {
                                    s += Qstr[k][u];
                                }
                                s += ')';
                                grph[i][j] = s;
                            }
                            else
                            {
                                for (int u = 2; u < len; u++)// landa is $
                                {
                                    s += Qstr[k][u];
                                }
                                grph[i][j] = s;
                            }
                        }
                    }
                }
        }
    }
    simplify(grph,cnt);
    return;
}
int main( void )
{
    int n = 0;
    cin >> n;
    string *str = new string[n];
    QString *Qstr = new QString[n];
    cin.ignore();
    for (int i = 0 ; i < n ; i++)
    {
        getline(std::cin, str[i]);
        Qstr[i] = str[i].c_str();
    }
    create_matrix(Qstr,n);
    return 0;
}
