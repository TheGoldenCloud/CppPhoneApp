#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <vector>

using namespace std;

struct animal { //Kao datatip
    string breed;
    int lifespan;
};

struct person {
    string name;
    string lastname;
    int age;
};

struct telefon {
    string brend;
    string model;
    int year;
    int price;
};

void write(string text) {
    ofstream fajl;
    fajl.open("telefoni.txt",ios::app);

    if (fajl.is_open()) {
        fajl << text;
        cout << "Uspesno upisano u fajl";
        fajl.close();
    }
    else {
        cout << "Fajl ne postoji!";
    }
}

//Use
void read() {
    ifstream fajl;
    string linija;

    fajl.open("blank.txt");

    if (fajl.is_open()) {

        while (getline(fajl, linija)) {
            cout << linija << "\n";
            cout << "\n";
        }
        fajl.close();
    }
    else {
        cout << "Fajl ne postoji!";
    }
}

//Nastavi
//telefon* kreirajTelefone() {
//    int n;
//
//    cout << "Unesite koliko ce biti telefona: ";
//    cin >> n;
//
//    telefon* telefoni = nullptr;
//
//    if (telefoni != NULL) {
//        telefoni = new telefon[n];
//
//        bool start = true;
//        
//    }
//
//}

//bool proveraBorja(string str) {
//    for (int i = 0; i < str.length(); i++) {
//        if (isdigit(str[i]) == false) {
//            return false;
//        }
//    }
//    return true;
//}

int phoneCount() {
    ifstream fajl;
    string linija;
    int kolicinaLinija = 0;

    fajl.open("blank.txt");

    if (fajl.is_open()) {

        //Ovde
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
        cout << "Fajl ne postoji!";
    }

    return kolicinaLinija;
}

//CUVANJE
//void eraseFileLine() {
//
//    string filename;
//    int line_number;
//
//    cout << "File: ";
//    getline(cin, filename);
//
//    cout << "Line: ";
//    cin >> line_number;
//
//    fstream read_file;
//
//    read_file.open(filename);
//
//    if (read_file.fail())
//    {
//        cout << "Error opening file." << endl;
//
//    }
//
//    vector<string> lines;
//    string line;
//
//    while (getline(read_file, line))
//        lines.push_back(line);
// 
//    read_file.close();
//
//    if (line_number > lines.size())
//    {
//        cout << "Line " << line_number;
//        cout << " not in file." << endl;
//
//        cout << "File has " << lines.size();
//        cout << " lines." << endl;
//
//    }
//
//    ofstream write_file;
//
//
//    write_file.open(filename);
//
//
//    if (write_file.fail())
//    {
//        cout << "Error opening file." << endl;
//    }
//
//    line_number--;
//
//
//    for (int i = 0; i < lines.size(); i++)
//        if (i != line_number)
//            write_file << lines[i] << endl;
//
//    write_file.close();
//}

//
void eraseFileLine(int odabir) {  //ovaj modifikuj

    ifstream read_file;

    read_file.open("blank.txt");

    vector<string> lines;
    string line;

    while (getline(read_file, line)) {
        lines.push_back(line);
    }
        
    read_file.close();


    ofstream write_file;


    write_file.open("blank.txt");


    if (write_file.fail())
    {
        cout << "Error opening file." << endl;
    }

    odabir--;


    for (int i = 0; i < lines.size(); i++) {
        if (i != odabir) {
            write_file << lines[i] << endl;
        }
    }
    
    write_file.close();
}

void selectPhone() {
    ifstream file;
    file.open("blank.txt", ios::in);
    int odabir;
    int current_line = 0;
    string line;
    string odabir1;

    if (file.is_open()) {

        //Procitaj - Ispisi
        read();

        do {
            cout << "Izaberite nacin telefoa kucanjem broja: ";
            cin >> odabir;
        } while (odabir >= phoneCount()); {

            //Cita sve linije i ispisuje
            while (!file.eof())
            {
                current_line++;

                getline(file, line);

                if (current_line == odabir) {
                    cout << "\n";
                    cout << "Izabrali ste: " << line << endl;
                    cout << "\n";
                }
            }
        }
        file.close();

        eraseFileLine(odabir);

        cout << "----- POSLE BRIOSANJA ----- \n";
        read();
        cout << "----- POSLE BRIOSANJA ----- \n";

    }
}

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

int main()
{




    //Dynamicly allocate struct
    //int n;

    //cout << "Unesi broj ljudi: ";
    //cin >> n;

    //person* personsi = nullptr;   //Kreiranje praznog pokazivaca

    //if(personsi == NULL){
    //    personsi = new person[n];   //Dodela proizvoljnog prostora pokazivacu

    //    for (int i = 0; i < n; i++){
    //        cout << "Unesi ime osobe " << i+1 << ": ";
    //        cin >> personsi[i].name;

    //        cout << "Unesi prezime osobe " << i + 1 << ": ";
    //        cin >> personsi[i].lastname;

    //        cout << "Unesi godine osobe " << i + 1 << ": ";
    //        cin >> personsi[i].age;
    //    }

    //    for (int i = 0; i < n; i++) {
    //        cout << i + 1 << ". " << "Name: " << personsi[i].name << " last name: " << personsi[i].lastname << " age: " << personsi[i].age << "\n";
    //    }

    //    delete[] personsi;  //Oslobadjanje memorije pokazivaca
    //}
    //else {
    //    cout << "Pointer nije deklarisan kao null na pocetku!";
    //}

    


    /*string str = "sunidhi";
    if (check_number(str))
        cout << str << " is an integer" << endl;
    else
        cout << str << " is a string" << endl;*/

    /*int brr = 1234534;

    string str1 = to_string(brr);

    if (proveraBorja(str1))
        cout << str1 << " is an integerrrrrrrrrrrr";
    else
        cout << str1 << " is a stringggggggggggggg";*/
    


    /*bool start = true;
    int gog = 0;

    while (start)
    {
        if (gog == 10) {
            start = false;
        }
        else
        {
            cout << "Unesi godine osobe : ";
            cin >> gog;
        }
        
    }*/



    /*string ulazniPodatci;

    cout << "Upisite neki text u fajl:";

    getline(cin,ulazniPodatci);

    upisiTextUFajl(ulazniPodatci);

    citanjeTxtDatoteke();*/

    //NASTAVI => ZAVRSI FUNKCIJE IZ TXTA, I DINAMICKI KREIRAJ STRUCT I PROCITAJ GA I UPISI (UVEDI I POKAZIVACE U UPIS ISPIS AKO MOZE!)

    

    //Ne znamo koliko prvo ima telefona u zadatom txt fajlu
    /*int n;
    telefon* telefoni = nullptr;
    telefoni = new telefon[n];*/


    //Staticki
    /*telefon* telefoni = new telefon[3];

    telefon t1;
    t1.brend = "Nokia";
    t1.model = "3310";
    t1.godinaIzlaska = 2000;

    telefon t2;
    t2.brend = "Samsung";
    t2.model = "A50";
    t2.godinaIzlaska = 2010;

    telefon t3;
    t3.brend = "Samsung";
    t3.model = "S20";
    t3.godinaIzlaska = 2020;

    telefoni[0] = t1;
    telefoni[1] = t2;
    telefoni[2] = t3;

    for (int i = 0; i < 3; i++)
    {
        cout << telefoni[i].brend << " " << telefoni[i].model << " " << telefoni[i].godinaIzlaska << "\n";
    }

    delete[] telefoni;*/


    //ZA JEDAN TELEFON
    /*telefon* Telefon = nullptr;

    Telefon = new telefon;

    telefon t;

    cout << "Unesi brend: ";
    cin >> t.brend;

    cout << "Unesi model: ";
    cin >> t.model;

    cout << "Unesi godinu izlaska: ";
    cin >> t.godinaIzlaska;

    cout << "Unesi cenu: ";
    cin >> t.cena;

    delete[] Telefon;

    cout << t.brend << " " << t.model << " " << t.godinaIzlaska << " " << t.cena << "\n";*/


    //ZA VISE TELEFONA
    
    //int n;

    //cout << "Unesi broj telefona za otkup: ";
    //cin >> n;

    //telefon* telefoni = nullptr;
    //

    //if(telefoni == NULL){
    //    telefoni = new telefon[n];   //Dodela proizvoljnog prostora pokazivacu

    //    for (int i = 0; i < n; i++){
    //        cout << "Unesi brend " << i+1 << ": ";
    //        cin >> telefoni[i].brend;

    //        cout << "Unesi model " << i + 1 << ": ";
    //        cin >> telefoni[i].model;

    //        cout << "Unesi godinu izlaska " << i + 1 << ": ";
    //        cin >> telefoni[i].year;

    //        cout << "Unesi cenu " << i + 1 << ": ";
    //        cin >> telefoni[i].price;
    //    }

    //    string inputtelefoni;

    //    //cout << "Uneli ste: ";
    //    for (int i = 0; i < n; i++) {
    //        //cout << i + 1 << ". " << "Brend: " << telefoni[i].brend << " model: " << telefoni[i].model << " godina izlaska: " << telefoni[i].godinaIzlaska << " cena: " << telefoni[i].cena << "\n";
    //        inputtelefoni += telefoni[i].brend + "," + telefoni[i].model + "," + to_string(telefoni[i].year) + "," + to_string(telefoni[i].price) + "\n";
    //    }

    //    //Upisi u datoteku
    //    //for (int i = 0; i < n; i++) {
    //    //    
    //    //    //cout << i + 1 << ". " << "Brend: " << telefoni[i].brend << " model: " << telefoni[i].model << " godina izlaska: " << telefoni[i].godinaIzlaska << " cena: " << telefoni[i].cena << "\n";
    //    //}

    //    upisiTextUFajl(inputtelefoni);

    //    delete[] telefoni;  //Oslobadjanje memorije pokazivaca
    //}
    //else {
    //    cout << "Pointer nije deklarisan kao null na pocetku!";
    //}

}

