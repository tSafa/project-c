#ifndef GROUPE_H_INCLUDED
#define GROUPE_H_INCLUDED
#include <vector>
#include "Groupe_Module.h"
#include "Personne.h"
#include "matiere.h"
#include <iterator>
#include <fstream>
#include <sstream>
#include "note.h"

class groupe{
string IdGrp;
string niveau;
string diplome;
string specialite;
int num_g;
vector <GroupeModule> ListeModules;
vector <etudiant> ListeEtudiants;

public :
groupe();
groupe(string,string,string,string,int,GroupeModule,etudiant);
 void setniveau(string);
 void setdiplome(string);
 void setspecialite(string);
 void setnum_g(int);
 string getidgrp() const;
 string getniveau() const;
 string getdiplome() const;
 string getspecialite() const;
 int getnum() const;
vector<GroupeModule> getlisteM() const;
 vector<etudiant> getlisteE() const;
 void ajuoutemodule(const GroupeModule& );
 void ajoutetudiant(const etudiant& );
 friend ostream& operator<<(ostream& os, const groupe& obj);

etudiant getEtudiantById(int) const;
GroupeModule getgmById(const string& ) const;
 void ajoutGroupe();
 void enregistrerGrp();
void modifgrp();
 void display();
 bool verifidgm(string);
bool verifidet(int);
void suppgrp();
void recherchegrp();
string getidgm(string);
float moyenne(string);
void affichepv();
vector<int> getidetfromgroup(string);
vector<string> getidgmfromgrp(string);
void mention(float);
void resultat(float);
};

vector<string> groupe::getidgmfromgrp(string IdGrp) {
    ifstream groupeFile("fichierGroupe.txt");
    string line;
    vector<string> gmIds;  // Use a vector to store all group module IDs

    // Vérifier si l'ID du groupe existe déjà
    while (getline(groupeFile, line)) {
        if (line.find("L'id du groupe : " + IdGrp) != string::npos) {
            size_t idgmPos = line.find("L'id de Groupe Module : ");
            while (idgmPos != string::npos) {
                // Adjust the substring extraction based on your file structure
                string gmId = line.substr(idgmPos + 24);
                size_t endPos = gmId.find(" ");
                gmId = gmId.substr(0, endPos);
                gmIds.push_back(gmId);

                // Find the next occurrence of group module ID
                idgmPos = line.find("L'id de Groupe Module : ", idgmPos + 1);
            }
            break;  // Stop processing the line once all IDs are retrieved
        }
    }

    groupeFile.close();

    if (gmIds.empty()) {
        cout << "Aucun ID de Groupe Module trouvé pour le groupe spécifié.\n";
    }

    return gmIds;
}



void groupe::affichepv() {
    int i=0;
    string idgrp;
    int idet;
    string nomgm;
    float coefgm;
    vector<int> idets;
    string nommat;
matiere mat;
note n;
float moyenneMatiere;
float moyenneGroupeModule;
float moyenneGenerale;
    cout << "\nVeuillez Entrer l'ID de votre groupe\n";
    cin >> idgrp;

    ifstream groupeFile("fichierGroupe.txt");
    string line;
    bool idEx = false;

    // Vérifier si l'ID du groupe existe déjà
    while (getline(groupeFile, line)) {
        if (line.find(idgrp) != string::npos) {
            idEx = true;


        }
    }

    groupeFile.close();

    if (idEx) {
  vector<int> idetudiants = getidetfromgroup(idgrp);
cout<<"\nLes ids des etudiants appartenant a ce groupe\n";
// Affichez les IDs d'étudiants
for (const int& idet : idetudiants) {
    cout << idet << " ";
}
note n;
cout<<"\nEntrer votre ID :\n";
int idet;
cin>>idet;
vector <string> idsgm =getidgmfromgrp(idgrp);
GroupeModule gm;
for (const string& idgm : idsgm) {
    //le nom et ne coeffecient des gm
    nomgm=gm.getnomgmbyidgm(idgm);
    coefgm=gm.getcoefgmbyid(idgm);
    moyenneGroupeModule=gm.moygm(idgm);
    cout <<"\n\n-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";

        cout<<"\nl'id du Groupe Module : "<<idgm<<"        |Le nom groupe module : "<<nomgm<<"        | Le coeffecient du groupe module : "<<coefgm<<"        | La moyenne de ce groupe Module : "<<moyenneGroupeModule<<"\n" ;
cout <<"-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";

    // les nom des matiéres :
    vector <string> idsmatiere=gm.getidmatbyidgm(idgm);
cout<<"\n   Les matiéres appartenant au groupe module "<<nomgm<< " : \n";
for (const string& idmat : idsmatiere) {
    nommat=mat.getnommatbyidmat(idmat);
    moyenneMatiere=n.MoyMat(idmat);


cout<<"\nle nom de la  matiére  : "<<nommat<<"        |La moyenne de cette matiere : "<<moyenneMatiere<<"\n";

}
}
moyenneGenerale=moyenne(idgrp);
cout<<"\n\n\n*********************************************************************************La moyenne Generale est : "<<moyenneGenerale<<"*******************************************************************";
resultat(moyenneGenerale);
mention(moyenneGenerale);

    } else {
        cout << "L'ID du groupe n'existe pas.\n";
    }
}












void groupe :: resultat(float moyenne){
if(moyenne>10){
    cout<<"\n\n**********************************Admis**********************************\n\n";
}else{
cout<<"\n\n--------------------------------------Ajourné--------------------------------------\n\n";
}

}

void groupe ::mention(float moyenne){

 if (moyenne>= 10 && moyenne < 12) {
      cout << "\nPassable\n" << endl;
    } else if (moyenne >= 12 && moyenne < 14) {
       cout << "\nAssez Bien\n" << endl;
    } else if (moyenne >= 14 && moyenne < 16) {
       cout << "\nBien\n" << endl;
    } else if (moyenne >= 16 && moyenne < 18) {
       cout << "\nTrès Bien\n" <<endl;
    } else if (moyenne >= 18 && moyenne <= 20) {
       cout << "\nExcellent\n" << endl;
    }



}























vector<int> groupe::getidetfromgroup(string idgrp) {
    ifstream inFile("fichierGroupe.txt");
    string line;
    vector<int> idets;

    while (getline(inFile, line)) {
        if (line.find("L'id du groupe : " + idgrp) != string::npos) {
            size_t idetPos = line.find("     L'id de L'etudiant: ");
            while (idetPos != string::npos) {
                int idetval = stoi(line.substr(idetPos + 25));
                idets.push_back(idetval);
                idetPos = line.find("     L'id de L'etudiant: ", idetPos + 1);
            }
            break;
        }
    }

    inFile.close();

    return idets;
}





















float groupe::moyenne(string IdGrp) {
    GroupeModule gm;
    float produit = 0;
    float somme = 0;
    float sommeCoef = 0;

    ifstream groupeFile("fichierGroupe.txt");

    string line;
    bool idEx = false;

    while (getline(groupeFile, line)) {
        if (line.find(IdGrp) != string::npos) {
            int idet1;

                    string idgm = getidgm(IdGrp);
                    if (!idgm.empty()) {
                        float coefgm = gm.getcoefgmbyid(idgm);
                        float moygm = gm.moygm(idgm);

                        produit = moygm * coefgm;
                        somme += produit;
                        sommeCoef += coefgm;

                    } else {
                        cout << "\nGroup Module ID not found.\n";
                    }

            idEx = true;

        }
    }

    groupeFile.close();

    if (!idEx) {
        cout << "\nGroup ID does not exist.\n";
    }

    if (sommeCoef != 0) {
        return somme / sommeCoef;
    } else {
        cout << "\nError: Division by zero.\n";
        return 0;
    }
}












string groupe::getidgm(string IdGrp) {
    ifstream groupeFile("fichierGroupe.txt");
    string line;
    bool idEx = false;
    string gmid; // Move the declaration outside the if block

    // Vérifier si l'ID du groupe existe déjà
    while (getline(groupeFile, line)) {
        if (line.find(IdGrp) != string::npos) {
            // Extract the note value from the line
            size_t idgmPos = line.find("L'id de Groupe Module : ");
            if (idgmPos != string::npos) {
                // Adjust the substring extraction based on your file structure
                gmid = line.substr(idgmPos + 24);
                // Find the end of the id
                size_t endPos = gmid.find(" ");
                // Extract only the id part
                gmid = gmid.substr(0, endPos);
            }
            idEx = true;
            break;
        }
    }

    groupeFile.close();

    if (!idEx) {
        cout << "L'ID du groupe Non Existant\n";
    }

    return gmid; // Now it's accessible here
}
























void groupe::recherchegrp() {
    cout << "\n Entrer l'id du groupe dont vous voulez afficher les données :\n";
    cin >> IdGrp;

    ifstream inFile("fichierGroupe.txt");
    string line;
    bool idExists = false;

    while (getline(inFile, line)) {
        if (line.find("L'id du groupe : " + IdGrp) != string::npos) {
            cout << "\nLes données du groupe  :\n";
            cout << line << endl;
            idExists = true;
            break;
        }
    }

    inFile.close();

    if (!idExists) {
        cout << "-------------L'ID non existant ------------.\n";
    }
}











void groupe ::suppgrp(){

string IdGrp;
    cout << "\nEntrer l'id de groupe a supprimer:\n";
    cin >> IdGrp;

    ifstream inFile("fichierGroupe.txt");
    string line;
    vector<string> fileContents;
    bool idExists = false;

    while (getline(inFile, line)) {
        if (line.find("L'id du groupe : " + IdGrp) != string::npos) {
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
        ofstream outFile("fichierGroupe.txt", ios::trunc);

        if (outFile.is_open()) {
            for (const string& content : fileContents) {
                outFile << content << "\n";
            }

            outFile.close();
            cout << "\n La suppression est terminée avec succés.\n";
        } else {
            cout << "\nError opening the output file.\n";
        }
    }

}






void groupe::modifgrp() {
    string id;
    cout << "\nEntrer l'id du groupe à modifier:\n";
    cin >> id;

    ifstream inFile("fichierGroupe.txt");
    string line;
    vector<string> fileContents;
    bool idExists = false;
    string add;
    string addanother;

    while (getline(inFile, line)) {
        if (line.find("L'id du groupe : " + id + " ") != string::npos) {
            idExists = true;
            cout << "Entrer les nouvelles informations du groupe\n";
            cout << "\nEntrer le niveau modifié:\n";
            cin >> niveau;
            cout << "\nEntrer la spécialité modifiée:\n";
            cin.ignore();  // Ignore any leftover newline characters
            getline(cin, specialite);
            cout << "\nEntrer le diplôme modifié:\n";
            cin >> diplome;
            cout << "\nEntrer le numéro du groupe modifié:\n";
            cin >> num_g;

            // Clear the lists before adding new data
            ListeModules.clear();
            ListeEtudiants.clear();

            do {
                int etudiantId;
                cout << "\nEntrer l'id de l'étudiant :\n";
                cin >> etudiantId;

                bool etudiantExists = verifidet(etudiantId);
                if (!etudiantExists) {
                    cout << "\nID étudiant non existant. Veuillez entrer un ID Existant.\n";
                } else {
                    // Add the existing student to the group
                    etudiant etudiantExist = getEtudiantById(etudiantId);
                    ajoutetudiant(etudiantExist);
                }

                cout << "\nVoulez-vous ajouter un autre étudiant ? (y/n): ";
                cin >> add;
            } while (add == "y" || add == "Y");

            do {
                string groupeModuleId;
                cout << "\nEntrer l'id du groupe module :\n";
                cin >> groupeModuleId;

                bool groupeModuleExists = verifidgm(groupeModuleId);
                if (!groupeModuleExists) {
                    cout << "\nID groupe module non existant. Veuillez entrer un ID Existant.\n";
                } else {
                    // Add the existing group module to the group
                    GroupeModule gmExist = getgmById(groupeModuleId);
                    ajuoutemodule(gmExist);
                }

                cout << "\nVoulez-vous ajouter un autre Groupe Module ? (y/n): ";
                cin >> addanother;
            } while (addanother == "y" || addanother == "Y");

            // Modify the line with new information
            line = "L'id du groupe : " + id + "     le niveau du groupe : " + niveau + "     La specialite : " + specialite +
                   "     Le diplome : " + diplome + "     Le numero du groupe : " + to_string(num_g);

            // Add the modified module IDs to the line
            for (const GroupeModule& gm : ListeModules) {
                line += "     L'id de Groupe Module : " + gm.getidgm();
            }

            // Add the modified student IDs to the line
            for (const etudiant& et : ListeEtudiants) {
                line += "     L'id de L'etudiant: " + to_string(et.getid());
            }
        }
        fileContents.push_back(line);
    }

    inFile.close();

    if (!idExists) {
        cout << "\nID Non existant\n";
    } else {
        ofstream outFile("fichierGroupe.txt", ios::trunc);

        if (outFile.is_open()) {
            for (const string& content : fileContents) {
                outFile << content << "\n";
            }

            cout << "\nLes informations ont été modifiées avec succès.\n";
        } else {
            cout << "\nError opening the output file.\n";
        }

        outFile.close();
    }
}







bool groupe ::verifidgm(string IdGM){
ifstream inFile("Fichier_GroupeModule.txt");
    string line;
    bool idEx = false;

    // Vérifier si l'ID du matiere existe déjà
    while (getline(inFile, line)) {
        if (line.find("L'id du groupe Module : " + IdGM) != string::npos) {
            idEx = true;
            break;
        }
    }

    inFile.close();
    if(idEx){
return true;
    } if(!idEx){
return false;
    }
}






bool groupe ::verifidet(int id){
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
            return true;
    }if(!idExists){
    return false;
    }



}

groupe :: groupe(){
IdGrp ="id1";
niveau ="niveau";
diplome ="diplome";
specialite="specialite";
num_g=1;
}
groupe :: groupe(string ch1,string ch2,string ch3,string ch4,int a,GroupeModule gm,etudiant etu){
    IdGrp =ch1;
    niveau =ch2;
    diplome =ch3;
    specialite=ch4;
    num_g=a;
    ListeModules.push_back(gm);
    ListeEtudiants.push_back(etu);


}


string groupe ::getidgrp() const{
return IdGrp;
}


string groupe ::getniveau() const{
return niveau;
}

string groupe ::getdiplome() const{
return diplome;
}

string groupe::getspecialite() const{
return specialite;
}

int groupe ::getnum() const{
return num_g;
}

vector<GroupeModule> groupe::getlisteM() const {
    return ListeModules;
}

vector<etudiant> groupe::getlisteE() const {
    return ListeEtudiants;
}

ostream& operator<<(ostream& os, const groupe& obj) {
    os << "\nL'id du groupe : \n" << obj.getidgrp() << "  "
       << "\nLe niveau: \n" << obj.getniveau() << "   "
       << "\n Le diplome : \n" << obj.getdiplome() << "\nLa specialite :\n" << obj.getspecialite()
       << "\nle numero du groupe\n" << obj.getnum() << "\nLa liste des modules \n";

    // Output modules
    for (const GroupeModule& mod : obj.getlisteM()) {
        os << mod; // Assuming GroupeModule has an operator<< defined
    }

    os << "\nLa liste des etudiants\n";

    // Output students
    for (const etudiant& etu : obj.getlisteE()) {
        os << etu; // Assuming etudiant has an operator<< defined
    }

    return os;
}





void groupe :: setniveau(string niveau1){
niveau=niveau1;

}

void groupe :: setdiplome(string diplome1){
diplome=diplome1;

}

void groupe ::setnum_g(int a){
num_g=a;

}

void groupe ::setspecialite(string specialite1){
specialite=specialite1;

}

void groupe::display(){
cout<<"\nl'id du groupe : \n"<<IdGrp<<"  "<<"\n le niveau : \n"<<niveau<<"  "<<"\nle diplome : \n"<<diplome<<"  "<<"\n groupe : \n"<<num_g<<"  "<<"\nla specialite : \n"<<specialite<<"   " <<"\n le numero du groupe : \n"<<num_g<<endl;
cout<<"\nLa liste des modules : \n"<<endl;
for(GroupeModule &mod : ListeModules){
    mod.display();

}
cout<<"\nLa liste des etudiants : \n"<<endl;
for (etudiant &etu : ListeEtudiants){
    etu.display();

}

}
void groupe :: ajuoutemodule(const GroupeModule& mod){
ListeModules.push_back(mod);

}
void groupe :: ajoutetudiant(const etudiant& etu){
        ListeEtudiants.push_back(etu);

}
fstream fichierGroupe;

void groupe::ajoutGroupe() {
    cout << " \nEntrer l'id du groupe : \n";
    cin >> IdGrp;

    ifstream groupeFile("fichierGroupe.txt");

    string line;
    bool idEx = false;

    // Vérifier si l'ID du groupe existe déjà
    while (getline(groupeFile, line)) {
        if (line.find(IdGrp) != string::npos) {
            idEx = true;
            break;
        }
    }

    groupeFile.close();

    if (idEx) {
        cout << "L'ID du groupe entré existe déjà. Veuillez entrer un ID différent.\n";

    } else {
        cout <<"\n Entrer le niveau :\n";
        cin >> niveau;
        cout <<"\nEntrer la specialite :\n";
        cin >> specialite;
        cout <<"\n Entrer le diplome :\n";
        cin >> diplome;
        cout <<"\n Entrer le numero du groupe :\n";
        cin >> num_g;
        char addAnother;
do{
        int id;
        cout<<"\nEntrer l'id de l'etudiant a ajouter dans le groupe :\n";
        cin>>id;

        ifstream etudiantFile("Fichier_etudiant.txt");
        bool idExists = false;

        while (getline(etudiantFile, line)) {
            if (line.find("Id etudiant : " + to_string(id)) != string::npos) {
                idExists = true;
                break;
            }
        }

        etudiantFile.close();

       if(idExists == false) {
            cout << "L'ID entré existe déjà. Veuillez entrer un ID différent.\n";


        }if(idExists == true){

            etudiant etudiantExist;
        etudiantExist = getEtudiantById(id); // Utiliser la fonction pré-définie
        ajoutetudiant(etudiantExist);



        cout<<"\nEtudiant ajoute au groupe avec succès\n";
          cout << "\nVoulez-vous ajouter un autre etudiant ? (y/n): ";

            cin >> addAnother;


        }}while (addAnother == 'y' || addAnother == 'Y');


        do {
          string IdGM;
        cout<<"\nVeuillez entrer l'id de groupe module a ajouter :\n";
      cin>>IdGM;
      ifstream gmFile("Fichier_GroupeModule.txt");
        bool idExist = false;
string line;
        while (getline(gmFile, line)) {
            if (line.find("L'id du groupe Module : " + (IdGM)) != string::npos) {
                idExist = true;
                break;
            }
        }

        gmFile.close();
if(idExist==false){
             cout<<"\nID non existant.Veuillez entrer l'id de groupe module a nouveau";

        }
        if(idExist==true){
         GroupeModule gmExist;
         gmExist=getgmById(IdGM);
         ajuoutemodule(gmExist);

            cout<<"\nGroupe Module ajouté au groupe avec succés\n";

        cout << "\nVoulez-vous ajouter un autre Groupe Module ? (y/n): ";
            cin >> addAnother;
        }
        }while (addAnother == 'y' || addAnother == 'Y');
 enregistrerGrp();
            cout<<"\n***************************Groupe Enregsitré***********************\n";


        }
    }


etudiant groupe::getEtudiantById(int id) const {
    etudiant result;  // Objet étudiant pour stocker les données
    ifstream etudiantFile("Fichier_etudiant.txt");
    string line;

    while (getline(etudiantFile, line)) {
        if (line.find("Id etudiant : " + to_string(id)) != string::npos) {
            // Utilisez une stringstream pour extraire les données de la ligne
            istringstream iss(line);

            // Ignorer "Id etudiant : "
            string idStr;
            iss >> idStr;
            // Lisez le reste de la ligne comme données
            string restOfLine;
            getline(iss, restOfLine);

            // Initialisez l'objet étudiant avec les données lues
            result = etudiant(id, restOfLine, "", "", 0);
            break;
        }
    }

    etudiantFile.close();
    return result;
}







GroupeModule groupe::getgmById(const string& IdGM) const {
    GroupeModule result;  // Objet GroupeModule pour stocker les données
    ifstream gmFile("Fichier_GroupeModule.txt");
    string line;

    while (getline(gmFile, line)) {
        if (line.find("L'id du groupe Module : " + IdGM) != string::npos) {
            // Utilisez une stringstream pour extraire les données de la ligne
            istringstream iss(line);

            // Ignorer "L'id du groupe Module : "
            string idStr;
            iss >> idStr;
            // Lisez le reste de la ligne comme données
            string restOfLine;
            getline(iss, restOfLine);

            // Initialisez l'objet GroupeModule avec les données lues
            result = GroupeModule(IdGM, restOfLine, 0, matiere());  // Assurez-vous d'avoir un constructeur adapté
            break;
        }
    }

    gmFile.close();
    return result;
}













/*
void groupe::enregistrerGrp() {
    ofstream outFile("fichierGroupe.txt", ios::app);

    GroupeModule gm =ListeModules.back();
    etudiant et =ListeEtudiants.back();
    if (outFile.is_open()) {
            if (!ListeModules.empty() && !ListeEtudiants.empty()) {
        outFile << "\nL'id du groupe : " << IdGrp << "     le niveau du groupe : " << niveau
                << "     La specialite : " << specialite << "     Le diplome : " << diplome
                << "     Le numero du groupe : " << num_g <<"     L'id de Groupe Module : "<<gm.getidgm()<<"     L'id de L'etudiant: "<<et.GetId()<< endl;


        outFile.close();
            }
    } else {
        cout << "Erreur lors de l'ouverture du fichier de sortie.\n";
    }
}*/
void groupe::enregistrerGrp() {
    ofstream outFile("fichierGroupe.txt", ios::app);

    if (outFile.is_open()) {
        if (!ListeModules.empty() && !ListeEtudiants.empty()) {


            outFile << "\nL'id du groupe : " << IdGrp << "     le niveau du groupe : " << niveau
                    << "     La specialite : " << specialite << "     Le diplome : " << diplome
                    << "     Le numero du groupe : " << num_g ;
                    for (const etudiant& et : ListeEtudiants) {
            outFile << "     L'id de L'etudiant: " << et.getid();
        }
                  for (const GroupeModule& gm : ListeModules) {
            outFile << "     L'id de Groupe Module : " << gm.getidgm();
        }

        }

        outFile.close();
    } else {
        cout << "Erreur lors de l'ouverture du fichier de sortie.\n";
    }
}


// ...

#endif // GROUPE_H_INCLUDED
