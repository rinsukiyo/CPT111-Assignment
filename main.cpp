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
    double totalCost = 0, hospital, surgery, pharmacy, service;
    
    // Menu
    // Maintaining...
    cout << "Welcome!" << endl;
    
    // Calculation
    hospital = hospitalStay();
    surgery = surgeryCharges();
    pharmacy = pharmacyCharges();
    service = serviceCharges();
    
    totalCost = hospital + surgery + pharmacy + service;
    
    // Display the charges separately and the total cost
    cout << "Hospital costs: $" << hospital << "\n"
         << "Surgery charges: $" << surgery << "\n"
         << "Pharmacy charges: $" << pharmacy << "\n"
         << "Service charges: $" << service << ".\n";
    
    cout << "Totally, the charge is $" << totalCost << endl;
    
}

// Prototypes

// Hospital costs (hospitalStay)
double hospitalStay()
{
    // Variables Definition
    int days, room = 0;
    double cost = 0, foodPrice = 25, temp = 0, rate = 0;
    string roomName;
    
    // Check if the user input is negative
    cout << "days" << endl;
    cin >> temp; days = temp;
    
    while (days != temp || temp < 0)
    {
        cout << "Invalid input. The number of days spent in the hospital should be an integer larger than or equal to 0." << endl;
        cin >> temp; days = temp;
    }
    // Check END
    
    if (days == 0) return 0;
    
    // Display the days spend in the hospital
    if (days == 1) cout << days << " day" << endl;
    else cout << days << " days" << endl;

    
    // Hospital's daily rate base on room types (5+)
    // Maintaining...
    
    // Room Menu
    cout << "room menu" << endl;
    cin >> room;
    
    // Check if the user input is not a positive integer
    while (room < 1 || room > 4 || temp != room)
    {
        cout << "Invalid input. The number of the rooms should be a positive integer from 1 to 4." << endl;
        cin >> temp;
        room = temp;
    }
    // Check END
    
    switch (room)
    {
        case 1:
            rate = 100;
            roomName = "Twin Sharing Room";
            break;
            
        case 2:
            rate = 150;
            roomName = "Deluxe Room";
            break;
            
        case 3:
            rate = 170;
            roomName = "Premium Deluxe";
            break;
            
        case 4:
            rate = 200;
            roomName = "Suite";
            break;
            
        default:
            break;
    }
    
    // Daily rate
    cost += days * rate;
    
    // Display the choice
    cout << "You have chosen Room Type " << room << ": " << roomName << ", which is $" << rate << " per day." << endl;
    
    // Food charges
    cout << "Food or not? (0no 1yes)" << endl;
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
        if (days == 1) cout << "The prices of food for 1 day is $" << foodPrice << "." << endl;
        else cout << "The prices of food for " << days << " days is $" << foodPrice * days << "." << endl;
    }
    
    return cost;
}

// Surgery charges (surgeryCharges)
double surgeryCharges()
{
    // Variables Definition
    int numType, type, timesSurgery;
    double charge = 0, cost = 0, temp = 0;
    bool isZero;
    string surgeryName;
    
    // Surgery Menu
    cout << "surgery menu" << endl;
    cout << "num of types of surgery performed" << endl;
    cin >> temp;
    numType = temp;
    
    // Check if less than or equal to 0, or larger than 10
    while (numType <= 0 || numType > 10 || temp != numType)
    {
        // Skip the calculating surgery charges function if not have
        if (numType == 0 && temp == numType) return 0;
        
        cout << "The number of the types of the surgeires should be a non-negative integer from 0 to 10." << endl;
        cin >> temp;
        numType = temp;
        
    }
    
    // Calculation
    for (int i = 1; i <= numType; i++)
    {
        cout << "which (" << i << "/" << numType << ")" << endl;
        cin >> temp;
        type = temp;
        
        // Check if less than 0 or larger than 10
        while (type <= 0 || type > 10 || type != temp)
        {
            cout << "integer, can't be less than or equal to 0, or larger than 10" << endl;
            cin >> temp;
            type = temp;
            
        }
        
        // How many times the surgery done
        cout << "how many" << endl;
        cin >> temp;
        timesSurgery = temp;
        
        // Check if less than or equal to 0
        while (timesSurgery <= 0 || timesSurgery != temp)
        {
            cout << "integer, can't be less than or equal to 0" << endl;
            if (timesSurgery == 0)
            {
                cout << "r u sure it's 0? don't worry, we'll ignore it (1yes 0no, i'll re-enter a number)" << endl;
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
                charge = 170000;
                surgeryName = "heart valve replacement";
                
                break;
                
            case 2:
                charge = 123000;
                surgeryName = "heart bypass";
                
                break;
                
            case 3:
                charge = 110000;
                surgeryName = "spinal fusion";
                
                break;
                
            case 4:
                charge = 40364;
                surgeryName = "hip replacement";
                
                break;
                
            case 5:
                charge = 35000;
                surgeryName = "knee replacement";
                
                break;
                
            case 6:
                charge = 282000;
                surgeryName = "angioplasty";
                
                break;
                
            case 7:
                charge = 28000;
                surgeryName = "hip resurfacing";
                
                break;
                
            case 8:
                charge = 25000;
                surgeryName = "gastric bypass";
                
                break;
                
            case 9:
                charge = 17500;
                surgeryName = "cornea";
                
                break;
                
            case 10:
                charge = 16000;
                surgeryName = "gastric sleeve";
                
                break;
                
            default:
                
                break;
        }
        
        // Add up
        cost += (charge * timesSurgery);
        
        // Display the details
        cout << surgeryName << " x " << timesSurgery << ", cost $" << (charge * timesSurgery) << " (" << i << "/" << numType << ")" << endl;
    }
    
    return cost;
}

double pharmacyCharges()
{
    // Variables Definition
    int numType = 0, type, timesMeds;
    double charge = 0, cost = 0, temp = 0;
    bool isZero;
    string medsName;
    
    // Medication menu
    cout << "medication menu" << endl;
    cout << "num of types of medication" << endl;
    cin >> temp;
    numType = temp;
    
    // Check if less than 0 or larger than 7
    while (numType < 0 || numType > 7 || numType != temp)
    {
        // Skip the calculating surgery charges function if not have
        if (numType == 0 && temp == numType) return 0;
        
        cout << "an integer, can't be less than 0 or larger than 7" << endl;
        cin >> temp;
        numType = temp;
        
    }
    
    // Calculation
    for (int i = 1; i <= numType; i++)
    {
        cout << "which (" << i << "/" << numType << ")" << endl;
        cin >> temp;
        type = temp;
        
        // Check if less than 0 or larger than 7
        while (type <= 0 || type > 7 || type != temp)
        {
            cout << "integer, can't be less than or equal to 0, or larger than 7" << endl;
            cin >> temp;
            type = temp;
            
        }
        
        // How many times the medication done
        cout << "how many" << endl;
        cin >> temp;
        timesMeds = temp;
        
        // Check if less than or equal to 0
        while (timesMeds <= 0 || timesMeds != temp)
        {
            cout << "integer, can't be less than or equal to 0" << endl;
            if (timesMeds == 0)
            {
                cout << "r u sure it's 0? don't worry, we'll ignore it (1yes 0no, i'll re-enter a number)" << endl;
                cin >> isZero;
                if (isZero == true) break;
                else cout << "ok, please re-enter it" << endl;
            }
            cin >> temp;
            timesMeds = temp;
            
        }
        
        // Charges of different medications
        switch (type)
        {
            case 1:
                charge = 30.7;
                medsName = "Surgical bra";
                
                break;
                
            case 2:
                charge = 46.3;
                medsName = "Abdominal or spinal support";
                
                break;
                
            case 3:
                charge = 2225;
                medsName = "Etanercept";
                
                break;
                
            case 4:
                charge = 225;
                medsName = "Celecoxib";
                
                break;
                
            case 5:
                charge = 3903;
                medsName = "Glatiramer";
                
                break;
                
            case 6:
                charge = 194;
                medsName = "Duloxetine";
                
                break;
                
            case 7:
                charge = 215;
                medsName = "Esomeprazole";
                
                break;
                
            default:
                
                break;
        }
        
        // Add up
        cost += (charge * timesMeds);
        
        // Display the details
        cout << medsName << " x " << timesMeds << ", cost $" << (charge * timesMeds) << " (" << i << "/" << numType << ")" << endl;
        
    }
    
    return cost;
}

// Service charges (serviceCharges)
double serviceCharges()
{
    // Variables Definition
    int numType, type, duration;
    double charge = 0, cost = 0, temp = 0;
    bool isZero;
    string serviceName;
    
    // Service menu
    cout << "service menu" << endl;
    cout << "num of types of service services" << endl;
    cin >> temp;
    numType = temp;
    
    // Check if less than or equal to 0, or larger than 10
    while (numType <= 0 || numType > 8 || numType != temp)
    {
        // Skip the calculating service charges function if not have
        if (numType == 0) return 0;
        
        cout << "integer, can't be less than 0 or larger than 8" << endl;
        cin >> temp;
        numType = temp;
        
    }
    
    // Calculation
    for (int i = 1; i <= numType; i++)
    {
        cout << "which (" << i << "/" << numType << ")" << endl;
        cin >> temp;
        type = temp;
        
        // Check if less than 0 or larger than 8
        while (type <= 0 || type > 8 || type != temp)
        {
            cout << "integer, can't be less than or equal to 0, or larger than 8" << endl;
            cin >> temp;
            type = temp;
            
        }
        
        // Get the duration of the service
        cout << "how many" << endl;
        cin >> temp;
        duration = temp;
        
        // Check if less than or equal to 0
        while (duration <= 0 || duration != temp)
        {
            cout << "integer, can't be less than or equal to 0" << endl;
            if (duration == 0)
            {
                cout << "r u sure it's 0? don't worry, we'll ignore it (1yes 0no, i'll re-enter a number)" << endl;
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
                charge = 100;
                serviceName = "X-ray/radiology";
                
                break;
                
            case 2:
                charge = 55;
                serviceName = "laboratory test";
                
                break;
                
            case 3:
                charge = 60;
                serviceName = "physiotherapy";
                
                break;
                
            case 4:
                charge = 130;
                serviceName = "ultrasound";
                
                break;
                
            case 5:
                charge = 148;
                serviceName = "bone mineral densitometry";
                
                break;
                
            case 6:
                charge = 245;
                serviceName = "fluoroscopy";
                
                break;
                
            case 7:
                charge = 130;
                serviceName = "mammography";
                
                break;
                
            case 8:
                charge = 120;
                serviceName = "nuclear medicine";
                
                break;
                
            default:
                
                break;
        }
        
        // Add up
        cost += (charge * duration);
        
        // Display the details
        cout << serviceName << " x " << duration << ", cost $" << (charge * duration) << " (" << i << "/" << numType << ")" << endl;
        
    }
    
    return 0;
}
