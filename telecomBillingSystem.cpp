#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

struct customer {
  string name;
  string id;
  int calls;
  int contact;
  float amount;
};
int total = 0;
customer c[100];
void bill() {

  if (total != 0) {
    string id;
    cout << "Enter Aadhaar no. of customer to generate a bill" << endl;
    cin >> id;
    for (int i = 0; i < total; i++) {
      if (c[i].id == id) {
        if (c[i].calls <= 100) {
          c[i].amount = 200;
        } else if (c[i].calls <= 150) {
          c[i].amount = 200 + 0.75 * (c[i].calls - 100);
        } else if (c[i].calls <= 200) {
          c[i].amount = 250 + 0.50 * (c[i].calls - 100);
        } else {

          c[i].amount = 255 + 0.25 * (c[i].calls - 200);
        }
        cout << "***********Bill************" << endl << endl;
        cout << "Name: " << c[i].name << endl;
        cout << "Aadhaar no.: " << c[i].id << endl;
        cout << "Contact: " << c[i].contact << endl;
        cout << "No. of Calls: " << c[i].calls << endl;
        cout << "Amount to be paid : " << c[i].amount << " Rs." << endl << endl;
        cout << "***************************" << endl << endl;
        break;
      }
      if (i == total - 1) {
        cout << "No such record found" << endl;
      }
    }
  } else {
    cout << "No data is entered" << endl;
  }
}
void add() {
  int user = 0;
  cout << "How many customer data do you want to enter??" << endl;
  cin >> user;
  for (int i = total; i < total + user; i++) {
    cout << "Enter data of customer " << i + 1 << endl << endl;
    cout << "Enter name: ";
    cin >> c[i].name;
    cout << "Enter aadhaar no. : ";
    cin >> c[i].id;
    cout << "Enter contact: ";
    cin >> c[i].contact;
    cout << "Enter calls: ";
    cin >> c[i].calls;
  }
  total = total + user;
}

void show() {
  if (total != 0) {
    for (int i = 0; i < total; i++) {
      cout << "\nData of customer " << i + 1 << endl << endl;
      cout << "Name: " << c[i].name << endl;
      cout << "Aadhaar no. : " << c[i].id << endl;
      cout << "Contact: " << c[i].contact << endl;
      cout << "No. of Calls: " << c[i].calls << endl;
    }
  } else {
    cout << "No data is entered" << endl;
  }
}
void search() {
  if (total != 0) {
    string id;
    cout << "Enter Aadhaar no. of customer which you want to search" << endl;
    cin >> id;
    for (int i = 0; i < total; i++) {
      if (c[i].id == id) {
        cout << "\nData of customer " << i + 1 << endl;
        cout << "Name: " << c[i].name << endl;
        cout << "Aadhaar no.: " << c[i].id << endl;
        cout << "Contact: " << c[i].contact << endl;
        cout << "No. of Calls: " << c[i].calls << endl;
        break;
      }
      if (i == total - 1) {
        cout << "No such record found" << endl;
      }
    }
  } else {
    cout << "No data is entered" << endl;

  }
}
void update() {
  if (total != 0) {
    string id;
    cout << "Enter Aadhaar no. of customer which you want to update" << endl;
    cin >> id;
    for (int i = 0; i < total; i++) {
      if (c[i].id == id) {

        cout << "\nOld data of customer " << i + 1 << endl << endl;
        cout << "Name: " << c[i].name << endl;
        cout << "Aadhaar no.: " << c[i].id << endl;
        cout << "Contact: " << c[i].contact << endl;
        cout << "No. of Calls: " << c[i].calls << endl;
        cout << "\nEnter new data" << endl;
        cout << "\nEnter customer name: ";
        cin >> c[i].name;
        cout << "Enter id: ";
        cin >> c[i].id;
        cout << "Enter contact: ";
        cin >> c[i].contact;
        cout << "Enter calls: ";
        cin >> c[i].calls;
        break;
      }
      if (i == total - 1) {
        cout << "No such record found" << endl;
      }
    }
  } else {
    cout << "No data is entered" << endl;
  }
}
void del() {
  if (total != 0) {

    int press;
    cout << "Press 1 to delete specific record" << endl;
    cout << "Press 2 to delete full record" << endl;
    cin >> press;
    if (press == 1) {
      string id;
      cout << "Enter Aadhaar no. of customer which you want to delete" << endl;
      cin >> id;
      for (int i = 0; i < total; i++) {
        if (c[i].id == id) {
          c[i].name = c[i + 1].name;
          c[i].id = c[i + 1].id;
          c[i].contact = c[i + 1].contact;
          c[i].calls = c[i + 1].calls;
          total--;
          cout << "Your required record is deleted" << endl;

          break;
        }
        if (i == total - 1) {
          cout << "No such record found" << endl;
        }
      }
    } else if (press == 2) {
      total = 0;

      cout << "All record is deleted" << endl;
    } else {
      cout << "Invalid Input" << endl;
    }
  } else {
    cout << "No data is entered" << endl;
  }
}
int main() {

  cout << "\n\n\t\tTelecom Billing Management System" << endl << endl;
  string username, password;
  cout << "\n\n\n\t\t******SIGN UP******" << endl;
  cout << "\t\tEnter new username: ";
  cin >> username;
  cout << "\t\tEnter new password: ";
  cin >> password;
  cout << "\t\tYour new id is creating please wait";
  for (int i = 0; i < 3; i++) {
    cout << ".";
    Sleep(200);
  }
  cout << "\n\t\tYour id is created successfully";
  Sleep(1000);
  start:
    system("CLS");
  string usrn, pswd;
  cout << "\n\n\t\tTelecom Billing Management System" << endl;
  cout << "\n\n\n\t\t******LOGIN******" << endl;
  cout << "\t\tEnter username: ";
  cin >> usrn;
  cout << "\t\tEnter password: ";
  cin >> pswd;
  if (usrn == username && pswd == password) {
    system("CLS");
    char ch;
    while (1) {
      cout << "\n\nPress 1 to enter data" << endl;
      cout << "Press 2 to show data" << endl;
      cout << "Press 3 to generate bill" << endl;
      cout << "Press 4 to search data" << endl;
      cout << "Press 5 to update data" << endl;
      cout << "Press 6 to delete data" << endl;
      cout << "Press 7 to logout" << endl;
      cout << "Press 8 to exit" << endl;
      ch = _getch();
      system("CLS");

      switch (ch) {
      case '1':
        add();
        break;
      case '2':
        show();
        break;
      case '3':
        bill();
        break;
      case '4':
        search();
        break;
      case '5':
        update();
        break;
      case '6':
        del();
        break;
      case '7':
        goto start;
        break;
      case '8':
        exit(0);
      default:
        cout << "\aInvalid Input" << endl;
        break;

      }
    }
  } else if (usrn != username) {
    cout << "\t\t\aInvalid username please try again";
    Sleep(1000);
    goto start;
  } else if (pswd != password) {
    cout << "\t\t\aInvalid password please try again";
    Sleep(1000);
    goto start;
  } else {
    cout << "\t\t\aInvalid username and password";
    Sleep(1000);
    goto start;
  }
}