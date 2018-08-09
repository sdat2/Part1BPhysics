// CharacterArray.cc
// Initialisation of a character array and passing to functions
#include <iostream>
using namespace std;

void PrintExtensionNumber(char phoneNumber[]);

int main(void){
char phone[11];
char prompt[] = "Enter telephone number: ";
   // Get phone number
   cout << prompt ;
   cin  >> phone ;
// If first two digits are 3 then it is a university number.
if( phone[0]=='3' && phone[1]=='3')
{
cout << "University extension ";
      PrintExtensionNumber(phone);
   }
else {
cout << "Dial 9-" << phone[0];
      PrintExtensionNumber(phone);
   }
return 0; }
// Function to print out a phone number, ignoring the first digit.

void PrintExtensionNumber(char phoneNumber[])
{
for(int i=1; phoneNumber[i] != '\0'; i++) {
     cout << phoneNumber[i];
   }
   cout << endl;
}
