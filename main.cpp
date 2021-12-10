//
//  main.cpp
//  CPT111
//
//  Created by Rinsuki on 10/12/2021.
//

#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
    // Initialization
    int ceilingNum = 0, choiceNum, num,
    choice1 = 0, choice2 = 0,
    row = 1, column = 1, i = 1;
    
    float container1 = 0, container2 = 0, container3 = 0,
    price = 0;
    
    string processorName, temp, make,
    model1, model2, model3, model;
    
    // Open the file
    ifstream input;
    input.open("input2.txt");
    
    // Check if the file exists
    if (input.fail())
    {
        cout << "File not found." << endl;
        return 0;
        
    }
    
    // Choose the preferred make
    cout << "Please type the make that you prefer." << endl;
    cin >> make;
    
    // Type the number of the features (filter conditions)
    cout << "Please enter the number of the features. (1-2)" << endl;
    cin >> choiceNum;
    
    // Check if the number is not equal to 1 or 2
    while (choiceNum != 1 && choiceNum != 2)
    {
        cout << "Sorry, you can only choose 1 or 2 features as your preferences." << endl;
        cout << "Please enter the number of the features. (1-2)" << endl;
        cin >> choiceNum;
        
    }
    
    // Menu
    cout << "Welcome! This is a program which tries best to help you choose the most suitable device for you!\n" << endl;
    cout << "" << endl;
    
    // Get the numbering of the choice(s)
    while (choiceNum != 1 && choiceNum != 2)
    {
        cout << "Please enter the numbering of the choice(s) from the menu respectively. ("
        << i << "/" << choiceNum << ")" << endl;
        cin >> choiceNum;
        
    }
    
    
    // Assign the choice1 (if has) and the choice2
    switch (choiceNum)
    {
        case 1:
            cout << "Please enter the first feature. (1-9)" << endl;
            cin >> choice1;
            choice1 += 1;
            
        case 2:
            cout << "Please enter the second feature. (1-9)" << endl;
            cin >> choice2;
            choice2 += 1; // Adjust the numbering of the user input to the actual input file
            
            // Check if the choice1 and the choice2 are same
            while (choice1 == choice2)
            {
                cout << "Two features can't be the same value! Please re-enter the second feature. (1-9)" << endl;
                cin >> choice2;
                choice2 += 1;
                
            }
            break;
            
        default:
            break;
            
    }
    
    // Check the numbering of the choices
    if (choiceNum == 2)
    {
        // Judge if the feature is processor (string)
        if (choice2 == 4)
        {
            cout << "Please type a processor that you prefer." << endl;
            getline(cin, processorName);
            
            // Input
            while (input)
            {
                // If the column is 1
                if (column == 1)
                {
                    input >> model; column++;
                    
                }
                
                // If the column is 3
                else if (column == 3)
                {
                    input >> price;
                    column++;
                    
                    // Check if the price is higher than the ceiling price
                    if (price > ceilingNum)
                    {
                        i--;
                        
                        // Go to the next line and throw the useless data
                        nextline:
                        while (i <= 6)
                        {
                            input >> temp;
                            i++;
                        }
                        
                        row++;
                        column = 1;
                        
                    }
                    // Check Complete
                    
                    
                }
                
                // If the column is 4
                else if (column == 4)
                {
                    input >> temp;
                    
                    if (temp == processorName)
                    {
                        // Bubble Sort Manually
                        if (price > container3)
                        {
                            
                            if (price > container2)
                            {
                                
                                if (price > container1)
                                {
                                    // Move original price 1 to the 2nd
                                    container2 = container1;
                                    model2 = model1;
                                    
                                    // Assign new data to the price 1
                                    container1 = price;
                                    model1 = model;
                                    
                                }
                                
                                // Price is larger than the price 2 but less than the price 1
                                else
                                {
                                    // Move original price 2 to the 3rd
                                    container3 = container2;
                                    model3 = model2;
                                    
                                    // Assign new data to the price 2
                                    container2 = price;
                                    model2 = model;
                                    
                                }
                                
                            }
                            
                            // Price is larger than the pricee 3 but less than the price 2
                            else
                            {
                                container3 = price;
                                model3 = model;
                                
                            }
                            
                        }
                        
                        else goto nextline;
                        
                        
                    }
                    
                    else goto nextline;
                    
                }
                
            }
            
            // Display the result(s)
            if (container1 == 0)
            {
                // Maintaining...
                
            }
            
            // 1 result
            else if (container2 == 0)
            {
                cout << model1 << endl;
                cout << container1 << endl;
            }
            
            // 2 results
            else if (container3 == 0)
            {
                cout << model1 << endl;
                cout << container1 << endl;
                cout << model2 << endl;
                cout << container2 << endl;
                
                
            }
            
            // 3 results
            else
            {
                cout << model1 << endl;
                cout << container1 << endl;
                cout << model2 << endl;
                cout << container2 << endl;
                cout << model3 << endl;
                cout << container3 << endl;
                
            }
            
            
            
        }
        // Judgement END
        
        
    }
    
    
    
    return 0;
}
