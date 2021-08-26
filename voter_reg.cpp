#include <bits/stdc++.h>
using namespace std;
#define MAX 100
vector<string> name, fn, ad, pro;
vector<int> id, age;
class voter
{
public:
    void add()
    {
        system("CLS");
        cout << "\tADD VOTER\n\n";
        string n, n2, adr, pr;
        cout << "NAME: ";
        cin >> n;
        cout << "FATHER NAME: ";
        cin >> n2;
        int a, nid;
        cout << "AGE: ";
        cin >> a;
        cout << "NID NO: ";
        cin >> nid;
        cout << "ADDRESS: ";
        cin >> adr;
        cout << "PROVINCE: ";
        cin >> pr;
        name.push_back(n);
        fn.push_back(n2);
        age.push_back(a);
        id.push_back(nid);
        ad.push_back(adr);
        pro.push_back(pr);

        cout << "\nREGISTRATION SUCCESSFUL . . .\n\n";
    }
    void dis()
    {
        system("CLS");
        cout << "\tALL VOTER LIST\n\n";
        if (!name.empty())
        {
            for (int i = 0; i != name.size(); i++)
            {
                //cout << v[i] << " " << vv[i] << " " << s[i] << endl;
                cout << "NAME: " << name[i] << endl;
                cout << "FATHER NAME: " << fn[i] << endl;
                cout << "AGE: " << age[i] << endl;
                cout << "NID: " << id[i] << endl;
                cout << "ADDRESS: " << ad[i] << endl;
                cout << "PROVINCE: " << pro[i] << endl;
                cout << "\n";
            }
        }
        else
        {
            cout << "\tLIST IS EMPTY . . .\n\n";
        }
    }
    void ser()
    {
        system("CLS");
        cout << "\tSEARCH BY NAME\n\n";
        string s;
        cout << "ENTER NAME: ";
        cin >> s;
        int r[100], j = -1;
        for (int i = 0; i != name.size(); i++)
        {
            if (name[i] == s)
            {
                r[++j] = i;
            }
        }
        if (j < 0)
        {
            cout << "\nNot Found!\n";
        }
        else
        {
            if (j > 0)
            {
                cout << "\n\tMultiple Matching Found . . .\n\n";
                for (int i = 0; i <= j; i++)
                {
                    cout << "NAME: " << name[r[i]] << endl;
                    cout << "FATHER NAME: " << fn[r[i]] << endl;
                    cout << "AGE: " << age[r[i]] << endl;
                    cout << "NID: " << id[r[i]] << endl;
                    cout << "ADDRESS: " << ad[r[i]] << endl;
                    cout << "PROVINCE: " << pro[r[i]] << endl;
                    cout << "\n";
                }
            }
            else
            {
                cout << "\n\tMatching Found . . .\n\n";
                cout << "NAME: " << name[r[0]] << endl;
                cout << "FATHER NAME: " << fn[r[0]] << endl;
                cout << "AGE: " << age[r[0]] << endl;
                cout << "NID: " << id[r[0]] << endl;
                cout << "ADDRESS: " << ad[r[0]] << endl;
                cout << "PROVINCE: " << pro[r[0]] << endl;
                cout << "\n";
            }
        }
    }
    int quit()
    {
        cout << "THANKS FOR USING THIS PROGRAM\n\n";
        cout << "      SEE YOU AGAIN . . .\n\n";
        return 0;
    }
};

int main()
{
    system("CLS");
    voter obj;
    cout << "\tVOTER REGISTRATION APPLICATION\n\n";
    cout << "1. Add Voter Registration\n";
    cout << "2. Display All Voter List\n";
    cout << "3. Search by name\n";
    cout << "4. Exit\n";
    int n;
    cout << ">> ";
    cin >> n;
    if (n == 1)
    {
        obj.add();
        system("pause");
        main();
    }
    else if (n == 2)
    {
        obj.dis();
        system("pause");
        main();
    }
    else if (n == 3)
    {
        obj.ser();
        system("pause");
        main();
    }
    else if (n == 4)
    {
        obj.quit();
    }
}
