#include <iostream>
#include <string>

int main(){

    // loop variable to check if program should run
    bool run = true;
    //loop if user says yes to more calcuations
    while(run)
    {
        run = false;            // program will terminate at the end of the loop while run is false
        // initialize operation and num1 and num2, num3
        std::string operation = ""; int num1 = 0, num2 = 0, num3 = 0;
        bool error = false;

        //take input for operation and num1 and num2
        std::cout << "Please enter any operation +,-,*,/,%: ";
        std::cin >> operation;
        std::cout << "Please enter a numnber: ";
        std::cin >> num1;
        std::cout << "Please enter another number: ";
        std::cin >> num2;
    
        // make decision about which operation based off of input to operation variable and outputs
        if (operation == "+")
        {
             num3 = num1 + num2;
        }

        else if (operation == "-")
        {
            num3 = num1 - num2;
        }

        else if (operation == "*")
        {
            num3 = num1 * num2;
        }

        else if (operation == "/")
        {
            if (num2 != 0)  //check for divide by zero error
            {
                num3 = num1 / num2;
            }
            else
            {
                std::cout << "ERROR: Divded by Zero" << std::endl;
                error = true;
            }
        }

        else if (operation == "%")
        {
            num3 = num1 % num2;
        }
        else
        {
            std::cout << "ERROR: Undefined\n";
            error = true;
        }

      // ouptput calculated number
        if(error == false)
        {
            std::cout << "Output: " << num3 << std::endl;
        }
        std::string again = "";
        std::cout << "Would you like to run the program again? typen Y for yes or anything for no: ";
        std::cin >> again;
        if(again == "Y") //if user answered yes the program loops
         {
            run = true;
         }

    }


    return 0;
}