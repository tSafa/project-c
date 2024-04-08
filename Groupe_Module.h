#ifndef GROUPE_MODULE_H_INCLUDED
#define GROUPE_MODULE_H_INCLUDED
#include <vector>
#include "matiere.h"
#include "Personne.h"
#include <iterator>
#include <fstream>
#include <sstream>
#include "note.h"
#include <cstring>
#include <regex>
class GroupeModule{
string IdGM ;
string NomGM ;
float CoefGM ;
vector <matiere> ListeMat ;
public :

    GroupeModule();
    GroupeModule(string,string,float,matiere);
    string getidgm() const;
    string getmongm() const;
    float  getcoefgm() const;
    vector<matiere> getliste() const;
matiere retour(int);
     friend ostream& operator<<(ostream& os, const GroupeModule& obj);
matiere getmatiereById(const string&) const;
     void ajoutGM();
     void enregistrerGM();

void setidgm(string);
void setnomgm(string);
void setcoefgm(float);
void modifgm();
 void ajoutmatiere(const matiere& m);
   void display() ;
bool verifidet(string);
void suppgm();
void cherchergm();
float moygm(string);
float getcoefById(const string&) const;
float getcoefgmbyid(string);
string getidgm();
string getnomgmfromfile();
float getcoefgmfromfile();
string getidmatfromfile();
vector <string> getidmatbyidgm(string);
string getnomgmbyidgm(string);
};







string GroupeModule::getnomgmbyidgm(string idgm) {
    ifstream inFile("Fichier_GroupeModule.txt");
    string line;
    string nomval;  // Variable pour stocker le nom du groupe module
    bool idExists = false;

    while (getline(inFile, line)) {
        if (line.find("L'id du groupe Module : " + idgm) != string::npos) {
            idExists = true;
            size_t nomPos = line.find("le nom du groupe de module : ");
            if (nomPos != string::npos) {
                // Utilisez une stringstream pour extraire le nom du groupe module
                stringstream ss(line.substr(nomPos + 29));
                ss >> nomval;
                break;
            }
        }
    }

    inFile.close();

    if (!idExists) {
        cout << "L'ID n'existe pas.\n";
    }

    return nomval;
}











vector<string> GroupeModule::getidmatbyidgm(string idgm) {
    vector<string> idmats;
    ifstream groupeFile("Fichier_GroupeModule.txt");
    string line;

    if (!groupeFile.is_open()) {
        cout << "Erreur lors de l'ouverture du fichier de lecture.\n";
        return idmats;
    }

    // Use a regex pattern to match the idgm in the line
    string searchPattern = "L'id du groupe Module : " + idgm;
    regex searchRegex(searchPattern);

    string idmatToken = "Id de la matiere ajoutee : ";

    while (getline(groupeFile, line)) {
        if (regex_search(line, searchRegex)) {
            size_t idmatPos = line.find(idmatToken);
            while (idmatPos != string::npos) {
                idmatPos += idmatToken.length();
                size_t endPos = line.find(" ", idmatPos);
                if (endPos == string::npos) {
                    endPos = line.length();
                }
                string idmat = line.substr(idmatPos, endPos - idmatPos);
                idmats.push_back(idmat);
                idmatPos = line.find(idmatToken, idmatPos);
            }
            break;
        }
    }

    groupeFile.close();

    if (idmats.empty()) {
        cout << "Aucun ID de matière trouvé pour le groupe spécifié.\n";
    }

    return idmats;
}















string GroupeModule::getidmatfromfile() {
    ifstream inFile("Fichier_GroupeModule.txt");
    string line;
    vector<string> ids;

    while (getline(inFile, line)) {
        size_t found = line.find("     Id de la matiere ajoutee : ");
        if (found != string::npos) {
            size_t endPos = line.find_first_of(" \t", found + 32);
            if (endPos != string::npos) {
                string idmat = line.substr(found + 32, endPos - (found + 32));
                ids.push_back(idmat);
            }
        }
    }

    inFile.close();

    // Concatenate the names with the expected format
    string idsString;
    for (const string& idmat : ids) {
        idsString += idmat + "     ";
    }

    return idsString;
}



















float GroupeModule::getcoefgmfromfile() {
    ifstream inFile("Fichier_GroupeModule.txt");
    string line;
    vector<float> coefs;

    while (getline(inFile, line)) {
        size_t found = line.find("     Le coefficient du groupe module : ");
        if (found != string::npos) {
            size_t endPos = line.find_first_of(" \t", found + 39);
            if (endPos != string::npos) {
                float coef = stof(line.substr(found + 39, endPos - (found + 39)));
                coefs.push_back(coef);
            }
        }
    }

    inFile.close();

    // Display all coefficients
    for (const float& coef : coefs) {
        cout <<"Coefficients du groupe module :   " <<coef << "        ";
    }
    cout << endl;

    // You can also return the vector if needed
    // return coefs;

    return 0.0;  // Modify the return statement if necessary
}

































string GroupeModule::getnomgmfromfile() {
    ifstream inFile("Fichier_GroupeModule.txt");
    string line;
    vector<string> noms;

    while (getline(inFile, line)) {
        size_t found = line.find("     le nom du groupe de module : ");
        if (found != string::npos) {
            // Find the end position of the name
            size_t endPos = line.find_first_of(" \t", found + 34);
            if (endPos != string::npos) {
                // Extract the name
                string nom = line.substr(found + 34, endPos - (found + 34));
                noms.push_back(nom);
            }
        }
    }

    inFile.close();

    // Concatenate the names with the expected format
    string namesString;
    for (const string& nom : noms) {
        namesString += "Nom GM : " + nom + "     ";
    }

    return namesString;
}






































string GroupeModule::getidgm() {
    ifstream inFile("Fichier_GroupeModule.txt");
    string line;
    vector<string> ids;  // Stocke les IDs des groupes module existants

    while (getline(inFile, line)) {
        size_t found = line.find("L'id du groupe Module : ");
        if (found != string::npos) {
            // Extraire l'ID de la ligne
            size_t endPos = line.find_first_of(" \t", found + 24);
            if (endPos != string::npos) {
                string id = line.substr(found + 24, endPos - (found + 24));
                ids.push_back(id);
            }
        }
    }

    inFile.close();

    // Afficher les IDs des groupes module existants

    // Si vous avez besoin de retourner les IDs sous forme de chaîne, vous pouvez les concaténer
    // et les retourner comme une seule chaîne, séparés par des virgules ou des espaces.

    // Exemple pour retourner une seule chaîne avec des virgules comme séparateurs :
    string idsString;
    for (const string& id : ids) {
        idsString +="  IdGM  :" + id +"     ";
    }

    // Supprimer la dernière virgule si elle existe
    if (!idsString.empty()) {
        idsString.pop_back();
    }

    return idsString;
}






float GroupeModule ::getcoefgmbyid(string IdGM){


    ifstream inFile("Fichier_GroupeModule.txt");
    string line;
    vector<string> fileContents;
    bool idExists = false;

    while (getline(inFile, line)) {
        if (line.find("L'id du groupe Module : " + IdGM) != string::npos) {
            idExists = true;
      size_t coefPos = line.find("     Le coefficient du groupe module : ");
            if (coefPos != string::npos) {
                float coefval = stoi(line.substr(coefPos + 38));
                return coefval;
            break;
        }
        }

    }
inFile.close();

    if (idExists==false){
                    cout << "-------------L'ID non existant ------------.\n";
    }


    }






























#include <regex>

float GroupeModule::moygm(string idgm) {
    ifstream inFile("Fichier_GroupeModule.txt");
    string line;
    bool idEx = false;
    int valueCount = 0;
    float totalCoefficient = 0;
    float weightedAverage = 0;

    while (!idEx && getline(inFile, line)) {
        if (line.find("L'id du groupe Module : " + idgm) != string::npos) {
            idEx = true;

            regex matiereIdRegex(R"(\d+)");
            smatch match;

            while (regex_search(line, match, matiereIdRegex)) {
                if (valueCount > 1) {
                    string matiereId = match.str();


                    matiere m = getmatiereById(matiereId);
                    float coeff0 = m.getcoef();
                    note n;
                    float moyenne = n.MoyMat(matiereId);

                    totalCoefficient += coeff0;
                    weightedAverage += moyenne * coeff0;
                }

                valueCount++;
                line = match.suffix().str();
            }
            break;
        }
    }

    inFile.close();

    if (!idEx) {
        cout << "Groupe Module ID not found in the file.\n";

    }

    if (totalCoefficient > 0) {
        float finalAverage = weightedAverage / totalCoefficient;
        return finalAverage;
    } else {
        cout << "No matieres found for the given Groupe Module or totalCoefficient is zero.\n";
    }
}























































































void GroupeModule :: cherchergm(){


 string IdGM;
 cout << "\n Entrer l'id du groupe  module dont vous voulez afficher les données :\n";
    cin >> IdGM;  // Utilisez le membre de données IdMat de la classe

    ifstream inFile("Fichier_GroupeModule.txt");
    string line;
    bool idExists = false;

    while (getline(inFile, line)) {
        if (line.find("L'id du groupe Module : " + IdGM) != string::npos) {
            cout << "\nLes données du groupe module :\n";
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







void GroupeModule ::suppgm(){
string IdGM;
    cout << "\nEntrer l'id de groupe Module a supprimer:\n";
    cin >> IdGM;

    ifstream inFile("Fichier_GroupeModule.txt");
    string line;
    vector<string> fileContents;
    bool idExists = false;

    while (getline(inFile, line)) {
        if (line.find("L'id du groupe Module : " + IdGM) != string::npos) {
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
        ofstream outFile("Fichier_GroupeModule.txt", ios::trunc);

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





void GroupeModule::modifgm() {
    string id;
    cout << "\nEntrer l'id de groupe Module a modifier:\n";
    cin >> id;

    ifstream inFile("Fichier_GroupeModule.txt");
    string line;
    vector<string> fileContents;
    bool idExists = false;

    // Keep track of whether the group module line has been found
    bool groupModuleFound = false;

    while (getline(inFile, line)) {
        if (line.find("L'id du groupe Module : " + id) != string::npos) {
            idExists = true;
            groupModuleFound = true; // Indicate that group module line has been found
            cout << "Entrer les nouvelles informations du groupe Module\n";
            cout << "\nEntrer le nom modifié:\n";
            cin >> NomGM;
            cout << "\nEntrer le coefficient du groupe module modifié:\n";
            cin >> CoefGM;

            // Replace the existing group module line with the modified information
            line = "L'id du groupe Module : " + id + "     le nom du groupe de module : " + NomGM + "     Le coefficient du groupe module : " + to_string(CoefGM);

            // Prompt user to input IDs of all the matieres
            string idmat;
            char addAnother;
            do {
                cout << "\nEntrer l'id de la matiere :\n";
                cin >> idmat;
                cout << "\nVoulez-vous ajouter une autre matiere ? (y/n): ";
                cin >> addAnother;

                // Include the ID of each matiere in the modified group module line
                line += "     l'id de matiére :" + idmat;
            } while (addAnother == 'y' || addAnother == 'Y');
        }
        fileContents.push_back(line); // Store the modified or unmodified line
    }

    inFile.close();

    if (!idExists) {
        cout << "\nID Non existant\n";
    } else {
        if (!groupModuleFound) {
            cout << "\nID de groupe module introuvable.\n";
            return;
        }

        ofstream outFile("Fichier_GroupeModule.txt", ios::trunc); // Truncate mode to clear the file

        if (outFile.is_open()) {
            for (const string& content : fileContents) {
                outFile << content << "\n";
            }

            outFile.close();
            cout << "\nLes informations ont été modifiées avec succès.\n";
        } else {
            cout << "\nErreur lors de l'ouverture du fichier de sortie.\n";
        }
    }
}







bool GroupeModule ::verifidet(string id){
    ifstream inFile("Fichier_matiere.txt");
    string line;
    bool idExists = false;

    // Vérifier si l'ID du matiere existe déjà
    while (getline(inFile, line)) {
        if (line.find("Idmatiere : " + id) != string::npos) {
            idExists = true;
            break;
        }
    }

    inFile.close();

    if (idExists) {
                    return true;
}
if(!idExists){
    return false;
}
}

void GroupeModule::setidgm(string a){
IdGM=a;
}
void GroupeModule ::setnomgm(string b){
NomGM=b;
}
void GroupeModule::setcoefgm(float c){
CoefGM=c;
}

GroupeModule :: GroupeModule(){
IdGM="111";
NomGM="Nom groupe module";
CoefGM=2.5;

}

GroupeModule :: GroupeModule(string ch,string ch1,float a,matiere m){
IdGM=ch;
NomGM=ch1;
CoefGM=a;
    ListeMat.push_back(m);


}
string GroupeModule ::getidgm() const{
return IdGM;
}
float GroupeModule ::getcoefgm() const{
return CoefGM;
}

string GroupeModule ::getmongm() const{
return NomGM;
}

vector<matiere> GroupeModule::getliste() const {
    return ListeMat;
}


ostream& operator<<(ostream& os, const GroupeModule& obj) {
    os << "\nL'id du groupe \n" << obj.getidgm() << "\nles coeffecients du groupe module : \n"
       << obj.getcoefgm() << "\n Le nom du groupe module : \n" << obj.getmongm() << "\nLa liste des matiere  :\n";

    for (const matiere& m : obj.getliste()) {
    os << m << "\n";  // Assuming you have a << operator for the matiere class
}


    return os;
}


void GroupeModule :: ajoutmatiere(const matiere& m){
        ListeMat.push_back(m);

}
void GroupeModule::display(){
    cout << "\n l'id du groupe module : \n" << IdGM << "   " << "\n le nom du groupe de module \n" << "    " << NomGM << "   " << "\n le coefficient :\n" << CoefGM << endl;
    cout << "\n ListeMat: \n" << endl;
    for (matiere &mat : ListeMat) {
        mat.display();
    }
}

fstream fichier_GroupeModule;

void GroupeModule::ajoutGM() {
    cout << "\nEntrer l'id du groupe module :\n";
    cin >> IdGM;

    ifstream inFile("Fichier_GroupeModule.txt");
    string line;
    bool idEx = false;

    while (getline(inFile, line)) {
        if (line.find("L'id du groupe Module : " + IdGM) != string::npos) {
            idEx = true;
            break;
        }
    }

    inFile.close();

    if (idEx) {
        cout << "L'id du groupe matiere existe déjà, veuillez en choisir un autre.\n";
    } else {
        cout << "\nEntrer le nom du groupe de module :\n";
        cin >> NomGM;
        cout << "\nEntrer le coefficient :\n";
        cin >> CoefGM;

        string IdMat;
        char addAnother;

        do {
            cout << "\nListe des matieres disponibles:\n";
            ifstream matiereFile("Fichier_matiere.txt");
            while (getline(matiereFile, line)) {
                cout << line << endl;
            }
            matiereFile.close();

            cout << "\nEntrer l'id de la matiere à ajouter :\n";
            cin >> IdMat;

            ifstream matiereCheckFile("Fichier_matiere.txt");
            bool matiereExists = false;
            string matiereInfo;

            // Chercher la ligne correspondant à l'ID saisi dans le fichier
            while (getline(matiereCheckFile, matiereInfo)) {
                if (matiereInfo.find("Idmatiere : " + IdMat) != string::npos) {
                    matiereExists = true;
                    break;
                }
            }
            matiereCheckFile.close();

            if (matiereExists) {
                // Enregistrez les données de matiereInfo dans l'objet matiere
                matiere m = getmatiereById(IdMat);
                ajoutmatiere(m);
                cout << "Matiere ajoutee avec succes.\n";
            } else {
                cout << "Matiere non existante !\n";
            }

            cout << "\nVoulez-vous ajouter une autre matiere ? (y/n): ";
            cin >> addAnother;

        } while (addAnother == 'y' || addAnother == 'Y');

        enregistrerGM();
    }
}

/*
matiere GroupeModule::getmatiereById(const string& IdMat) const {
    matiere result;  // Objet GroupeModule pour stocker les données
    ifstream matiereFile("Fichier_matiere.txt");
    string line;

    while (getline(matiereFile, line)) {
        if (line.find("Idmatiere : " + IdMat) != string::npos) {
            // Utilisez une stringstream pour extraire les données de la ligne
            istringstream iss(line);

            // Ignorer "L'id du groupe Module : "
            string idStr;
            iss >> idStr;
            // Lisez le reste de la ligne comme données
            string restOfLine;
            getline(iss, restOfLine);

            // Initialisez l'objet GroupeModule avec les données lues
            result = matiere(IdMat, restOfLine, 0, enseignant());  // Assurez-vous d'avoir un constructeur adapté
            break;
        }
    }

    matiereFile.close();
    return result;
}

*/
matiere GroupeModule::getmatiereById(const string& IdMat) const {
    matiere result;  // Object to store matiere data
    ifstream matiereFile("Fichier_matiere.txt");
    string line;

    while (getline(matiereFile, line)) {
        if (line.find("Idmatiere : " + IdMat) != string::npos) {
            // Use a stringstream to extract data from the line
            istringstream iss(line);

            // Ignore "Idmatiere : "
            string idStr;
            iss >> idStr;

            // Ignore "Nom de la matiere : "
            string nomStr;
            iss >> nomStr;

            // Ignore "Le coefficient de la matiere : "
            string coefStr;
            iss >> coefStr;

            // Ignore "L'id de l'enseignant de cette matiere : "
            int ensId;
            iss >> ensId;

            // Initialize the matiere object with the read data
            result.setidmat(IdMat);
            result.setnom(nomStr);
            result.setcoef(stof(coefStr));  // Convert string to float
            result.setEnseignantId(ensId); // Assuming you have a setenseignant function

            break;
        }
    }

    matiereFile.close();
    return result;
}








/*

void GroupeModule::enregistrerGM() {
    ofstream outFile("Fichier_GroupeModule.txt", ios::app);

    if (outFile.is_open()) {
        // Write the general information about GroupeModule
        outFile << "\nL'id du groupe Module : " << IdGM << "     le nom du groupe de module : " << NomGM << "     Le coefficient du groupe module : " << CoefGM;

        // Iterate over each matiere in ListeMat
        for (const matiere& m : ListeMat) {
            outFile << "     Id de la matiere ajoutée : " << m.getidmat();
        }

        outFile << " ";  // Add a space or another delimiter at the end

        outFile.close();
        cout << "Le groupe module a été ajouté au fichier avec succès.\n";
    } else {
        cout << "Erreur lors de l'ouverture du fichier de sortie.\n";
    }
}
*/
void GroupeModule::enregistrerGM() {
    ofstream outFile("Fichier_GroupeModule.txt", ios::app);

    if (outFile.is_open()) {
        // Write the general information about GroupeModule
        outFile << "\nL'id du groupe Module : " << IdGM << "     le nom du groupe de module : " << NomGM << "     Le coefficient du groupe module : " << CoefGM;

        // Iterate over each matiere in ListeMat
        for (const matiere& m : ListeMat) {
            outFile << "     Id de la matiere ajoutee : " << m.getidmat();
        }

        outFile << " ";  // Add a space or another delimiter at the end

        outFile.close();
        cout << "Le groupe module a ete ajoute au fichier avec succes.\n";
    } else {
        cout << "Erreur lors de l'ouverture du fichier de sortie.\n";
    }
}

#endif // GROUPE_MODULE_H_INCLUDED
