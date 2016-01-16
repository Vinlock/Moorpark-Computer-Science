//
//  main.cpp
//  Homework1
//
//  Created by Vinlock on 1/14/16.
//  Copyright © 2016 PvP All Day. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

struct MonthlyBudget {
    double housing, utilities, household_expenses, transportation, food, medical, insurance, entertainment, clothing, misc;
};

void AskUser(MonthlyBudget budget);

const double
    HOUSING = 500.0,
    UTILITIES = 150.0,
    HOUSEHOLD_EXPENSES = 65.0,
    TRANSPORTATION = 50.0,
    FOOD = 250.00,
    MEDICAL = 30.0,
    INSURANCE = 100.0,
    ENTERTAINMENT = 150.0,
    CLOTHING = 75.0,
    MISC = 50.0;

const string
    OVER_BUDGET = "Over Budget by ",
    UNDER_BUDGET = "Under Budget by ",
    MET_BUDGET = "Met Budget!";

int main() {
    
    MonthlyBudget budget;
    AskUser(budget);
    
    
    
}

void AskUser(MonthlyBudget budget) {
    cout << "Please enter the amounts spent in each budget category during a month." << endl;
    
    cout << "Housing: ";
    cin >> budget.housing;
    
    cout << "Utilities: ";
    cin >> budget.utilities;
    
    cout << "Household Expenses: ";
    cin >> budget.household_expenses;
    
    cout << "Transportation: ";
    cin >> budget.transportation;
    
    cout << "Food: ";
    cin >> budget.food;
    
    cout << "Medical: ";
    cin >> budget.medical;
    
    cout << "Insurance: ";
    cin >> budget.insurance;
    
    cout << "Entertainment: ";
    cin >> budget.entertainment;
    
    cout << "Clothing: ";
    cin >> budget.clothing;
    
    cout << "Misc: ";
    cin >> budget.misc;
}

void Report(MonthlyBudget budget) {
    cout << "Your Budget:" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << 
}
