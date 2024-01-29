// Your First C++ Program
using namespace std;
#include <iostream>

/*
    1 Program that can find the sum and average of n numbers using loop. both for and while. prompt to enter the n number before performing any of the calculation. DONE

    2 Program that returns the sum of +ve numbers only using do while loop. if the user enters a -ve number, the loop ends and the sum of the +ve numbers is returned. DONE

    3 Generate Fibionacci sequence up to a certain number. DONE

    4 Integer number and that determines if the +ve, -ve or 0. Do this using nested if statements

*/
int main()
{
    // int n, num, sum = 0;
    // double avrg;

    // cout << "Enter number of integers to be summed: ";
    // cin >> n;

    // for (int x = 0; x < n; ++x)
    // {
    //     cout << "Enter number: ";
    //     cin >> num;
    //     sum += num;
    // }

    // avrg = sum / n;
    // cout << "Sum of " << n << " numbers is " << sum << "\n";
    // cout << "Average of " << n << " numbers is " << avrg << "\n";

    // int a, total = 0;

    // cout << "Enter a positive number: ";
    // cin >> a;
    // if (a > 0)
    // {
    //     total += a;
    //     cout << "Total: " << total << "\n";
    // }
    // else
    // {
    //     cout << "Total: 0\n";
    // }

    // do
    // {
    //     cout << "Enter a positive number: ";
    //     cin >> a;
    //     if (a > 0)
    //     {
    //         total += a;
    //         cout << "Total: " << total << "\n";
    //     }
    //     else
    //     {
    //         total -= a;
    //         cout << "Total: " << total << "\n";
    //     }

    // } while (a > 0);

    // int t, n1 = 0, n2 = 1, next = 0, i = 2;

    // cout << "Enter number of terms: ";
    // cin >> t;
    // cout << "Fibionacci sequence: " << n1 << " " << n2 << " ";
    // next = n1 + n2;

    // while (i < t)
    // {
    //     cout << next << " ";
    //     n1 = n2;
    //     n2 = next;
    //     next = n1 + n2;
    //     ++i;
    // }

    // cout << "\n";

    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (num== 0)
    {
        cout << "You entered 0.\n";
    }
    else
    {
        if (num < 0)
        {
            cout << num << " is a negative number\n";
        }
        else if (num > 0)
        {
            cout << num << " is a positive number\n";
        }
    }

    return 0;
}