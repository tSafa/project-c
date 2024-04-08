#ifndef PERSONNE_H_INCLUDED
#define PERSONNE_H_INCLUDED
#include <fstream>
#include <vector>
#include <sstream>
class personne{
protected :
int id;
string nom;
string prenom;
string mail;


};
class etudiant : public personne{
int Num_insc;
public :

    etudiant();
    etudiant(int ,string , string,string,int);
     int getid() const;
    string getnom() const;
    string getprenom() const;
    string getmail() const;
    int getnum() const;
int  GetId();
void enregistrementFichier();
    void setId(int);
    void setnom(string);
    void setprenom(string);
    void setmail(string);
    void setnum(int);

       friend ostream& operator<<(ostream& os, const etudiant& obj);
       void ajout_etudiant();
       void ajout_tablet(const etudiant&);
       void display();
void suppression();
       string getName();
       string getFname();
       string getEmail();
       int getnumber();
       void recherchEtu();
void modifEtu();
void getidet();
    };


    void etudiant::getidet() {
    ifstream inFile("Fichier_etudiant.txt");
    string line;
    vector<int> ids;  // Stocke les IDs des étudiants existants

    while (getline(inFile, line)) {
        size_t found = line.find("Id etudiant : ");
        if (found != string::npos) {
            // Extraire l'ID de la ligne
            int id;
            istringstream(line.substr(found + 14)) >> id;
            ids.push_back(id);
        }
    }

    inFile.close();

    // Afficher les IDs des étudiants existants

    for (int id : ids) {
        cout <<"\n"<< id << "\n ";
    }
    cout << endl;

    // Retourner le premier ID trouvé (vous pouvez modifier cela selon vos besoins)

}





    void etudiant ::recherchEtu(){


        int id;
    cout << "\n Entrer l'id de l'etudiant :\n";
    cin >> id;

    ifstream inFile("Fichier_etudiant.txt");
    string line;
    vector<string> fileContents;  // Stocke les lignes du fichier

    while (getline(inFile, line)) {
        if (line.find("Id etudiant : " + to_string(id)) != string::npos) {
            cout << "\nDonnées de l'etudiant :\n";
            cout << line << endl;  // Affiche la ligne correspondant à l'ID
            break;
        }
    }

    inFile.close();

    // Affiche un message si l'ID n'existe pas
    if (line.find("Id etudiant : " + to_string(id)) == string::npos) {
        cout << "-------------L'ID non existant ------------.\n";
    }

    }


    void etudiant ::suppression(){
         vector<string> fileContents;
         int id;
   cout<<"\n Entrer l'id de l'etudiant a supprimé:\n";
cin >>id;
 ifstream inFile("Fichier_etudiant.txt");
    string line;
    bool idExists = false;
while (getline(inFile, line)) {
        if (line.find("Id etudiant : " + to_string(id)) != string::npos) {
            idExists = true;
             line ="  ";
            break;
        }
         fileContents.push_back(line);
    }

    inFile.close();

    if (!idExists){
                    cout << "-------------L'ID non existant ------------.\n";
    }
    else {
        ofstream outFile("Fichier_etudiant.txt", ios::trunc);

        if (outFile.is_open()) {
            for (const string& content : fileContents) {
                outFile << content << "\n";
            }

            outFile.close();
            cout << "\nLes information de l'etudiant supprimé avec succés.\n";
        } else {
            cout << "\nError opening the output file.\n";
        }
    }





    }





void etudiant::modifEtu() {
    int id;
    cout << "\nEntrer l'id de l'etudiant a modifier:\n";
    cin >> id;

    ifstream inFile("Fichier_etudiant.txt");
    string line;
    vector<string> fileContents;
    bool idExists = false;

    while (getline(inFile, line)) {
        if (line.find("Id etudiant : " + to_string(id)) != string::npos) {
            idExists = true;
            cout << "Entrer les nouvelles informations de l'etudiant\n";
            cout << "\nEntrer le nom  modifié:\n";
            cin >> nom;
            cout << "\nEntrer le prenom  modifié:\n";
            cin >> prenom;
            cout << "\nEntrer le mail  modifié:\n";
            cin >> mail;
            cout << "\nEntrer le num d'inscription  modifié:\n";
            cin >> Num_insc;

            line = "Id etudiant : " + to_string(id) + "     Nom de l'etudiant : " + nom + "     Prenom de l'etudiant : " + prenom +
                   "     Adresse mail : " + mail + "     Numero d'inscrit : " + to_string(Num_insc);
        }
        fileContents.push_back(line);
    }

    inFile.close();

    if (!idExists) {
        cout << "\nID Non existant\n";
    } else {
        ofstream outFile("Fichier_etudiant.txt", ios::trunc);

        if (outFile.is_open()) {
            for (const string& content : fileContents) {
                outFile << content << "\n";
            }

            outFile.close();
            cout << "\nLes information de l'etudiant modifié avec succés.\n";
        } else {
            cout << "\nError opening the output file.\n";
        }
    }
}

string etudiant :: getName(){
return nom;
}
string etudiant :: getFname(){
return prenom;
}
string etudiant ::getEmail(){
return mail;
}
int etudiant ::getnumber(){
return Num_insc;
}
int etudiant :: GetId(){
return id;
}
etudiant :: etudiant(){
id=0;
nom="nom1";
prenom="prenom1";
mail="personne@gmail.com";
Num_insc=1;
}
etudiant :: etudiant(int a,string ch ,string ch1,string ch2,int b){

id=a;
nom=ch;
prenom=ch1;
mail=ch2;
Num_insc=b;

}

 int etudiant ::getid()const{
    return id;

    }
    string etudiant :: getnom()const{
    return nom;

    }
    string etudiant ::getprenom ()const{
    return prenom;
    }
    string etudiant ::getmail()const{
    return mail;
    }

    int etudiant :: getnum()const{
    return Num_insc;
    }
ostream& operator<<(ostream& os, const etudiant& obj) {
    os << "Id etudiant: \n" << obj.getid() << "\nNom de l'etudiant : \n" << obj.getnom() << "\n le prenom de l enseignant : \n" << obj.getprenom()<<"\nl'adresse  mail :\n"<<obj.getmail()<<"\nle numero d'insrit : \n"<<obj.getnum();
    return os;
}


void etudiant ::setId(int a){
id=a;
}
void etudiant ::setmail(string gmail){
mail=gmail;
}
void etudiant ::setnom(string enom){
nom=enom;
}
void etudiant ::setprenom(string eprenom){
prenom=eprenom;
}
void etudiant ::setnum(int a){
Num_insc=a;
}

int a;
fstream Fichier_etudiant ;

void etudiant ::ajout_etudiant(){
cout<<"\n Entrer l'id de l'etudiant :\n";
cin >>id;
 ifstream inFile("Fichier_etudiant.txt");
    string line;
    bool idExists = false;
while (getline(inFile, line)) {
        if (line.find("Id etudiant : " + to_string(id)) != string::npos) {
            idExists = true;
            break;
        }
    }

    inFile.close();

    if (idExists){
                    cout << "L'ID entré existe déjà. Veuillez entrer un ID différent.\n";
    }else{
cout <<"\n Entrer le nom de l'etudiant\n";
cin>>nom;
cout <<"\n Entrer le prenom de l'etudiant\n";
cin>>prenom;
cout <<"\nEntrer l'adresse mail\n";
cin >>mail;
cout <<"\nEntrer le numero de l'etudiant\n";
cin>>Num_insc;

    enregistrementFichier();
}}
void etudiant::enregistrementFichier() {
    ofstream outFile("Fichier_etudiant.txt", ios::app);
    if (outFile.is_open()) {
        outFile << "\nId etudiant : " << id << "     Nom de l'etudiant : " << nom << "     Prenom de l'etudiant : " << prenom
                << "     Adresse mail : " << mail << "     Numero d'inscrit : " << Num_insc << "\n\n";


        outFile.close();
        cout << "L'etudiant a été ajouté au fichier avec succès.\n";
    } else {
        cout << "Erreur lors de l'ouverture du fichier de sortie.\n";
    }
}




void etudiant :: display(){

cout <<"l'id de l'etudiant : \n" <<id<<"  "<<"\n le nom de l'etudiant : \n"<<nom<<"  "<<"\n le prenom de l'etudiant : \n"<<prenom<<"  "<<"\n le mail : \n"<<mail<<"  "<<"\n le num d'inscrit : \n"<<Num_insc<<endl;

}
class enseignant :public personne {
int cnss;
public :
    enseignant();
    enseignant(int ,string , string,string,int);
    int getid() const;
    string getnom() const;
    string getprenom() const;
    string getmail() const;
    int getcnss() const;
    int getCnss();
           friend ostream& operator<<(ostream& os, const enseignant& obj);
void ajoutEnseignant();
void setid(int);
void enregistrement_Fichier();
        void display();
void modifens();
void supp();
void recherchens();
};

void enseignant::recherchens() {
    int id;
    cout << "\n Entrer l'id de l'enseignant :\n";
    cin >> id;

    ifstream inFile("Fichier_enseignant.txt");
    string line;
    vector<string> fileContents;  // Stocke les lignes du fichier

    while (getline(inFile, line)) {
        if (line.find("Id enseignant: " + to_string(id)) != string::npos) {
            cout << "\nDonnées de l'enseignant :\n";
            cout << line << endl;  // Affiche la ligne correspondant à l'ID
            break;
        }
    }

    inFile.close();

    // Affiche un message si l'ID n'existe pas
    if (line.find("Id enseignant: " + to_string(id)) == string::npos) {
        cout << "-------------L'ID non existant ------------.\n";
    }
}





void enseignant ::supp(){

 vector<string> fileContents;
         int id;
   cout<<"\n Entrer l'id de l'enseignant a supprimé:\n";
cin >>id;
 ifstream inFile("Fichier_enseignant.txt");
    string line;
    bool idExists = false;
while (getline(inFile, line)) {
        if (line.find("Id enseignant: " + to_string(id)) != string::npos) {
            idExists = true;
             line ="  ";
            break;
        }
         fileContents.push_back(line);
    }

    inFile.close();

    if (!idExists){
                    cout << "-------------L'ID non existant ------------.\n";
    }
    else {
        ofstream outFile("Fichier_enseignant.txt", ios::trunc);

        if (outFile.is_open()) {
            for (const string& content : fileContents) {
                outFile << content << "\n";
            }

            outFile.close();
            cout << "\nLes information de l'enseignant supprimé avec succés.\n";
        } else {
            cout << "\nError opening the output file.\n";
        }
    }





    }






void enseignant::modifens() {
    int id;
    cout << "\nEntrer l'id de l'enseignant a modifier:\n";
    cin >> id;

    ifstream inFile("Fichier_enseignant.txt");
    string line;
    vector<string> fileContents;
    bool idExists = false;

    while (getline(inFile, line)) {
        if (line.find("Id enseignant: " + to_string(id)) != string::npos) {
            idExists = true;
            cout << "Entrer les nouvelles informations de l'enseignant\n";
            cout << "\nEntrer le nom  modifié:\n";
            cin >> nom;
            cout << "\nEntrer le prenom  modifié:\n";
            cin >> prenom;
            cout << "\nEntrer le mail  modifié:\n";
            cin >> mail;
            cout << "\nEntrer le CNSS  modifié:\n";
            cin >> cnss;

            line = "Id enseignant: " + to_string(id) + "     Nom de l'enseignant : " + nom + "     Prenom de l'enseignant : " + prenom +
                   "     Adresse mail : " + mail + "     Le CNSS : " + to_string(cnss);
        }
        fileContents.push_back(line);
    }

    inFile.close();

    if (!idExists) {
        cout << "\nID Non existant\n";
    } else {
        ofstream outFile("Fichier_enseignant.txt", ios::trunc);

        if (outFile.is_open()) {
            for (const string& content : fileContents) {
                outFile << content << "\n";
            }

            outFile.close();
            cout << "\nLes information de l'enseignant modifié avec succés.\n";
        } else {
            cout << "\nError opening the output file.\n";
        }
    }
}



void enseignant::setid(int a){
id=a;
}


enseignant :: enseignant(){
id=0;
nom="nom Enseignant";
prenom ="prenom enseigant";
mail="enseigant@gmail.com";
cnss=1111;


}
enseignant :: enseignant(int a,string ch1,string ch2,string ch3,int b){
id=a;
nom=ch1;
prenom=ch2;
mail=ch3;
cnss=b;


}


int enseignant :: getid() const{
return id;

}
string enseignant :: getnom() const{
return nom;

}
string enseignant :: getprenom() const{
return prenom;

}
string enseignant :: getmail()const{
return mail;

}
int enseignant :: getcnss() const{
return cnss;

}

int enseignant :: getCnss(){

return cnss;
}
ostream& operator<<(ostream& os, const enseignant& obj) {
    os << "Id enseignant: \n" << obj.getid() << "\nNom de l'enseignant : \n" << obj.getnom() << "\n Prenom de l enseigant : \n" << obj.getprenom()<<"\nl'adresse  mail :\n"<<obj.getmail()<<"\nle CNSS : \n"<<obj.getcnss();
    return os;
}




void enseignant::ajoutEnseignant() {
    cout << "\n Entrer l'id de l'enseignant :\n";
    cin >> id;

    // Check if the ID already exists in the file
    ifstream inFile("Fichier_enseignant.txt");
    string line;
    bool idExists = false;

    while (getline(inFile, line)) {
        if (line.find("Id enseignant: " + to_string(id)) != string::npos) {
            idExists = true;
            break;
        }
    }

    inFile.close();

    if (idExists) {
        cout << "L'ID entré existe déjà. Veuillez entrer un ID différent.\n";
    } else {
        // If ID doesn't exist, proceed with other inputs
        cout << "\n Entrer le nom de l'enseignant :\n";
        cin >> nom;
        cout << "\n Entrer le prenom de l'enseignant :\n";
        cin >> prenom;
        cout << "\n Entrer le mail de l'enseignant :\n";
        cin >> mail;
        cout << "\n Entrer le CNSS :\n";
        cin >> cnss;

        // Save the record to the file
        enregistrement_Fichier();
    }
}


void enseignant :: display(){
cout <<"\n l'id de l'enseignant : \n"<<id<<"   "<<"\n Le nom de l'enseignant : \n"<<nom<<"  "<<"\n Le prenon de l enseignant : \n"<<prenom<<"  "<<"\n le mail : \n"<<mail<<"  "<<"\n le CNSS : \n"<<cnss <<endl;
}

void enseignant::enregistrement_Fichier() {
    ofstream outFile("Fichier_enseignant.txt", ios::app);
    if (outFile.is_open()) {
        outFile << "Id enseignant: " << id << "     Nom de l'enseignant : " << nom << "     Prenom de l'enseignant : " << prenom
                << "     Adresse mail : " << mail << "     Le CNSS : " << cnss << "\n\n";


        outFile.close();
        cout << "L'enseignant a été ajouté au fichier avec succès.\n";
    } else {
        cout << "Erreur lors de l'ouverture du fichier de sortie.\n";
    }
}




#endif // PERSONNE_H_INCLUDED
