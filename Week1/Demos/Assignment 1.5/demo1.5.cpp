#include <iostream>
#include <string>

int main()
{
    // loop variable to check if program should run
    bool run = true;
    // loop if user asks to run program again
    while (run)
    {
        run = false;   // assume program terminates unles user says otherwise
        char operation = 0; 
        int num1 = 0;
        int num2 = 0;
        int num3 = 0;
        bool error = false;

        // takes the input for operation and numbers
        std::cout << "Please enter any operation +,-,*,/,%: ";
        while (!(std::cin >> operation) || 
            (operation != '+' && operation != '-' 
                && operation != '*' && operation != '/' && operation != '%'))
        {
            std::cout << "ERROR: Invalid operation\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Please enter a valid operation: ";
        }

        std::cout << "Please enter a number: ";
        while (!(std::cin >> num1))
        {
            std::cout << "ERROR: Invalid number\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Please enter a valid number: ";
        }

        std::cout << "Please enter another number: ";
        while (!(std::cin >> num2))
        {
            std::cout << "ERROR: Invalid number\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Please enter a valid number: ";
        }

        // chooses the user inputted operation
        switch (operation)
        {
            case '+':
                num3 = num1 + num2;
                break;

            case '-':
                num3 = num1 - num2;
                break;

            case '*':
                num3 = num1 * num2;
                break;

            case '/':
                if (num2 != 0)  // check for divide by zero error
                {
                    num3 = num1 / num2;
                }
                else
                {
                    std::cout << "ERROR: Divded by Zero" << std::endl;
                    error = true;
                }
                break;

            case '%':
                num3 = num1 % num2;
                break;
        }

        // output calculated number if there was no error
        if (error == false)
        {
            std::cout << "Output: " << num3 << std::endl;
        }
        std::string again = "";
        std::cout << "Would you like to run the program again? typen Y for yes or anything for no: ";
        std::cin >> again;
        if (again == "Y") // if user answered yes the program loops
         {
            run = true;
         }

    }

    return 0;
}