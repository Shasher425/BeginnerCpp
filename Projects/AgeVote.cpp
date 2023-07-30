#include <iostream>

using namespace std;
int main ()
{
 string firstName;
 string lastName;
 int age;
cout << "Type your first name: ";
cin >> firstName; 
cout << "Type your last name: ";
cin >> lastName; 
cout << "Type your age: ";
cin >> age

if (age <= 17){
    cout << "Hello ,  " << firstName<<" "<<lastName << "  .";
    cout << "  Your age is  " << age <<"." << "  Hence , you are not eligible to vote";
}
else{
     cout << "Hello ,  " << firstName<<" "<<lastName << " ";
    cout << "You are " << age << ".Congratulations  , You are  eligible to vote";
}


}

