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
    length1, width1, length2, width2;
    
    int solution1, solution2 = 0;
    
    // Ask for input
    cout << "Please enter the length and the width of the dining hall/room." << endl;
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
            cout << "Sorry, the " << endl;
        }
        
    } else if (length >= 2.1) {
        if (width >= 1.5) {
            
        } else if (width >= 1.0) {
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
        } else if (width >= 0.8) {
            
            
        } else if (width >= 0.76) {
            length1 =  0.76;
            width1 = 0.76;
            
        } else {
            cout << "Sorry, the " << endl;
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
            cout << "Sorry, the " << endl;
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
            cout << "Sorry, the " << endl;
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
            cout << "Sorry, the " << endl;
        }
        
    } else if (length >= 0.76) {
        if (width >= 0.76) {
            length1 = 0.76;
            width1 = 0.76;
            solution1 = 8;
            
        } else {
            cout << "Sorry, the " << endl;
        }
        
    } else {
        cout << "Sorry, the" << endl;
    }
    
    return 0;
    
}
