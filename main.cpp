#include <iostream>
#include <vector>
using namespace std;
#include "matiere.h"
#include "Personne.h"
#include "Groupe_Module.h"
#include "groupe.h"
#include "note.h"
#include "fonctions.h"















   int main() {
       /*
string idgrp;
   cout<<"\nEntrer ID groupe \n";
   cin>>idgrp;
   float moy;
groupe grp;
moy=grp.moyenne(idgrp);
cout<<moy;*/
etudiant et;
enseignant ens;
matiere mat;
GroupeModule gm;
note n;
groupe grp;




char quitter;
int choix;
char choix1;
do{
cout<<"\n*******************Bienvenue****************\n";
cout<<"\n1-Gestion des étudiant\n";
cout <<"\n2-Gestion des Enseignants \n";
cout<<"\n3-Gestion des matiéres\n";
cout<<"\n4-Gestion des Groupe Module\n";
cout<<"\n5-Gestion des notes\n";
cout<<"\n6-Gestion des groupes \n";
cout <<"\n7-Affichage du PV\n";



cout <<"\nEntrer votre choix\n";
cin>>choix;



switch(choix){
case 1 :cout<<"\nA-Ajout d'un étudiant \n";
cout<<"\nB-Suppression d'un étudiant \n";
cout<<"\nC-Recherche d'un étudiant \n";
cout<<"\nD-modification d'un étudiant \n";
break;




case 2:
cout<<"\nA-Ajout d'un Enseignant \n";
cout<<"\nB-Suppression d'un Enseignant \n";
cout<<"\nC-Recherche d'un Enseignant \n";
cout<<"\nD-modification d'un Enseignant \n";
break;




case 3:
cout<<"\nA-Ajout d'une Matiere \n";
cout<<"\nB-Suppression d'une Matiere \n";
cout<<"\nC-Recherche d'une Matiere \n";
cout<<"\nD-modification d'une Matiére \n";
break;



case 4:
cout<<"\nA-Ajout d'un Groupe Module \n";
cout<<"\nB-Suppression d'un Groupe Module \n";
cout<<"\nC-Recherche d'un Groupe Module \n";
cout<<"\nD-modification d'un Groupe Module \n";
break;




case 5:
cout<<"\nA-Ajout d'une note \n";
cout<<"\nB-Suppression d'une note \n";
cout<<"\nC-Recherche d'une note \n";
cout<<"\nD-modification d'une note \n";
break;




case 6:
cout<<"\nA-Ajout d'un Groupe\n";
cout<<"\nB-Suppression d'un Groupe \n";
cout<<"\nC-Recherche d'un Groupe\n";
cout<<"\nD-modification d'un Groupe  \n";
break;
case 7: grp.affichepv();
break;


default :cout<<"\nVeuillez entrer un choix Valide\n";

}
if(choix !=7){
cout <<"\nVeuillez entrer un choix\n";
cin>>choix1;
if(choix ==1 && choix1 =='A'){et.ajout_etudiant();}
if(choix ==1 && choix1 == 'B'){  et.suppression();}
if(choix ==1 && choix1 =='C'){et.recherchEtu();}
if(choix ==1 && choix1 =='D'){et.modifEtu();}





if(choix == 2 && choix1 == 'A'){ens.ajoutEnseignant();}
if(choix ==2 && choix1== 'B'){ens.supp();}
if(choix ==2 && choix1== 'C'){ ens.recherchens();}
if(choix ==2 && choix1== 'D'){ens.modifens();}






if(choix ==3 && choix1== 'A') {mat.ajoutmatiere();}
if(choix ==3 && choix1== 'B'){mat.suppmat();}
if(choix ==3 && choix1== 'C'){mat.recherchemat();}
if(choix ==3 && choix1 == 'D'){mat.modifmatiere();}






if(choix ==4 && choix1== 'A'){gm.ajoutGM();}
if(choix ==4 && choix1 =='B'){gm.suppgm();}
if (choix ==4 && choix1 == 'C'){gm.cherchergm();}
if( choix ==4 && choix1 =='D'){gm.modifgm();}







if(choix ==5 && choix1=='A'){n.ajoutnote();}
if( choix ==5 && choix1=='B'){n.suppnote();}
if(choix ==5 && choix1=='C'){n.recherchenote();}
if(choix ==5 && choix1=='D'){n.modifnote();}


if(choix ==6 && choix1=='A'){grp.ajoutGroupe();}
if ( choix ==6 && choix1=='B'){grp.suppgrp();}
if(choix ==6 && choix1=='C'){grp.recherchegrp();}
if ( choix ==6 && choix1== 'D'){grp.modifgrp();}
}



cout<<"\nVoulez-vous quitter? (y/n)\n";
cin>>quitter;

}while(quitter == 'n'||quitter=='N');

if(quitter=='y'|| quitter=='Y'){

    cout<<"\n-------Au revoire-----\n";
}



   return 0;
}
