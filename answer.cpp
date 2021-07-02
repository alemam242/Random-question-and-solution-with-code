#include <bits/stdc++.h>
#include <cstring>
#include <unistd.h>
using namespace std;
#define INT "input_int.txt" // input file name for int
#define STR "input_string.txt" // input file name for string

/*
here used 4 sorting algorithm
1.Quicksort for sort int in ascending order
2.Insertion sort for int in descending order
3.Bubble sort for sort string in ascending order
4.Selection sort for sort string in descending order
*/

void sort_int_ass();
void sort_int_des();
void sort_string_ass();
void sort_string_des();

int quit()
{
    cout << "Thanks for using this program" << endl;
    return 0;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high], tmp;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);

    return i + 1;
}

void quicksort(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot;
        pivot = partition(a, low, high);

        quicksort(a, low, pivot - 1);
        quicksort(a, pivot + 1, high);
    }
    else
    {
        return;
    }
}

int main()
{
    system("CLS");
    int n;
    cout << "SORTING PROGRAM" << endl;
    cout << "\n1. Sort Integer" << endl;
    cout << "2. Sort String" << endl;
    cout << "0. EXIT" << endl;
    cout << "\n>>> ";
    cin >> n;

    if (n == 1)
    {
    back:
        cout << "1. Assending Order" << endl;
        cout << "2. Descending Order" << endl;
        cout << "\n>>> ";
        cin >> n;
        if (n == 1)
        {
            sort_int_ass();
        }
        else if (n == 2)
        {
            sort_int_des();
        }
        else
        {
            cout << "Choice Invalid!!!\n";
            system("pause");
            cout << endl;
            goto back;
        }
    }
    else if (n == 2)
    {
    back2:
        cout << "1. Assending Order" << endl;
        cout << "2. Descending Order" << endl;
        cout << "\n>>> ";
        cin >> n;
        if (n == 1)
        {
            sort_string_ass();
        }
        else if (n == 2)
        {
            sort_string_des();
        }
        else
        {
            cout << "Choice Invalid!!!\n";
            system("pause");
            cout << endl;
            goto back2;
        }
    }
    else if (n == 0)
    {
        quit();
    }
    else
    {
        cout << "Choice Invalid!!!" << endl;
        system("pause");
        main();
    }

    return 0;
}

void sort_int_ass()
{
    fstream file;
    file.open(INT, ios::in);
    int a[100];
    int i, j, tmp, n, x = 0;
    if (!file)
    {
        cout << "No such file" << endl;
    }
    else
    {
        while (!file.eof())
        {
            file >> n;
            a[x++] = n;
        }
    }

    quicksort(a, 0, x - 1); // Quicksort

    cout << "Sorted values are: ";
    for (i = 0; i < x; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    system("pause");
    main();
}

void sort_int_des()
{
    fstream file;
    file.open(INT, ios::in);
    int a[100];
    int i, j, tmp, n, x = 0;
    if (!file)
    {
        cout << "No such file" << endl;
    }
    else
    {
        while (!file.eof())
        {
            file >> n;
            a[x++] = n;
        }
    }
    //************************************
    for (i = 1; i < x; i++)
    {
        tmp = a[i];
        j = i - 1;
        while (a[j] < tmp && j >= 0) // insertion sort logic
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = tmp;
    }
    //**************************************
    cout << "Sorted values are: ";
    for (i = 0; i < x; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    system("pause");
    main();
}

void sort_string_ass()
{
    fstream file;
    file.open(STR, ios::in);
    char b[10];
    char a[10][40];
    char min[40];
    int k = 0, n, x;
    if (!file)
    {
        cout << "No such file" << endl;
    }
    else
    {
        while (!file.eof())
        {
            file >> b;
            strcpy(a[k++], b);
        }
    }
    //**********************************************
    char tmp[100];
    for (int j = 0; j < k - 1; j++)
    {
        for (int i = j + 1; i < k; i++)
        {
            if (strcmp(a[j], a[i]) > 0) // bubble sort logic
            {
                strcpy(tmp, a[j]);
                strcpy(a[j], a[i]);
                strcpy(a[i], tmp);
            }
        }
    }
    //*************************************************
    //*********************************************
    //cout << "Sorted strings are:\n";
    for (int i = 0; i < k; i++)
    {
        cout << a[i] << endl;
    }

    cout << endl;
    system("pause");
    main();
}

void sort_string_des()
{
    fstream file;
    file.open(STR, ios::in);
    char b[10];
    char a[10][40];
    char min[40];
    int k = 0, n, x;
    if (!file)
    {
        cout << "No such file" << endl;
    }
    else
    {
        while (!file.eof())
        {
            file >> b;
            strcpy(a[k++], b);
        }
    }
    //*******************************************
    for (int i = 0; i < k - 1; i++)
    {
        x = i;
        strcpy(min, a[i]);
        for (int j = i + 1; j < k; j++)
        {
            if ((strcmp(a[j], min)) > 0) //selection sort logic
            {
                strcpy(min, a[j]);
                x = j;
            }
        }
        strcpy(a[x], a[i]);
        strcpy(a[i], min);
    }
    //*********************************************
    cout << "Sorted strings are:\n";
    for (int i = 0; i < k; i++)
    {
        cout << a[i] << endl;
    }
    cout << endl;
    system("pause");
    main();
}