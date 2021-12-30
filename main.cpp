//
//  main.cpp
//  CPT111
//
//  Created by Rinsuki on 30/12/2021.
//

#include <iostream>
#include <string>

using namespace std;

// Headers
double hospitalStay();
double surgeryCharges();

int main()
{
    // Variable Definition
    // Maintaining...
    double totalCost = 0;
    
    // Menu
    // Maintaining...
    
    
    // Calculation
    totalCost += hospitalStay() + surgeryCharges();
    
}

// Prototypes

// Hospital costs (hospitalStay)
double hospitalStay(int days, double temp, int room, double rate, double cost, double foodPrice)
{
    // Check if the user input is not a positive integer
    cout << "days" << endl;
    cin >> temp; days = temp;
    
    while (days != temp || temp < 1)
    {
        cout << "Invalid input. The number of days spent in the hospital should be a positive integer." << endl;
        cin >> temp; days = temp;
    }
    
    cout << days << " days" << endl;
    
    // Hospital's daily rate base on room types (5+)
    // Maintaining...
    
    switch (room)
    {
        case 1:
            rate = 0;
            
            break;
            
        case 2:
            rate = 0;
            
            break;
            
        case 3:
            rate = 0;
            
            break;
            
        case 4:
            rate = 0;
            
            break;
            
        case 5:
            rate = 0;
            
            break;
            
        default:
            rate = 0;
            
            break;
    }
    
    // Daily rate
    cost += days * rate;
    
    // Food charges
    cout << "food or not 0no 1yes" << endl;
    cin >> temp;
    
    while (temp != 0 && temp != 1)
    {
        cout << "Invalid input." << endl;
        cin >> temp;
        
    }
    
    if (temp == 1) cost *= foodPrice;
    
    return cost;
}

// Surgery charges (surgeryCharges)
double surgeryCharges(int numType, int type, int temp, bool isZero, double charge, double cost = 0)
{
    cout << "surgery menu" << endl;
    cout << "types of surgery performed" << endl;
    cin >> numType;
    
    // Skip the calculating surgery charges function if not have
    if (numType == 0) return 0;
    
    // Check if less than 0 or larger than 10
    while (numType < 0 || numType > 10)
    {
        cout << "can't be less than 0 or larger than 10" << endl;
        cin >> numType;
        
    }
    
    // Calculation
    for (int i = 0; i < numType; i++)
    {
        cout << "which (" << i << "/" << numType << ")" << endl;
        cin >> type;
        
        // Check if less than 0 or larger than 10
        while (type < 0 || type > 10)
        {
            cout << "can't be less than 0 or larger than 5" << endl;
            cin >> type;
            
        }
        
        // How many surgeries done
        cout << "how many" << endl;
        cin >> temp;
        
        // Check if less than or equal to 0
        while (temp <= 0)
        {
            cout << "can't be less than or equal to 0" << endl;
            if (temp == 0)
            {
                cout << "r u sure it's 0? don't worry, we'll ignore it" << endl;
                cin >> isZero;
                if (isZero == true) break;
                else cout << "ok, please re-enter it" << endl;
            }
            cin >> temp;
            
        }
        
        // Charges of different surgeries
        switch (type)
        {
            case 1:
                charge = 0;
                
                break;
                
            case 2:
                charge = 0;
                
                break;
                
            case 3:
                charge = 0;
                
                break;
                
            case 4:
                charge = 0;
                
                break;
                
            case 5:
                charge = 0;
                
                break;
                
            case 6:
                charge = 0;
                
                break;
                
            case 7:
                charge = 0;
                
                break;
                
            case 8:
                charge = 0;
                
                break;
                
            case 9:
                charge = 0;
                
                break;
                
            case 10:
                charge = 0;
                
                break;
                
            default:
                
                break;
        }
        
        // Add up
        cost += (charge * temp);
        
    }
    
    return cost;
}
