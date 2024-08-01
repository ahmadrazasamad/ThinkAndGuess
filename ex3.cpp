#include <iostream>
#include <cctype>   // for tolower()
#include <unistd.h> // for sleep()
using namespace std;

int main()
{
    cout << "\t\t\t\t\t\t\tWelcome to Think and Guess\n"; // added /t here for printing it in the center
    cout << "Please specify a range by entering its starting and ending values.\n";

    // Input for range
    int start = 0, end = 0;
    cout << "Enter the starting point of the range: ";
    cin >> start;
    cin.ignore();
    cout << "Enter the ending point of the range: ";
    cin >> end;
    cin.ignore();

    cout << endl;

    while (start > end || start == end)
    {
        cout << "Ending point cannot be " << ((start == end) ? "equal to" : "less than") << " the starting point(" << start << ")!\n";
        cout << "Kindly re-enter the ending point: ";
        cin >> end;
        cin.ignore();

        if (start < end)
            cout << endl;
    }

    int numOfGuesses = 0;
    bool numberGuessed = false;
    cout << "Think of a number between " << start << "(inclusive) and " << end << "(inclusive)!!!\n";

    sleep(3); // a 3-seconds delay for enhancing UX

    do
    {
        numOfGuesses++;
        int mid = (start + end) / 2;
        int idealGuessedNumber = mid;

        char choice;
        cout << "Are you thinking of number " << idealGuessedNumber << "?\n";
        cout << "Press 'Y' for yes, 'L' if the number you are thinking is greater than " << idealGuessedNumber << ", or 'S' if the number you are thinking is smaller than " << idealGuessedNumber << ": ";
        cin >> choice;
        cin.ignore();
        choice = tolower(choice);

        while (choice != 'y' && choice != 'l' && choice != 's')
        {
            cout << "Wrong choice entered. Please re-enter: ";
            cin >> choice;
            cin.ignore();
            choice = tolower(choice);
        }

        if (choice == 'y')
        {
            numberGuessed = true;
            cout << "It took " << numOfGuesses << " guess(es) to guess " << idealGuessedNumber << ".\n";
        }
        else if (choice == 'l')
            start = mid + 1;
        else if (choice == 's')
            end = mid - 1;
    } while (!numberGuessed && start <= end);

    if (!numberGuessed)
        cout << "It seems there was a mistake. Please try again.\n";

    system("pause");
    return 0;
}