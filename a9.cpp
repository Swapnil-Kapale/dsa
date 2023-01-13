#include <iostream>
#include <algorithm>
using namespace std;
const int N = 6; // Number of employees
struct Employee
{
    int id;
    string name;
    double salary;
};
void merge(double arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    double L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(double arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int main()
{
    Employee employees[N];
    for (int i = 0; i < N; i++)
    {
        cout << "Enter details for employee " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> employees[i].id;
        cout << "Name: ";
        cin >> employees[i].name;
        cout << "Salary: ";
        cin >> employees[i].salary;
    }
    double salary[N];
    for (int i = 0; i < N; i++)
        salary[i] = employees[i].salary;
    mergeSort(salary, 0, N - 1);
    cout << "Top five employees with highest salary:" << endl;
    for (int i = N - 1; i >= N - 5; i--)
    {
        for (int j = 0; j < N; j++)
        {
            if (employees[j].salary == salary[i])
            {
                cout << "ID: " << employees[j].id << endl;
                cout << "Name: " << employees[j].name << endl;
                cout << "Salary: " << employees[j].salary << endl;
            }
        }
    }
    return 0;
}
