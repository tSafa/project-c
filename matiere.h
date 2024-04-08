#ifndef MATIERE_H_INCLUDED
#define MATIERE_H_INCLUDED
#include "Personne.h"

#include <fstream>
#include <sstream>
#include <vector>



class matiere  {
string IdMat ;
string NomMat ;
float Coef ;
enseignant Ens;

public :
    matiere();
    matiere(string , string ,float ,enseignant);
 string getIdmat() const;
 string getnommat() const;
 float getcoef() const;
 enseignant getens() const;
 void ajoutmatiere();
 void enregistrermatiere();
        friend ostream& operator<<(ostream& os, const matiere& obj);
void display();
void setid(string);
string getidmat();
float getcof();
void setnom(string);
void setcoef(float);
void setidmat(string);
enseignant getensById(const int&) const;
void modifmatiere();
void suppmat();
void recherchemat();
void setnommat(string);
 void setEnseignantId(int id) {
        enseignant Ens;
        Ens.setid(id);
    }
string getidmat() const {
        return IdMat;
    }


    string getnommatbyidmat(string);
};







string matiere ::getnommatbyidmat(string idmat){
ifstream inFile("Fichier_matiere.txt");
    string line;
    string nomval;  // Variable pour stocker le nom du groupe module
    bool idExists = false;

    while (getline(inFile, line)) {
        if (line.find("Idmatiere : " + idmat) != string::npos) {
            idExists = true;
            size_t nomPos = line.find("Nom de la matiere : ");
            if (nomPos != string::npos) {
                // Utilisez une stringstream pour extraire le nom du groupe module
                stringstream ss(line.substr(nomPos + 20));
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



















float matiere ::getcof(){

return Coef;
}


void matiere::recherchemat() {
    cout << "\n Entrer l'id de la matiere :\n";
    cin >> IdMat;  // Utilisez le membre de données IdMat de la classe

    ifstream inFile("Fichier_matiere.txt");
    string line;
    bool idExists = false;

    while (getline(inFile, line)) {
        if (line.find("Idmatiere : " + IdMat) != string::npos) {
            cout << "\nLes données de la matiere :\n";
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








void matiere ::suppmat(){
vector<string> fileContents;
         string IdMat;
   cout<<"\n Entrer l'id de la matiere a supprimé:\n";
cin >>IdMat;
 ifstream inFile("Fichier_matiere.txt");
    string line;
    bool idExists = false;
while (getline(inFile, line)) {
        if (line.find("Idmatiere : " + IdMat) != string::npos) {
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
        ofstream outFile("Fichier_matiere.txt", ios::trunc);

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



void matiere ::setidmat(string idmat){

IdMat =idmat;
}



void matiere::modifmatiere() {
    bool idExists = false;  // Declare idExists here



    ifstream inFile("Fichier_matiere.txt");
    string line;
    vector<string> fileContents;

    // Output file contents for verification
    cout << "\nLes mariéres :\n";
    while (getline(inFile, line)) {
        cout << line << endl;
    }
 cout << "\nEntrer l'id de la matiere a modifié:\n";
    cin >> IdMat;
    // Reset file pointer to the beginning
    inFile.clear();
    inFile.seekg(0, ios::beg);

    while (getline(inFile, line)) {
        if (line.find("Idmatiere : " + IdMat + " ") != string::npos) {
            idExists = true;
            cout << "Entrer les nouvelles informations du matiere\n";
            cout << "\nEntrer le nom de la matiere modifié:\n";
            cin >> NomMat;
            cout << "\nEntrer le coefficient  modifié:\n";
            cin >> Coef;
            int idens;
            cout << "\nEntrer le nouveau enseignant de la matiere :\n";
            cin >> idens;

            ifstream ensFile("Fichier_enseignant.txt");
            bool ensIdExists = false;

            while (getline(ensFile, line)) {
                if (line.find("Id enseignant: " + to_string(idens)) != string::npos) {
                    ensIdExists = true;
                    break;
                }
            }

            ensFile.close();

            if (ensIdExists) {
                Ens.setid(idens);
                line = "\nIdmatiere : " + IdMat + "      Nom de la matiere : " + NomMat + "      Le coefficient de la matiere : " + to_string(Coef) + "      L'id de l'enseignant : " + to_string(idens);
                cout << "\nLes informations ont été modifiées avec succès.\n";  // Move inside the block
            } else {
                cout << "\nID enseignant non existant\n";
            }
        }
        fileContents.push_back(line);
    }

    inFile.close();

    if (!idExists) {
        cout << "\nID Non existant\n";
    } else {
        ofstream outFile("Fichier_matiere.txt", ios::trunc);

        if (outFile.is_open()) {
            for (const string &content : fileContents) {
                outFile << content << "\n";
            }
        } else {
            cout << "\nError opening the output file.\n";
        }

        outFile.close();
    }
}











void matiere ::setnom(string matnom){
NomMat=matnom;
}

void matiere ::setcoef(float b){
Coef=b;
}


void matiere ::setid(string a){
IdMat=a;

}
string matiere::getidmat(){
return IdMat;
}


fstream Fichier_matiere ;
matiere :: matiere(){
IdMat="id matiere";
NomMat="nom matiere";
Coef=1.5;


}

matiere :: matiere(string ch1,string ch2,float a, enseignant e){
IdMat=ch1;
NomMat=ch2;
Coef=a;



}



string matiere :: getIdmat() const{
return IdMat;
}
string matiere ::getnommat() const{
return NomMat;

}
float matiere :: getcoef() const{
return Coef;
}
enseignant matiere :: getens() const{
return Ens;

}
ostream& operator<<(ostream& os, const matiere& obj) {
    os << "Id matiere: \n" << obj.getIdmat() << "\nNom matiere : \n" << obj.getnommat() << "\n le coeffcient de la matiere : \n" << obj.getcoef()<<"\nl'enseignant :\n"<<obj.getens();
    return os;
}

void matiere :: display(){
    enseignant e;
    cout <<"l'id du matiere : \n"<<IdMat<<"   "<<"\n le nom de la matiere : \n"<<NomMat<<"  "<<"\n le coefficient de la matiere :  \n"<<"  "<<Coef<<endl;
e.display();
}


void matiere::ajoutmatiere() {
    cout << "\n Entrer l'id du matiere : \n";
    cin >> IdMat;

    ifstream inFile("Fichier_matiere.txt");
    string line;
    bool idExists = false;

    // Vérifier si l'ID du matiere existe déjà
    while (getline(inFile, line)) {
        if (line.find("Idmatiere : " + IdMat) != string::npos) {
            idExists = true;
            break;
        }
    }

    inFile.close();

    if (idExists) {
        cout << "L'ID du matiere entré existe déjà. Veuillez entrer un ID différent.\n";
    } else {
        // Si l'ID du matiere n'existe pas, procédez aux autres saisies
        cout << "\n Entrer le nom de la matiere :\n";
        cin >> NomMat;
        cout << "Entrer le coefficient de la matiere : \n";
        cin >> Coef;

        // Afficher les données des enseignants pour permettre à l'utilisateur de choisir un enseignant
        ifstream enseignantFile("Fichier_enseignant.txt");
        cout << "\nDonnées des enseignants :\n";
        while (getline(enseignantFile, line)) {
            cout << line << endl;
        }
        enseignantFile.close();

        // Demander à l'utilisateur d'entrer l'ID de l'enseignant
        int idEnseignant;
        cout << "\nVeuillez entrer l'id de l'enseignant de cette matiere :\n";
        cin >> idEnseignant;

        // Vérifier si l'ID de l'enseignant existe
        ifstream enseignantCheckFile("Fichier_enseignant.txt");
        bool enseignantExists = false;
        while (getline(enseignantCheckFile, line)) {
            if (line.find("Id enseignant: " + to_string(idEnseignant)) != string::npos) {
                enseignantExists = true;
                break;
            }
        }
        enseignantCheckFile.close();

        if (enseignantExists) {
            // Si l'enseignant existe, enregistrez la matiere dans le fichier
        Ens.setid(idEnseignant);


            enregistrermatiere();

        } else {
            cout << "L'ID de l'enseignant n'existe pas. Veuillez entrer un ID valide.\n";
        }
    }
}





void matiere::enregistrermatiere() {
    ofstream outFile("Fichier_matiere.txt", ios::app);

    if (outFile.is_open()) {
        outFile << "\nIdmatiere : " << IdMat << "      Nom de la matiere : " << NomMat << "      Le coefficient de la matiere : " << Coef << "     L'id de l'enseignant de cette matiere : " << Ens.getid()<< endl;

        outFile.close();
        cout << "La matiere a été ajoutée au fichier avec succès.\n";
    } else {
        cout << "Erreur lors de l'ouverture du fichier de sortie.\n";
    }
}


#endif // MATIERE_H_INCLUDED
