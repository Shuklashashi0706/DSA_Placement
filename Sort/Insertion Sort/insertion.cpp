#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Function prototype
void insertion(int arr[], int n);

int main()
{
    int n, i, j;
    cout << "Enter array size:" << endl;
    cin >> n;
    int arr[n]; // Declare an array of size n

    cout << "Enter elements:" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i]; // Input array elements
    }

    auto start = high_resolution_clock::now(); // Measure the start time

    insertion(arr, n); // Call the insertion sort function

    auto stop = high_resolution_clock::now(); // Measure the end time

    // Calculate the duration in milliseconds
    auto duration = duration_cast<milliseconds>(stop - start);

    // Print the sorted array
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }

    cout << "\nExecution time: " << duration.count() << " milliseconds" << endl;

    cout << endl;
    return 0;
}

// Insertion sort function
void insertion(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i <= n - 1; i++)
    {
        j = i; // Current element index

        while (j > 0 && arr[j - 1] > arr[j]) // Compare with the left element
        {

            // Swap the elements
            swap(arr[j],arr[j-1]);

            j--; // Move to the left
        }
    }
}
