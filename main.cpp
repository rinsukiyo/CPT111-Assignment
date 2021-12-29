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

int main()
{
    // Variable Definition
    // Maintaining...
    
    // Menu
    // Maintaining...
    
}

// Prototypes
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
