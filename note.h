#ifndef NOTE_H_INCLUDED
#define NOTE_H_INCLUDED
#include "Personne.h"
#include "matiere.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

class note{
    matiere m;
    etudiant et;
    float note1;
    string type;
    vector<pair<string, float>> tableauNotes;
public :
    note();
    note(matiere,etudiant,float,string);
    matiere getmatiere() const;
    etudiant getetudiant() const;
    float getnote() const;
    string gettype() const;

void ajoutnote();
void enregistrer();
    void display();
    void modifnote();
    void suppnote();
    friend std::istream& operator>>(std::istream& is, note& n);
void afficher();
float MoyMat(string);
    void recherchenote();
};

float note::MoyMat(string idmat) {
    float somme = 0;
    int nbNote = 0;


    ifstream inFile("Fichier_note.txt");
    string line;

    while (getline(inFile, line)) {
        // Check if the line contains the specified subject ID
        size_t pos = line.find("L'id de la matiere : " + idmat);
        if (pos != string::npos) {
            // Extract the note value from the line
            size_t notePos = line.find("La note : ");
            if (notePos != string::npos) {
                float noteValue = stof(line.substr(notePos + 10));
                somme += noteValue;
                nbNote++;
            }
        }
    }

    inFile.close();

    if (nbNote > 0) {
        float moy = somme / nbNote;
        return moy;
    } else {
        cout << "\nAucune note trouvée pour l'ID de matiere spécifié.\n";
        return 0;
    }
}

void note ::recherchenote(){
    int id;
 cout << "\n Entrer l'id de l'etudiant dont vous voulez afficher les données :\n";
    cin >> id;  // Utilisez le membre de données IdMat de la classe

    ifstream inFile("Fichier_note.txt");
    string line;
    bool idExists = false;

    while (getline(inFile, line)) {
        if (line.find("L'id de l'etudiant :" + to_string(id) + " ") != string::npos) {
            cout << "\nLes données de la note :\n";
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

void note::suppnote(){

vector<string> fileContents;
         int id;
   cout<<"\n Entrer l'id de l'etudiant que vous voulez supprimer la note:\n";
cin >>id;
  tableauNotes.erase(
        std::remove_if(
            tableauNotes.begin(),
            tableauNotes.end(),
            [id](const std::pair<std::string, float>& pair) {
                return pair.first == to_string(id);
            }),
        tableauNotes.end()
    );
 ifstream inFile("Fichier_note.txt");
    string line;
    bool idExists = false;
while (getline(inFile, line)) {
        if (line.find("L'id de l'etudiant :" + to_string(id) + " ") != string::npos) {
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
        ofstream outFile("Fichier_note.txt", ios::trunc);

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







void note::modifnote() {
    int id;
    cout << "\nEntrer l'id de l'etudiant que vous voulez changer la note:\n";
    cin >> id;

    ifstream inFile("Fichier_note.txt");
    string line;
    vector<string> fileContents;
    bool idExists = false;

    while (getline(inFile, line)) {
        if (line.find("L'id de l'etudiant :" + to_string(id) + " ") != string::npos) {
            idExists = true;
            cout << "Entrer les nouvelles informations du note\n";
            cout << "\nEntrer la note modifié:\n";
            cin >> note1;
            cout << "\nEntrer le type modifié:\n";
            cin >> type;
            string idmat;
cout <<"\nEntrer l'id de la matiere dont vous modifiez la note :\n";
cin>>idmat;
ifstream matiereCheckFile("Fichier_matiere.txt");
    bool matExists = false;
    while (getline(matiereCheckFile, line)) {
        if (line.find("Idmatiere : " + idmat) != string::npos) {
            matExists = true;
            break;
        }
    }
    matiereCheckFile.close();
    if (!matExists) {
        cout << "\nL'ID de la matière n'existe pas. Veuillez entrer un ID valide.\n";
        return; // Exiting the function if the subject ID is not found
    }
if(matExists){



            // Update the internal data of the note object
            m.setidmat(idmat);  // Replace with appropriate method to set the ID of the subject
            et.setId(id);  // Assuming et.setId exists to set the ID of the student
for (auto &pair : tableauNotes) {
    if (pair.first == idmat) {
        pair.second = note1;  // Update the note value in the pair
        break;
    }
}


            // Update the line with the correct IDs and data
            line = "\nLa note : " + to_string(note1) + "    Le type d'examen : " + type + "     L'id de l'etudiant :" + to_string(id) + "     L'id de la matiere : " + m.getidmat();
        }}
        fileContents.push_back(line);
    }

    inFile.close();

    if (!idExists) {
        cout << "\nID Non existant\n";
    } else {
        ofstream outFile("Fichier_note.txt", ios::trunc);

        if (outFile.is_open()) {
            for (const string &content : fileContents) {
                outFile << content << "\n";
            }

            cout << "\nLes informations ont été modifiées avec succès.\n";
        } else {
            cout << "\nError opening the output file.\n";
        }

        outFile.close();
    }
}




note :: note(){
note1=20;
type ="ds";
}
note:: note(matiere mat,etudiant etu,float a,string ch){
 m=mat;
et=etu;
note1=a;
type=ch;

}
void note::display(){
m.display();
et.display();
cout<<"la note :"<<note1<<"type :"<<type<<endl;
}
matiere note :: getmatiere() const{
return m ;

}
etudiant note :: getetudiant() const{
    return et;
}

float note::getnote() const{
return note1;
}
string note::gettype() const{
return  type;

}


ostream& operator<<(ostream& os, const note& obj) {
    os << "\nLa matiere \n" << obj.getmatiere()<< "\nLes informations de l etudiant: \n" << obj.getetudiant() << "\n La note : \n" << obj.getnote()<<"\nType  :\n"<<obj.gettype();
    return os;
}






void note::ajoutnote() {
    string line;
    cout << "Entrer la note :\n";
    cin >> note1;
    cout << "\n le type de l'examen:\n";
    cin >> type;

    // Reading student data for display
    ifstream studentFile("Fichier_etudiant.txt");
    cout << "\nDonnées des étudiants :\n";
    while (getline(studentFile, line)) {
        cout << line << endl;
    }
    studentFile.close();

    // Checking for student ID
    int idetudiant;
    cout << "\nVeuillez entrer l'id de l'étudiant :\n";
    cin >> idetudiant;
    ifstream studentCheckFile("Fichier_etudiant.txt");
    bool etuExists = false;
    while (getline(studentCheckFile, line)) {
        if (line.find("Id etudiant : " + to_string(idetudiant)) != string::npos) {
            etuExists = true;
            break;
        }
    }
    studentCheckFile.close();

    // If student ID does not exist, print an error message
    if (!etuExists) {
        cout << "\nL'ID de l'étudiant n'existe pas. Veuillez entrer un ID valide.\n";
        return; // Exiting the function if the student ID is not found
    }

    // Student ID exists, move on to check subject ID
    et.setId(idetudiant); // Assuming et.setId exists to set the ID of the student

    // Reading subject data for display
    ifstream matiereFile("Fichier_matiere.txt");
    cout << "\nLa liste des matières :\n";
    while (getline(matiereFile, line)) {
        cout << line << endl;
    }
    matiereFile.close();

    // Checking for subject ID
    string idmatiere;
    cout << "\nVeuillez entrer l'id de la matière :\n";
    cin >> idmatiere;
    ifstream matiereCheckFile("Fichier_matiere.txt");
    bool matExists = false;
    while (getline(matiereCheckFile, line)) {
        if (line.find("Idmatiere : " + idmatiere) != string::npos) {
            matExists = true;
            break;
        }
    }
    matiereCheckFile.close();

    // If subject ID does not exist, print an error message
    if (!matExists) {
        cout << "\nL'ID de la matière n'existe pas. Veuillez entrer un ID valide.\n";
        return; // Exiting the function if the subject ID is not found
    }

    // Both IDs exist, proceed to add the note to the file
    m.setid(idmatiere); // Assuming m.setid exists to set the ID of the subject
    tableauNotes.push_back(make_pair(idmatiere, note1));

    enregistrer(); // Proceed to save the note
}


fstream fichier_note;
void note ::enregistrer(){
    ofstream outFile("Fichier_note.txt", ios::app);
    if (outFile.is_open()) {

outFile << "\nLa note : " << note1 << "     Le type d'examen : " << type << "     L'id de l'etudiant :" << et.getid() <<"     L'id de la matiere : "<<m.getidmat()<< endl;
    outFile.close();
    cout << "La note a été ajoutée au fichier avec succès.\n";
    } else {
        cout << "Erreur lors de l'ouverture du fichier de sortie.\n";
    }


}
#endif // NOTE_H_INCLUDED
