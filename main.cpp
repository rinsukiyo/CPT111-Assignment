//
//  main.cpp
//  CPT111
//
//  Created by Rinsuki on 2021/11/19.
//

#include <iostream>

using namespace std;

int main() {
    // Initialization
    double length, width, temp,
    length1 = 0.0, width1 = 0.0, length2 = 0.0, width2 = 0.0,
    seat1 = 0.0, seat2 = 0.0;
    
    int solution1, solution2 = 0;
    
    // Ask for input
    cout << "Welcome! Looking for a new table fits your dining hall? We are here to help!" << endl;
    cout << "Please enter the length and the width of the dining hall or room." << endl;
    cin >> length >> width;
    
    // Interchange if the width is larger than the length
    if (width <= length) {
        temp = length;
        length = width;
        width = temp;
    }
    
    // Space Reservation
    length -= (1.0 + 0.6);
    width -= (1.0 + 0.6);
    
    // Judgement
    if (length >= 3) {
        if (width >= 1.3) {
            length1 = 3;
            width1 = 1.3;
            
            length2 = 3;
            width2 = 3;
            
            solution1 = 9;
            solution2 = 4;
        } else if (width >= 1) {
            length1 = 3;
            width1 = 1;
            
            length2 = 2.1;
            width2 = 1.0;
            
            solution1 = 4;
            solution2 = 3;
        } else if (width >= 0.9) {
            length1 = 1.5;
            width1 = 0.9;
            
            length2 = 1.3;
            width2 = 0.8;
            
            solution1 = 2;
            solution2 = 1;
        } else if (width >= 0.8) {
            length1 = 1.3;
            width1 = 0.8;
            
            length2 = 0.9;
            width2 = 0.9;
            
            solution1 = 1;
            solution2 = 7;
        } else if (width >= 0.76) {
            length1 = 0.76;
            width1 = 0.76;
            solution1 = 8;
            
        } else {
            solution1 = solution2 = 0;
            cout << "Sorry, we can't find a table that meets your requirements." << endl;
        }
        
    } else if (length >= 2.1) {
        if (width >= 1.0) {
            length1 = 2.1;
            width1 = 1.0;
            
            length2 = 1.5;
            width2 = 1.5;
            
            solution1 = 3;
            solution2 = 5;
        } else if (width >= 0.9) {
            length1 = 1.5;
            width1 = 0.9;
            
            length2 = 1.35;
            width2 = 1.35;
            
            solution1 = 2;
            solution2 = 6;
        } else if (width >= 0.76) {
            length1 =  0.76;
            width1 = 0.76;
            
            solution1 = 8;
            
        } else {
            solution1 = solution2 = 0;
            cout << "Sorry, we can't find a table that meets your requirements." << endl;
        }
        
    } else if (length >= 1.5) {
        if (width >= 1.5) {
            length1 = 1.5;
            width1 = 1.5;
            
            length2 = 1.5;
            width2 = 0.9;
            
            solution1 = 5;
            solution2 = 2;
        } else if (width >= 0.9) {
            length1 = 1.5;
            width1 = 0.9;
            
            length2 = 1.3;
            width2 = 0.8;
            
            solution1 = 2;
            solution2 = 1;
        } else if (width >= 0.8) {
            length1 = 1.3;
            width1 = 0.8;
            
            length2 = 0.9;
            width2 = 0.9;
            
            solution1 = 1;
            solution2 = 7;
        } else if (width >= 0.76) {
            length1 = 0.76;
            width1 = 0.76;
            solution1 = 1;
            
        } else {
            solution1 = solution2 = 0;
            cout << "Sorry, we can't find a table that meets your requirements." << endl;
        }
        
    } else if (length >= 1.35) {
        if (width >= 1.35) {
            length1 = 1.35;
            width1 = 1.35;
            
            length2 = 1.3;
            length2 = 0.8;
            
            solution1 = 6;
            solution2 = 1;
        } else if (width >= 0.8) {
            length1 = 1.3;
            width1 = 0.8;
            
            length2 = 0.76;
            width2 = 0.76;
            
            solution1 = 1;
            solution2 = 8;
        } else if (width >= 0.76) {
            length1 = 0.76;
            width1 = 0.76;
            solution1 = 8;
            
        } else {
            solution1 = solution2 = 0;
            cout << "Sorry, we can't find a table that meets your requirements." << endl;
        }
        
    } else if (length >= 0.9) {
        if (width >= 0.9) {
            length1 = 0.9;
            width1 = 0.9;
            
            length2 = 0.76;
            width2 = 0.76;
            
            solution1 = 7;
            solution2 = 8;
        } else if (width >= 0.76) {
            length1 = 0.76;
            width1 = 0.76;
            solution1 = 8;
            
        } else {
            solution1 = solution2 = 0;
            cout << "Sorry, we can't find a table that meets your requirements." << endl;
        }
        
    } else if (length >= 0.76) {
        if (width >= 0.76) {
            length1 = 0.76;
            width1 = 0.76;
            solution1 = 8;
            
        } else {
            solution1 = solution2 = 0;
            cout << "Sorry, we can't find a table that meets your requirements." << endl;
        }
        
    } else {
        solution1 = solution2 = 0;
        cout << "Sorry, we can't find a table that meets your requirements." << endl;
    }
    // Judgement END
    
    // Calculate the seats of the best choices
    // Define the number of the seats of Solution 1
    switch (solution1) {
        case 1:
            seat1 = 6;
            break;
            
        case 2:
            seat1 = 6;
            break;
            
        case 3:
            seat1 = 8;
            break;
            
        case 4:
            seat1 = 12;
            break;
            
        case 5:
            seat1 = 8;
            break;
            
        case 6:
            seat1 = 6;
            break;
            
        case 7:
            seat1 = 4;
            break;
            
        case 8:
            seat1 = 2;
            break;
            
        case 9:
            seat1 = 10;
            break;
            
        default:
            break;
    }
    // Define the number of the seats of Solution 1 END
    
    // Define the number of the seats of Solution 2
    switch (solution2) {
        case 1:
            seat2 = 6;
            break;
            
        case 2:
            seat2 = 6;
            break;
            
        case 3:
            seat2 = 8;
            break;
            
        case 4:
            seat2 = 12;
            break;
            
        case 5:
            seat2 = 8;
            break;
            
        case 6:
            seat2 = 6;
            break;
            
        case 7:
            seat2 = 4;
            break;
            
        case 8:
            seat2 = 2;
            break;
            
        case 9:
            seat2 = 10;
            break;
            
        default:
            break;
    }
    
    // Show the results
    // If two solutions exist
    if (solution1 != 0 && solution2 != 0) {
        cout << "Thanks for waiting. We have found 2 solutions for you. The number " << solution1 << " and the number " << solution2 << " are available." << endl;
        
        cout << "The number " << solution1 << " has " << seat1 << " seats, and the number " << solution2 << " has " << seat2 << " seats. (" << length1 << " x " << width1 << "m or " << length2 << " x " << width2 << "m)" << endl;
    
    // If only one solution exists
    } else if (solution1 != 0 & solution2 == 0) {
        cout << "Thanks for waiting. We have found 1 solution for you. The number " << solution1 << " is available." << endl;
        
        cout << "The number " << solution1 << " has " << seat1 << " seats. (" << length1 << " x" << width1 << "m)" << endl;
    }
    
    cout << "Have a nice day!" << endl;
    
    return 0;
    
}
