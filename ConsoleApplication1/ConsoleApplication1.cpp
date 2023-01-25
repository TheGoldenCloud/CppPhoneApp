#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <vector>

using namespace std;

//Structure
struct telefon {
    string brend;
    string model;
    int year;
    int price;
};

//Options
int pickOption() {
    int input;
    while (true) {
        cin >> input;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter an integer: ";
        }
        else {
            return input;
            break;
        }
    }
}

//Nastavak programa ???? NEMA NIGDE FUNKCIJE
void nastavakPrograma() {
    int pick;
    cout << "Do you want to continue with shopping: ";
    cin >> pick;
}

//Checking
bool numberCheck(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str[i]) == false) {
            return false;
        }
    }
    return true;
}

//Read from txt
void read() {
    ifstream fajl;
    string linija;

    fajl.open("telefoni.txt");

    if (fajl.is_open()) {

        while (getline(fajl, linija)) {
            cout << linija << "\n";
            cout << "\n";
        }
        fajl.close();
    }
    else {
        cout << "File dosen't exist!";
    }
}

//Writes to txt 
void write(string text) {
    ofstream fajl;
    fajl.open("telefoni.txt", ios::app);

    if (fajl.is_open()) {
        fajl << text;
        cout << "Success!";
        fajl.close();
    }
    else {
        cout << "File dosen't exist!";
    }
}

//Calculates number of telephones in txt
int phoneCount() {
    ifstream fajl;
    string linija;
    int kolicinaLinija = 0;

    fajl.open("telefoni.txt");

    if (fajl.is_open()) {

        while (getline(fajl, linija)) {

            if (linija.empty()) {
                kolicinaLinija = 0;
            }
            else {
                kolicinaLinija += 1;
            }

        }
        fajl.close();
    }
    else {
        cout << "File dosen't exist!";
    }

    return kolicinaLinija;
}

//Delete the phone
void deletePhone(int odabir) {

    ifstream ifajl;

    ifajl.open("telefoni.txt",ios::in);

    vector<string> linije;
    string linija;

    while (getline(ifajl, linija)) {
        linije.push_back(linija);
    }

    ifajl.close();

    ofstream ofajl;

    ofajl.open("telefoni.txt");

    if (ofajl.fail())
    {
        cout << "Error opening file." << endl;
    }

    odabir--;

    for (int i = 0; i < linije.size(); i++) {
        if (i != odabir) {
            ofajl << linije[i] << endl;
        }
    }

    ofajl.close();
}


//Dinamicly adding phone to txt 
void sell() {
    int n;
    string inputtelefoni;

    cout << "Enter amount of telefpohones: ";
    cin >> n;

    telefon* telefoni = nullptr;

    if (telefoni == NULL) {
        telefoni = new telefon[n];

        for (int i = 0; i < n; i++) {
            cout << "Enter brand " << i + 1 << ": ";
            cin >> telefoni[i].brend;

            cout << "Enter model " << i + 1 << ": ";
            cin >> telefoni[i].model;

            cout << "Enter year " << i + 1 << ": ";
            cin >> telefoni[i].year;

            cout << "Enter price " << i + 1 << ": ";
            cin >> telefoni[i].price;
        }

        for (int i = 0; i < n; i++) {
            inputtelefoni += telefoni[i].brend + "," + telefoni[i].model + "," + to_string(telefoni[i].year) + "," + to_string(telefoni[i].price) + "\n";
        }

        write(inputtelefoni);

        delete[] telefoni;
    }
    else {
        cout << "Pointer empty!";
    }
}

//
void selectPhone() {
    ifstream file;
    file.open("telefoni.txt", ios::in);
    int odabir;
    int current_line = 0;
    string line;

    if (file.is_open()) {

        read();

        do {
            cout << "Choose phone with the number: ";
            cin >> odabir;
        } while (odabir >= phoneCount()); {

            while (!file.eof())
            {
                current_line++;

                getline(file, line);

                if (current_line == odabir) {
                    cout << "\n";
                    cout << "You choose: " << line << endl;
                    cout << "\n";
                }
            }
        }
        file.close();

        deletePhone(odabir);
        
        cout << "----- AFTER ----- \n\n";
        read();
        cout << "----- AFTER ----- \n";


    }
}

//Text enter
void entryText() {
    cout << "Hello, welcome to our phone store\n";
    cout << "How can we help you?\n";
    cout << "1 - Kupovinu telefona\n";
    cout << "2 - Selling phone\n";
    cout << "3 - Exit\n";
    cout << "\n";
}


int main()
{
    bool start = true;
    string odabir;

    while (start) {
        entryText();

        switch (pickOption()) {
        case 1:
            cout << "1 - You have chosen to buy a phone\n\n";
            
            selectPhone();

            cout << "Do you want to continue shopping? ";
            cin >> odabir;

            if (odabir == "Yes") {
                selectPhone();
            }
            else if (odabir == "No") {
                cout << "Hello, you have finished shopping";
                start = false;
            }
            break;
        case 2:
            cout << "2 - You have chosen to buy a phone\n";

            sell();

            cout << "Do you want to continue the sale: ";
            cin >> odabir;

            if (odabir == "Yes") {
                sell();
            }
            else if (odabir == "No") {
                cout << "Goodbuy, you have completed the sale";
                start = false;
            }

            break;
        case 3:
            cout << "3 - Goodbuy\n";
            start = false;
            break;

        }
    }

    

    



}

