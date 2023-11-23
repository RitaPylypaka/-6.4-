#include <iostream>
#include <iomanip>
#include <ctime> 
using namespace std;

void Create(int* x, const int size, const int Low, const int High, int i) {
    if (i < size) {
        x[i] = Low + rand() % (High - Low + 1);
        Create(x, size, Low, High, i + 1);
    }
}

int Dob(int* x, const int size, int s, int i) {
    if (i < size) {
        if (x[i] > 0) {
            s *= x[i];
            Dob(x, size, s, i + 1);
        }
        else
            Dob(x, size, s, i + 1);

    }
    else
        return s;
}
void Print(int* a, const int size, int i) {
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

int Sum(int* a, const int size, int i, int& l)
{
    if (i < size)
    {
        if (i < l)
            return a[i] + Sum(a, size, i + 1, l);
        else
            return Sum(a, size, i + 1, l);
    }
    else
        return 0;
}


int Min(int* a, const int size, int i, int min, int& l) {
    if (a[i] < min) {
        min = a[i];
        l = i;
    }
    if (i < size - 1)
        return Min(a, size, i + 1, min, l);
    else
        return l;
}

void Sort(int* a, const int size) {
    for (int i = 0; i < size - 1; i += 2) {
        int min = a[i];
        int imin = i;
        for (int j = i + 2; j < size; j += 2)
            if (min > a[j]) {
                min = a[j];
                imin = j;
            }
        a[imin] = a[i];
        a[i] = min;
    }
    for (int i = 1; i < size - 1; i += 2) {
        int min = a[i];
        int imin = i;
        for (int j = i + 2; j < size; j += 2)
            if (min > a[j]) {
                min = a[j];
                imin = j;
            }
        a[imin] = a[i];
        a[i] = min;
    }
}

int main() {
    srand((unsigned)time(NULL));
    int n;
    cout << "n= ";
    cin >> n;
    int* x = new int[n];

    int l = -1;

    int Low = -8;
    int High = 8;

    Create(x, n, Low, High, 0);
    Print(x, n, 0);
    cout << "Dob: " << Dob(x, n, 1, 0) << endl;
    int c = Min(x, n, 0, x[0], l);
    cout << "Sum: " << Sum(x, n, 0, l) << endl;
    Sort(x, n);
    Print(x, n, 0);

    delete[] x; // Free allocated memory

    return 0;
}
