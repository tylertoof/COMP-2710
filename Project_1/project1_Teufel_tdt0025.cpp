/* FILE NAME: project1_Teufel_tdt0025.cpp 
 * AUTHOR: Tyler Teufel 
 * 
 * No outside sources used besides the textbook,
 * Absolute C++.
 */ 
 
#include <iostream> 
using namespace std; 


int main() {
   //variable initialization
   double interestRate;
   double interestRateC;
   double loan;
   double monthlyPaid;
   int currentMonth = 0;
   double interestTotal;
   double monthlyInterest;
   double principle;
   
   
   
   
   //Currency formatting
   cout.setf(ios::fixed); 
   cout.setf(ios::showpoint); 
   cout.precision(2);
   
   // USER INPUT 
   // NOTE: For valid input, the loan, interest, and monthly payment must 
   // be positive. The monthly payment must also be large enough to 
   // terminate the loan. 
   cout << "\nLoan Amount: "; 
   cin >> loan;
   while (loan <= 0) {
      cout << "\n** The value must be positive! **";
      cout << "\nLoan Amount: ";
      cin >> loan;
   }
   cout << "Interest Rate (% per year): "; 
   cin >> interestRate;
   while (interestRate < 0) {
      cout << "\n** The value must be positive! **";
      cout << "\nInterest Rate (% per year): ";
      cin >> interestRate;
   }
   
   // GET PROPER INTEREST RATES FOR CALCULATIONS 
   interestRate /= 12; 
   interestRateC = interestRate / 100; 
   cout << "Monthly Payments: "; 
   cin >> monthlyPaid;
   while (monthlyPaid < loan * interestRateC) {
      cout << "\n** Insufficient payment! **";
      cout << "\nMonthly Payments: ";
      cin >> monthlyPaid;
   }
   
   cout << endl; 
  
   // AMORTIZATION TABLE 
   cout << "*****************************************************************\n" 
      << "\tAmortization Table\n" 
      << "*****************************************************************\n" 
      << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n"; 
 
   // LOOP TO FILL TABLE 
   while (loan > 0) { 
      if (currentMonth == 0) { 
         cout << currentMonth << "\t$" << loan;  
         if (loan < 1000) cout << "\t"; // Formatting MAGIC 
         cout << "\t" << "N/A\tN/A\tN/A\t\tN/A\n";  
          
      } 
      else {
         
         monthlyInterest = loan * interestRateC;
         if (loan * (1 + interestRateC) >= monthlyPaid) {
            principle = monthlyPaid - monthlyInterest;
            loan -= principle;
            interestTotal += monthlyInterest;
         
            cout << currentMonth << "\t$" << loan;
            if (loan < 1000) cout <<"\t";
            cout << "\t$" << monthlyPaid << "\t" << interestRate << "\t$" << monthlyInterest 
               << "\t\t$" << principle << "\n";
           
            
         }
         else {/*if (loan * (1 + interestRateC) < monthlyPaid)*/ 
            
            monthlyPaid = loan;
            principle = monthlyPaid + monthlyInterest;
            interestTotal += monthlyInterest;
            loan -= loan;
            
            cout << currentMonth << "\t$" << loan;
            if (loan < 1000) cout <<"\t";
            cout << "\t$" << principle << "\t" << interestRate << "\t$" << monthlyInterest 
               << "\t\t$" << monthlyPaid << "\n";
         }
      }
      currentMonth++; 
   }
   
   cout << "****************************************************************\n"; 
   cout << "\nIt takes " << --currentMonth << " months to pay off " 
        << "the loan.\n" 
        << "Total interest paid is: $" << interestTotal; 
   cout << endl << endl;  
   return 0;
   
   
   
}