#include <iostream>
#include <deque>

using namespace std;

// Constants
const int MAX_SPECIALIZATIONS = 20;
const int MAX_SPOTS_PER_SPECIALIZATIONS = 5;

// Struct of type patient to store patient data
struct patient {
  string name;
  bool status;
};
// Struct specialization contains spots for patients
struct specialization {
  // deque of patients
  deque<patient> patients;
};
// array of 20 specializations 
specialization specializations[MAX_SPECIALIZATIONS];

// menu function to take input from user
int menu() {
  int choice = -1;
  while (choice == -1) {
    cout << "Enter your choice:" << endl;
    cout << "1) Add new patients" << endl;
    cout << "2) Print all patients" << endl;
    cout << "3) Get new patient" << endl;
    cout << "4) Exit" << endl;

    cin >> choice;

    if (!(1 <= choice && choice <= 4)) {
      cout << "Invalid choice. Try again" << endl;
      choice = -1; // loop keep working
    }
  }
  return choice;
}

//function to add patient to the selected specialization
void add_patient() {
  int spec;
  string name;
  bool status;

  cin >> spec >> name >> status;
  // check specializations available slots
  if (specializations[spec-1].patients.size() < MAX_SPOTS_PER_SPECIALIZATIONS) {
    patient p;
    p.name = name;
    p.status = status;
    // check status
    if (status) {
      //Urgent patient add at front
      specializations[spec-1].patients.push_front(p);
    } else {
      //Regular patient add at back 
      specializations[spec-1].patients.push_back(p);
    }
  } else {
    cout << "Sorry we can't add more patients for this specialization." << endl;
  }
}

// function to print all patients in each specialization
void print_patients() {
  for (int i = 0; i < MAX_SPECIALIZATIONS; i++) 
  {
    if(!specializations[i].patients.empty()){
      cout << "There are " <<  specializations[i].patients.size() << "  patients at specialization " << i+1 << endl;
      // specializations[i].patients
      for(const auto & dq : specializations[i].patients){
        cout << dq.name ;
        dq.status ? cout <<" urgent" : cout <<" regular" ;
        cout << endl;
      }
      cout << endl;
    }
  }
}

//function to get next patient according to the selected specialization
void get_next_patient(){
  cout << "Enter specialization : ";
  int spec;
  cin >> spec;
  if(specializations[spec-1].patients.empty()){
    cout << "No patients at the moment. Have rest, Dr" << endl;
  }
  else{
    cout << specializations[spec-1].patients.front().name << " please go with the Dr" << endl;
    specializations[spec-1].patients.pop_front();
  }

}

int main() {
  while (1) {

    // Get user choice
    int choice = menu();

    // Perform action according to user choice
    switch (choice) {
    // Add new patient
    case 1:
      cout << "Enter specialization, name, status : ";
      add_patient();
      break;
    // Print all patients
    case 2:
      cout << "*********************************" << endl;
      print_patients();
      break;
    // Get next patient
    case 3:
      get_next_patient();
      break;
    // Exit
      case 4:
      cout << "Exit";
      return 0;
      break;
    default:
      cout << "Please Enter Valid Option" << endl;
      break;
    }
  }
  return 0;
}