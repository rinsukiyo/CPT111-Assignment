//
//  main.cpp
//  CPT111
//
//  Created by Rinsuki on 21/01/2022.
//

#include <iostream>
#include <string>

using namespace std;

// Headers
void displayMenu();
int getPatientNum();

double hospitalStay(int &);
double surgeryCharges();
double pharmacyCharges();
double serviceCharges();
double eachCost(double, double, double, double);

void lowestAndHighest(double *, int);


int main()
{
    // Show the Menu
    displayMenu();
    
    // Get the number of the patients
    const int patientNum = getPatientNum();
    
    // Variable Definition
    double totalCost = 0, hospital[patientNum], surgery[patientNum], pharmacy[patientNum], service[patientNum], total[patientNum];
    int eachDays, totalDays = 0;
    
    // Send the values to the array
    for (int i = 0; i < patientNum; i++)
    {
        cout << "Please enter the details of patient " << i + 1 << ". (" << i + 1 << "/" << patientNum << ")" << endl;
        
        hospital[i] = hospitalStay(eachDays); totalDays += eachDays;
        surgery[i] = surgeryCharges(); pharmacy[i] = pharmacyCharges(); service[i] = serviceCharges();
        
    }
    
    // Display the costs of each patient, and calculate the total cost of each patient
    cout << "Costs of each patient: " << endl;
    for (int i = 0; i < patientNum; i++)
    {
        cout << "Patient " << i + 1 << endl;
        total[i] = eachCost(hospital[i], surgery[i], pharmacy[i], service[i]);
        
    }
    
    // Display the total costs of all the patients
    for (int i = 0; i < patientNum; i++) totalCost += total[i];
    cout << "The total costs of all the patients is $" << totalCost << ".\n" << endl;
    
    // Categorized by the different types
    double totalHospitalStay = 0, totalSurgery = 0, totalPharmacy = 0, totalService = 0;
    for (int i = 0; i < patientNum; i++)
    {
        totalHospitalStay += hospital[i]; totalSurgery += surgery[i];
        totalPharmacy += pharmacy[i]; totalService += service[i];
        
    }
    
    // Display the total costs of all the patients
    cout << "The total costs by different types are below: \n"
    << "The total costs of the hospital staying is $" << totalHospitalStay << "\n"
    << "Surgery charges is $" << totalSurgery << "\n"
    << "Pharmacy charges is $" << totalPharmacy << "\n"
    << "Service charges is $" << totalService << "\n" << endl;
    
    // Calculate and display the average hospital stay for each patient
    double avgStay = static_cast<double>(totalDays) / static_cast<double>(patientNum);
    cout << "The average hospital stay for each patient is " << avgStay << " days\n" << endl;
    
    // Find the patient who pays the highest bills, and who pays the lowest
    if (patientNum == 1)
    {
        cout << "The patient who pays lowest and the highest bills is patient 1." << endl;
        cout << "Lowest / Highest Bills: $" << total[0] << endl;
        
    } else lowestAndHighest(total, patientNum);
    
    return 0;
    
}

// Prototypes
void displayMenu()
{
    cout << "******************************************************************" << endl;
    cout << "********** Welcome to the hospital billing system 2.0! ***********" << endl;
    cout << "***** Please enter your choice according to the instructions *****" << endl;
    cout << "*********************** Type ENTER to start **********************" << endl;
    cout << "******************************************************************" << endl;
    cin.get();
    
}

// Get the number of the patients
// Input Validation: a positive integer
int getPatientNum()
{
    // Initialization
    double temp = 0.1;
    int num = 0;
    
    cout << "Please enter the number of the patients." << endl;
    cin >> temp;
    num = temp;
    
    while (num != temp || temp < 1)
    {
        cout << "Invalid input. The number of the patients should be a positive integer." << endl;
        cout << "Please re-enter the number of the patients." << endl;
        cin >> temp;
        num = temp;
        
    }
    
    return num;
}

// Hospital costs (hospitalStay)
double hospitalStay(int &days)
{
    // Variables Definition
    int room = 0;
    double cost = 0, foodPrice = 25, temp = 0, rate = 0;
    string roomName;
    
    // Check if the user input is negative
    cout << "Please enter the number of days the patient was hospitalized (if the patient was not hospitalized, please enter 0)." << endl;
    cin >> temp; days = temp;
    
    while (days != temp || temp < 0)
    {
        cout << "Invalid input. The number of the hospitalized days should be a non-negative integer. (0+)" << endl;
        cin >> temp; days = temp;
    }
    // Check END
    
    if (days == 0) return 0;
    
    // Display the number of the hospitalized days
    cout << "The patient was hospitalized for ";
    
    if (days == 1) cout << days << " day." << endl;
    else cout << days << " days." << endl;

    // Room Menu
    cout << "------------------------------------------------------------------" << endl;
    cout << "****************************Room Menu:****************************" << endl;
    cout << "*****************1.Twin Sharing Room: $100 per day****************" << endl;
    cout << "*****************2.Deluxe Room: $150 per day**********************" << endl;
    cout << "*****************3.Premium Deluxe: $170 per day*******************" << endl;
    cout << "*****************4.Suite: $200 per day****************************" << endl;
    cout << "*******Please enter the type of room chosen by patient (1-4)******" << endl;
    cin >> temp;
    room = temp;
    
    // Check if the user input is incorrect
    while (room < 1 || room > 4 || temp != room)
    {
        cout << "Invalid input. The number of the rooms should be a positive integer. (1-4)" << endl;
        cin >> temp;
        room = temp;
    }
    // Check END
    
    // Hospital's daily rate base on room types
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
    cout << "Patient have chosen Room Type " << room << ": " << roomName << ", which is $" << rate << " per day." << endl;
    
    // Food charges
    cout << "Did the patient eat any of the meals provided by the hospital during his or her stay? (Enter 1 for Yes, enter 0 for No)" << endl;
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
        
        // Display the prices of the meals
        if (days == 1) cout << "The prices of the meals for 1 day is $" << foodPrice << "." << endl;
        else cout << "The prices of the meals for " << days << " days is $" << foodPrice * days << "." << endl;
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
    cout << "------------------------------------------------------------------" << endl;
    cout << "**************************Surgery Menu:***************************" << endl;
    cout << "*****************1.heart valve replacement: $170,000**************" << endl;
    cout << "*****************2.heart bypass: $123,000*************************" << endl;
    cout << "*****************3.spinal fusion: $110,000************************" << endl;
    cout << "*****************4.hip replacement: $40,364***********************" << endl;
    cout << "*****************5.knee replacement: $35,000**********************" << endl;
    cout << "*****************6.angioplasty: $282,000**************************" << endl;
    cout << "*****************7.hip resurfacing: $28,000***********************" << endl;
    cout << "*****************8.gastric bypass: $25,000************************" << endl;
    cout << "*****************9.cornea: $17,500********************************" << endl;
    cout << "*****************10.gastric sleeve: $16,000***********************" << endl;
    
    cout << "How many different types of surgeries did the patient undergo in the hospital? (enter the number of types between 1-10, if the number is 0 then enter 0 to skip)" << endl;
    cin >> temp;
    numType = temp;
    
    // Check if less than or equal to 0, or larger than 10
    while (numType <= 0 || numType > 10 || temp != numType)
    {
        // Skip the calculating surgery charges function if not have
        if (numType == 0 && temp == numType) return 0;
        
        cout << "The number of different types of the surgery should be a non-negative integer (enter the number of types between 1-10, if the number is 0 then enter 0 to skip)" << endl;
        cin >> temp;
        numType = temp;
        
    }
    
    // Calculation
    for (int i = 1; i <= numType; i++)
    {
        cout << "Please enter the choice of surgery shown on the surgery menu (" << i << "/" << numType << ")" <<endl;
        cin >> temp;
        type = temp;
        
        // Check if less than 0 or larger than 10
        while (type <= 0 || type > 10 || type != temp)
        {
            cout << "Invalid input. The choice should be a positive integer (enter a number between 1-10)" << endl;
            cin >> temp;
            type = temp;
            
        }
        
        // How many times the surgery done
        cout << "How many times has the patient had this surgery done? (" << i << "/" << numType << ")" << endl;
        cin >> temp;
        timesSurgery = temp;
        
        // Check if less than or equal to 0
        while (timesSurgery <= 0 || timesSurgery != temp)
        {
            cout << "Invalid input. The times of the surgery done should be a positive integer. (0 to skip)" << endl;
            if (timesSurgery == 0)
            {
                cout << "Are you sure the times of the surgery is 0? Don't worry, we'll skip it if you want." << endl;
                cout << "Do you want to skip it? (1 - Yes, 0 - No)" << endl;
                cin >> isZero;
                if (isZero == true) break;
                else cout << "Please re-enter the times of the surgery." << endl;
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
    cout << "------------------------------------------------------------------" << endl;
    cout << "**************************Medication Menu*************************" << endl;
    cout << "**********************1.Surgical Bra:$30.70***********************" << endl;
    cout << "**********************2.Abdominal or Spinal support: $46.30*******" << endl;
    cout << "**********************3.Etanercept: $2,225************************" << endl;
    cout << "**********************4.Celecoxib: $225***************************" << endl;
    cout << "**********************5.Glatiramer: $3,903************************" << endl;
    cout << "**********************6.Duloxetine: $194**************************" << endl;
    cout << "**********************7.Esomeprazole: $215************************" << endl;
    
    cout << "How many different kinds of medications chosen by patient? (enter the number of kinds between 1-7, if the number is 0 then enter 0 to skip)" << endl;
    cin >> temp;
    numType = temp;
    
    // Check if less than 0 or larger than 7
    while (numType < 0 || numType > 7 || numType != temp)
    {
        // Skip the calculating medication charges function if not have
        if (numType == 0 && temp == numType) return 0;
        
        cout << "Invalid input. The kinds of the medications should be a non-negative integer, (enter the number of kinds between 1-7, if the number is 0 then enter 0 to skip)" << endl;
        cin >> temp;
        numType = temp;
        
    }
    
    // Calculation
    for (int i = 1; i <= numType; i++)
    {
        cout << "Please enter the choice of medication shown on the medication menu. (" << i << "/" << numType << ")" << endl;
        cin >> temp;
        type = temp;
        
        // Check if less than 0 or larger than 7
        while (type <= 0 || type > 7 || type != temp)
        {
            cout << "Invalid input. The choice of medication should be a positive integer. (enter the number of choice between 1-7)" << endl;
            cin >> temp;
            type = temp;
            
        }
        
        // How many times the medication used
        cout << "How many times is the current medication used? (" << i << "/" << numType << ")" << endl;
        cin >> temp;
        timesMeds = temp;
        
        // Check if less than or equal to 0
        while (timesMeds <= 0 || timesMeds != temp)
        {
            cout << "Invalid input. The times of the medication used should be a non-negative integer (1+, enter 0 to skip)" << endl;
            if (timesMeds == 0)
            {
                cout << "Are you sure the times of the medication used is 0? Don't worry, we'll skip it if you want." << endl;
                cout << "Do you want to skip it? (1 - Yes, 0 - No)" << endl;
                cin >> isZero;
                if (isZero == true) break;
                else cout << "Please re-enter the times of the medication used. (1+, enter 0 to skip)" << endl;
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
    int numType, type, frequency;
    double charge = 0, cost = 0, temp = 0;
    bool isZero;
    string serviceName;
    
    // Service menu
    cout << "------------------------------------------------------------------" << endl;
    cout << "**************************Service menu:***************************" << endl;
    cout << "********************1.X-ray/radiology:$100************************" << endl;
    cout << "********************2.laboratory test:$55*************************" << endl;
    cout << "********************3.physiotherapy:$60***************************" << endl;
    cout << "********************4.ultrasound:$130*****************************" << endl;
    cout << "********************5.bone mineral densitometry:$148**************" << endl;
    cout << "********************6.fluoroscopy:$245****************************" << endl;
    cout << "********************7.mammography:$130****************************" << endl;
    cout << "********************8.nuclear medicine:$120***********************" << endl;
    
    cout << "How many different types of services did the patient undergo in the hospital?(enter the number of type between 1-8, if the number is 0 then enter 0 to skip)" << endl;
    cin >> temp;
    numType = temp;
    
    // Check if less than or equal to 0, or larger than 8
    while (numType <= 0 || numType > 8 || numType != temp)
    {
        // Skip the calculating service charges function if not have
        if (numType == 0) return 0;
        
        cout << "Invalid input. The kinds of the services used should be a non-negative integer (enter the number of kinds between 1-8, if the number is 0 then enter 0 to skip)" << endl;
        cin >> temp;
        numType = temp;
        
    }
    
    // Calculation
    for (int i = 1; i <= numType; i++)
    {
        cout << "Please enter the choice of medication shown on the medication menu. (" << i << "/" << numType << ")" << endl;
        cin >> temp;
        type = temp;
        
        // Check if less than 0 or larger than 8
        while (type <= 0 || type > 8 || type != temp)
        {
            cout << "Invalid input. The choice of the service should be a positive integer. (enter a number between 1-8)" << endl;
            cin >> temp;
            type = temp;
            
        }
        
        // Get the duration of the service
        cout << "How many times is the current service done? (" << i << "/" << numType << ")" << endl;
        cin >> temp;
        frequency = temp;
        
        // Check if less than or equal to 0
        while (frequency <= 0 || frequency != temp)
        {
            cout << "Invalid input. The times of the service done should be a non-negative integer (1+, 0 to skip)" << endl;
            if (frequency == 0)
            {
                cout << "Are you sure the frequency of the service is 0? Don't worry, we'll skip it if you want." << endl;
                cout << "Do you want to skip it? (1 - Yes, 0 - No)" << endl;
                cin >> isZero;
                if (isZero == true) break;
                else cout << "Please re-enter the frequency of the service." << endl;
            }
            cin >> frequency;
            
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
        cost += (charge * frequency);
        
        // Display the details
        cout << serviceName << " x " << frequency << ", cost $" << (charge * frequency) << " (" << i << "/" << numType << ")" << endl;
        
    }
    
    return cost;
}

double eachCost(double hospital, double surgery, double pharmacy, double service)
{
    // Variable Definition
    double total = hospital + surgery + pharmacy + service;
    
    cout << "Hospital costs: $" << hospital << "\n"
    << "Surgery charges: $" << surgery << "\n"
    << "Pharmacy charges: $" << pharmacy << "\n"
    << "Service charges: $" << service << "\n"
    << "The total cost is $" << total << "\n\n";
    
    return total;
    
}

void lowestAndHighest(double *total, int num)
{
    // Initialize the lowest and the highest bills
    double lowest, highest;
    lowest = highest = total[0];
    string lowestPatient = "1", highestPatient = "1";
    
    for (int i = 1; i < num; i++)
    {
        
        // Lowest Bills
        if (total[i] <= lowest)
        {
            // If the costs of a patient is equal to another one, who has the lowest bills
            if (total[i] == lowest)
            {
                lowestPatient += (", " + to_string(i + 1));
                
            } else
            {
                lowest = total[i];
                lowestPatient = to_string(i + 1);
            }
            
        }
        
        // Highest Bills
        if (total[i] >= highest)
        {
            // If the costs of a patient is equal to another one, who has the highest bills
            if (total[i] == highest)
            {
                highestPatient += (", " + to_string(i + 1));
                
                
            } else
            {
                highest = total[i];
                highestPatient = to_string(i + 1);
            }
            
        }
        
        
    }
    
    // Display the results about who paying the highest bills and the lowest bills
    cout << "Paying the highest bills: Patient " << highestPatient << " ($" << highest << ")\n"
    << "Paying the lowest bills: Patient " << lowestPatient << " ($" << lowest << ")" << endl;
    
}
