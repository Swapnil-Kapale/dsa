#include <iostream>
#include <algorithm>
using namespace std;
// Structure to store the details of an employee.
struct Employee
{
    string name;
    int salary;
};
// Function to partition the array for Quick sort.
int Partition(Employee *arr, int low, int high)
{
    int pivot = arr[high].salary;
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j].salary <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
// Recursive function to sort the array using Quicksort.
void QuickSort(Employee *arr, int low, int high)
{
    if (low < high)
    {
        int pi = Partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}
int main()
{
    // Get the number of employees from the user.
    cout << "Enter the number of employees: ";
    int n;
    cin >> n;
    // Create an array of employees.
    Employee *employees = new Employee[n];
    // Get the details of each employee from the user.
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the name of employee " << i + 1 << ": ";
        cin >> employees[i].name;
        cout << "Enter the salary of employee " << i + 1
             << ": ";
        cin >> employees[i].salary;
    }
    // Sort the array of employees by salary using Quick sort.
    QuickSort(employees, 0, n - 1);
    // Display the details of the top five employees with the highest salary.
    cout << "Top 5 employees with highest salary:" << endl;
    for (int i = n - 1; i >= n - 5; i--)
    {
        cout << employees[i].name << ": " << employees[i].salary << endl;
    }
    // Free the dynamically allocated memory.
    delete[] employees;

    return 0;
}
