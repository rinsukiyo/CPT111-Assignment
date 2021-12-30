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
double pharmacyCharges();
double serviceCharges();

int main()
{
    // Variable Definition
    double totalCost = 0;
    
    // Menu
    // Maintaining...
    
    
    // Calculation
    totalCost = hospitalStay() + surgeryCharges() + pharmacyCharges() + serviceCharges();
    
    cout << "in total, " << totalCost << endl;
    
}

// Prototypes

// Hospital costs (hospitalStay)
double hospitalStay()
{
    // Variables Definition
    int days, room = 0;
    double cost = 0, foodPrice = 0, temp = 0, rate = 0;
    string roomName;
    
    // Check if the user input is not a positive integer
    cout << "days" << endl;
    cin >> temp; days = temp;
    
    while (days != temp || temp < 1)
    {
        cout << "Invalid input. The number of days spent in the hospital should be a positive integer." << endl;
        cin >> temp; days = temp;
    }
    
    cout << days << " days" << endl;
    // Check END
    
    // Hospital's daily rate base on room types (5+)
    // Maintaining...
    
    cout << "room menu" << endl;
    cin >> room;
    
    // Check if the user input is not a positive integer
    while (room < 1 || room > 4)
    {
        cout << "Invalid input. The number of the rooms should be 1-4." << endl;
        cin >> room;
    }
    // Check END
    
    switch (room)
    {
        case 1:
            rate = 0;
            roomName = "";
            
            break;
            
        case 2:
            rate = 0;
            roomName = "";
            
            break;
            
        case 3:
            rate = 0;
            roomName = "";
            
            break;
            
        case 4:
            rate = 0;
            roomName = "";
            
            break;
            
        case 5:
            rate = 0;
            roomName = "";
            
            break;
            
        default:
            rate = 0;
            roomName = "";
            
            break;
    }
    
    // Daily rate
    cost += days * rate;
    
    // Display the choice
    cout << "You have chosen room " << room << " " << roomName << ", which is $" << rate << " per day." << endl;
    
    // Food charges
    cout << "food or not 0no 1yes" << endl;
    cin >> temp;
    
    // Check if the input is invalid
    while (temp != 0 && temp != 1)
    {
        cout << "Invalid input." << endl;
        cin >> temp;
        
    }
    
    if (temp == 1)
    {
        cost += (foodPrice * days);
        // Display the prices of food
        cout << "The prices of food for " << days << " days is " << foodPrice << endl;
    }
    
    return cost;
}

// Surgery charges (surgeryCharges)
double surgeryCharges()
{
    // Variables Definition
    int numType, type, timesSurgery;
    double charge = 0, cost = 0;
    bool isZero;
    
    // Surgery menu
    cout << "surgery menu" << endl;
    cout << "num of types of surgery performed" << endl;
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
        
        // How many times the surgery done
        cout << "how many" << endl;
        cin >> timesSurgery;
        
        // Check if less than or equal to 0
        while (timesSurgery <= 0)
        {
            cout << "can't be less than or equal to 0" << endl;
            if (timesSurgery == 0)
            {
                cout << "r u sure it's 0? don't worry, we'll ignore it" << endl;
                cin >> isZero;
                if (isZero == true) break;
                else cout << "ok, please re-enter it" << endl;
            }
            cin >> timesSurgery;
            
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
        cost += (charge * timesSurgery);
        
    }
    
    return cost;
}

double pharmacyCharges()
{
    // Variables Definition
    int numType, type, timesMeds;
    double charge = 0, cost = 0;
    bool isZero;
    
    // Medication menu
    cout << "medication menu" << endl;
    cout << "num of types of medication" << endl;
    cin >> numType;
    
    // Skip the calculating pharmacy charges function if not have
    if (numType == 0) return 0;
    
    // Check if less than 0 or larger than 7
    while (numType < 0 || numType > 7)
    {
        cout << "can't be less than 0 or larger than 7" << endl;
        cin >> numType;
        
    }
    
    // Calculation
    for (int i = 0; i < numType; i++)
    {
        cout << "which (" << i << "/" << numType << ")" << endl;
        cin >> type;
        
        // Check if less than 0 or larger than 7
        while (type < 0 || type > 7)
        {
            cout << "can't be less than 0 or larger than 5" << endl;
            cin >> type;
            
        }
        
        // How many times the medication done
        cout << "how many" << endl;
        cin >> timesMeds;
        
        // Check if less than or equal to 0
        while (timesMeds <= 0)
        {
            cout << "can't be less than or equal to 0" << endl;
            if (timesMeds == 0)
            {
                cout << "r u sure it's 0? don't worry, we'll ignore it" << endl;
                cin >> isZero;
                if (isZero == true) break;
                else cout << "ok, please re-enter it" << endl;
            }
            cin >> timesMeds;
            
        }
        
        // Charges of different medications
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
                
            default:
                
                break;
        }
        
        // Add up
        cost += (charge * timesMeds);
        
    }
    
    return cost;
}

// Service charges (serviceCharges)
double serviceCharges()
{
    // Variables Definition
    int numType, type, duration;
    double charge = 0, cost = 0;
    bool isZero;
    
    // Service menu
    cout << "service menu" << endl;
    cout << "num of types of service services" << endl;
    cin >> numType;
    
    // Skip the calculating service charges function if not have
    if (numType == 0) return 0;
    
    // Check if less than 0 or larger than 10
    while (numType < 0 || numType > 8)
    {
        cout << "can't be less than 0 or larger than 8" << endl;
        cin >> numType;
        
    }
    
    // Calculation
    for (int i = 0; i < numType; i++)
    {
        cout << "which (" << i << "/" << numType << ")" << endl;
        cin >> type;
        
        // Check if less than 0 or larger than 8
        while (type < 0 || type > 8)
        {
            cout << "can't be less than 0 or larger than 8" << endl;
            cin >> type;
            
        }
        
        // Get the duration of the service
        cout << "how many" << endl;
        cin >> duration;
        
        // Check if less than or equal to 0
        while (duration <= 0)
        {
            cout << "can't be less than or equal to 0" << endl;
            if (duration == 0)
            {
                cout << "r u sure it's 0? don't worry, we'll ignore it" << endl;
                cin >> isZero;
                if (isZero == true) break;
                else cout << "ok, please re-enter it" << endl;
            }
            cin >> duration;
            
        }
        
        // Charges of different services
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
                
            default:
                
                break;
        }
        
        // Add up
        cost += (charge * duration);
        
    }
    
    return 0;
}
