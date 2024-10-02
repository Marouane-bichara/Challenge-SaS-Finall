#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nom[20], prenom[20],dpart[20];
    int numeroUnique,jour,mois,annee;
    float noteGenerale;
}Etudiants;

Etudiants etudiant[100];
int size = 0;

void ajouterEtudiant();
void ModifierOsuprime();
void afficher();
void moyenne();
void statics();
void recheacher();
void tri();



int main()
{
    int choix;
    do
    {
        printf("\n");
        printf("_______________\n");
        printf("\n");
        printf("1. Ajouter un etudiant.\n");
        printf("2. Modifier ou supprimer etudiant.\n");
        printf("3. afficher.\n");
        printf("4. Calculer la moyenne generale.\n");
        printf("5. Statistiques.\n");
        printf("6. Rechercher un etudiant.\n");
        printf("7. Trier les etudiant.\n");
        printf("8. Exte.\n");
        printf("Entrez le choix : ");
        scanf("%d" , &choix);

    system("@cls||clear");

        switch (choix)
        {
        case 1:
            ajouterEtudiant();
            break;
        case 2:
            system("@cls||clear");
            ModifierOsuprime();
            break;
        case 3:
            system("@cls||clear");
            afficher();
            break;
        case 4:
            system("@cls||clear");
            moyenne();
            break;
        case 5:
            statics();
            break;
        case 6:
            recheacher();
            break;
        case 7:
            tri();
            break;
        }

    } while (choix != 8);

    return 0;
}

void UserInfo (int index)
{ 
    int choix;
    printf("\n");
    printf("_______________\n");
    printf("\n");
    printf("Entrez le nom : ");
    scanf("%s",etudiant[index].nom);
    printf("Entrez le prenom : ");
    scanf("%s",etudiant[index].prenom);
    printf("Entrez le jour de naissance : ");
    scanf("%d",&etudiant[index].jour);
    printf("Entrez le mois  :");
    scanf("%d",&etudiant[index].mois);
    printf("Entrez l'annee : ");
    scanf("%d",&etudiant[index].annee);
    printf("Entrez le numero unique: ");
    scanf("%d", &etudiant[index].numeroUnique);
    printf("Entrez le departement.\n");
    printf("1. Pour MATH\n");
    printf("2. Pour PC\n");
    printf("3. Pour SVT\n");
    printf("Entrez votre choix : ");
    scanf("%d", &choix);
    while (choix < 1 || choix > 3)
    {
        printf("\nChoix invalide. Entrez un nombre entre 1 et 3 : ");
        scanf("%d", &choix);
    }

    switch (choix)
    {
    case 1:
        strcpy(etudiant[index].dpart, "MATH");
        break;
    case 2:
        strcpy(etudiant[index].dpart, "PC");
        break;
    case 3:
        strcpy(etudiant[index].dpart, "SVT");
        break;
    }
    printf("Entrez le note Generale :");
    scanf("%f" , &etudiant[index].noteGenerale);
}

void ajouterEtudiant()
{
    UserInfo(size);
    size++;
}

void suprimer()
{
    int id;
    printf("Entre le numero unique : ");
    scanf("%d" , &id);
    for (int i = 0; i < size; i++)
    {
        if (id == etudiant[i].numeroUnique)
        {
            for (int j = i; j < size - 1; j++)
            {
                etudiant[j] = etudiant[j + 1];
            }
            size--;
            break;
        }
        
    }
    
}

void Modifer()
{
    int id;
    printf("Entrez le numero unique : ");
    scanf("%d" , &id);
    for (int i = 0; i < size; i++)
    {
        if (id == etudiant[i].numeroUnique)
        {
            UserInfo(i);
        }
    }
}

void ModifierOsuprime()
{
    int choix2;;
    do
    {
        printf("\n");
        printf("_______________\n");
        printf("\n");
        printf("1. Modifier etudiant\n");
        printf("2. Supprimer etudiant\n");
        printf("3. Exit\n");
        printf("Entrez le choix : ");
        scanf("%d" , &choix2);

    switch (choix2)
    {
    case 1:
        Modifer();
        break;
    case 2:
        suprimer();
        break;
    }
    } while (choix2 != 3);

}

void afficher()
{
    for (int i = 0; i < size; i++)
    {
        printf("\n");
        printf("_______________\n");
        printf("\n");
        printf("Etudiant numero : %d\n" , etudiant[i].numeroUnique);
        printf("Prenom : %s\n" , etudiant[i].prenom);
        printf("Nome : %s\n" , etudiant[i].nom);
        printf("Date de naissance : %d/%d/%d\n" , etudiant[i].jour , etudiant[i].mois , etudiant[i].annee);
        printf("Departement : %s\n" , etudiant[i].dpart);
        printf("Note generale : %.2f\n", etudiant[i].noteGenerale);
    }
}

void lemoyenGeneraldeUnvirsity()
{
    float lemoyeenGeneralDeUnviersity = 0;
    for (int i = 0; i < size; i++)
    {
        lemoyeenGeneralDeUnviersity += etudiant[i].noteGenerale;
    }
    lemoyeenGeneralDeUnviersity /= size; 
    printf("\n");
    printf("_______________\n");
    printf("\n");
    printf("Le moyen general de Unviersity : %.2f\n" , lemoyeenGeneralDeUnviersity);
}

void lemoyenGeneraldeDepartement()
{
    
    float math = 0, svt = 0, pc = 0;
    int mathEtudiant = 0, svtEtudiant = 0, pcEtudiant = 0;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(etudiant[i].dpart, "MATH") == 0)
        {
            math += etudiant[i].noteGenerale;
            mathEtudiant++;
        }
        else if (strcmp(etudiant[i].dpart, "PC") == 0)
        {
            pc += etudiant[i].noteGenerale;
            pcEtudiant++;
        }
        else if (strcmp(etudiant[i].dpart, "SVT") == 0)
        {
            svt += etudiant[i].noteGenerale;
            svtEtudiant++;
        }
    }  
    if (mathEtudiant > 0)
    {
        math /= mathEtudiant;
        printf("\n le moyenne general de math est: %.2f", math);
    }  
        if (pcEtudiant > 0)
    {
        pc /= pcEtudiant;
        printf("\n le moyenne general de pc est: %.2f", pc);
    }
    if (svtEtudiant > 0)
    {
        svt /= svtEtudiant;
        printf("\n le moyenne general de svt est: %.2f", svt);
    }
}

void moyenne()
{
    int choix3;
    

    do
    {
        printf("\n");
        printf("_______________\n");
        printf("\n");
        printf("\n1. Le moyenne general de Unviersity.");
        printf("\n2. Le moyenne genral de departement.");
        printf("\n3. Exit\n");
        printf("Entrez le choix : ");
        scanf("%d" , &choix3);

        switch (choix3)
        {
        case 1:
            lemoyenGeneraldeUnvirsity();
            break;
        case 2:
            lemoyenGeneraldeDepartement();
            break;
        }
    } while (choix3 != 3);
}

void EtudiantsAyantMoyenneSeuil()
{
    float moyenneSeuil;
    printf("\nentrez le moyenne seuil: ");
    scanf("%f", &moyenneSeuil);
    for (int i = 0; i < size; i++)
    {
        if (moyenneSeuil <= etudiant[i].noteGenerale)
        {
            printf("\n");
            printf("_______________\n");
            printf("\n");
            printf("Etudiant numero : %d\n" , etudiant[i].numeroUnique);
            printf("Prenom : %s\n" , etudiant[i].prenom);
            printf("Nome : %s\n" , etudiant[i].nom);
            printf("Date de naissance : %d/%d/%d\n" , etudiant[i].jour , etudiant[i].mois , etudiant[i].annee);
            printf("Departement : %s\n" , etudiant[i].dpart);
            printf("Note generale : %.f\n", etudiant[i].noteGenerale);
        }
    }
}

void afficherLeNombreTotalDetudiantsInscrits()
{
    printf("\nle nombre total d'etudiants inscrits est: %d", size);
}

void afficherLeNombreDetudiantsDansChaqueDepartement()
{
    int mathEtudiatn = 0, svtEtudiant = 0, pcEtudiant = 0;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(etudiant[i].dpart, "MATH") == 0)
        {
            mathEtudiatn++;
        }
        else if (strcmp(etudiant[i].dpart, "PC") == 0)
        {
            pcEtudiant++;
        }
        else if (strcmp(etudiant[i].dpart, "SVT") == 0)
        {
            svtEtudiant++;
        }
    }

    printf("\nle nombre d'etudiants dans chaque departement");
    printf("\npour MATH: %d ", mathEtudiatn);
    printf("\npour PC: %d ", pcEtudiant);
    printf("\npour SVT: %d ", svtEtudiant);
}

void les3EtudiantsAyantLesMeilleuresNotes()
{
    if (size < 3)
    {
        printf("Il n'y a pas 3 etudiants pour afficher.\n");
        return; 
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j > size - 1; j++)
        {
            Etudiants temp = etudiant[i];
            etudiant[i] = etudiant[j];
            etudiant[j] = temp;
        }
    }
        printf("\nLes 3 etudiants ayant les meilleures notes: \n");
        for (int i =  0 ; i < 3 ; i++)
        {
            printf("\n");
            printf("_______________\n");
            printf("\n");
            printf("Etudiant numero : %d\n" , etudiant[i].numeroUnique);
            printf("Prenom : %s\n" , etudiant[i].prenom);
            printf("Nome : %s\n" , etudiant[i].nom);
            printf("Date de naissance : %d/%d/%d\n" , etudiant[i].jour , etudiant[i].mois , etudiant[i].annee);
            printf("Departement : %s\n" , etudiant[i].dpart);
            printf("Note generale : %.f\n", etudiant[i].noteGenerale);
        }
        
}

void etudiantSuperieureA10DansChaqueDepartement()
{
    int mathEtudiatn = 0, svtEtudiant = 0, pcEtudiant = 0;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(etudiant[i].dpart, "MATH") == 0)
        {
            if (etudiant[i].noteGenerale >= 10)
            {
                mathEtudiatn++;
            }
        }
        else if (strcmp(etudiant[i].dpart, "PC") == 0)
        {
            if (etudiant[i].noteGenerale >= 10)
            {
                pcEtudiant++;
            }
        }
        else if (strcmp(etudiant[i].dpart, "SVT") == 0)
        {
            if (etudiant[i].noteGenerale >= 10)
            {
                svtEtudiant++;
            }
        }
    }

    printf("\nle nombre d'etudiant superieure a 10 dans chaque departement");
    printf("\npour MATH: %d ", mathEtudiatn);
    printf("\npour PC: %d ", pcEtudiant);
    printf("\npour SVT: %d ", svtEtudiant);
}

void statics()
{
    int choix;
    do
    {
        printf("\n");
        printf("_______________\n");
        printf("\n");
        printf("\n1. Le nombre total d'etudiants.");
        printf("\n2. Afficher le nombre d'etudiants dans chaque departement.");
        printf("\n3. Afficher les etudiants ayant une moyenne generale superieure a un certain seuil.");
        printf("\n4. Afficher les 3 etudiants ayant les meilleures notes.");
        printf("\n5. Afficher les etudiants ayant 10 dans chaque departement");
        printf("\n6. Exite\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        system("@cls||clear");
        switch (choix)
        {
        case 1:
            afficherLeNombreTotalDetudiantsInscrits();
            break;
        case 2:
            afficherLeNombreDetudiantsDansChaqueDepartement();
            break;
        case 3: 
            EtudiantsAyantMoyenneSeuil();
            break;
        case 4:
            les3EtudiantsAyantLesMeilleuresNotes();
            break;
        case 5:
            etudiantSuperieureA10DansChaqueDepartement();
            break;
        }
    } while (choix != 6);
    
}

void RecherchParleNome()
{
    char nome[20];
    printf("Entrez le nome : ");
    scanf("%s" , nome);

    for (int i = 0; i < size; i++)
    {
        if (strcasecmp(nome , etudiant[i].nom) == 0)
        {
            printf("Etudiant numero : %d\n" , etudiant[i].numeroUnique);
            printf("Prenom : %s\n" , etudiant[i].prenom);
            printf("Nome : %s\n" , etudiant[i].nom);
            printf("Date de naissance : %d/%d/%d\n" , etudiant[i].jour , etudiant[i].mois , etudiant[i].annee);
            printf("Departement : %s\n" , etudiant[i].dpart);
            printf("Note generale : %.f\n", etudiant[i].noteGenerale);  
        }   
    }
    
}

void afficherEtudiantParDepartement()
{
    int choix;
    char departement[10];
    printf("Entrez le departement.\n");
    printf("1. Pour MATH\n");
    printf("2. Pour PC\n");
    printf("3. Pour SVT\n");
    printf("Entrez votre choix : ");
    scanf("%d", &choix);

    if (choix == 1)
    {
        strcpy(departement, "MATH");
    }
    else if (choix == 2)
    {
        strcpy(departement, "PC");
    }
    else if (choix == 3)
    {
        strcpy(departement, "SVT");
    }

    for (int i = 0; i < size; i++)
    {
        if (strcmp(etudiant[i].dpart, departement) == 0)
        {
                printf("Etudiant numero : %d\n" , etudiant[i].numeroUnique);
                printf("Prenom : %s\n" , etudiant[i].prenom);
                printf("Nome : %s\n" , etudiant[i].nom);
                printf("Date de naissance : %d/%d/%d\n" , etudiant[i].jour , etudiant[i].mois , etudiant[i].annee);
                printf("Departement : %s\n" , etudiant[i].dpart);
                printf("Note generale : %.f\n", etudiant[i].noteGenerale);
        }
    }
}

void recheacher()
{
    int choix;

    do
    {
        printf("\n");
        printf("_______________\n");
        printf("\n");
        printf("1. Rchercher un etudiant par son nom.\n");
        printf("2. Aficher la list des etudiants inscrits dans un department specifique.\n");
        printf("3. Exite.\n");
        printf("Entrez votre choix : ");
        scanf("%d" , &choix);

        system("@cls||clear");
        switch (choix)
        {
        case 1:
            RecherchParleNome();
            break;
        case 2:
            afficherEtudiantParDepartement();
            break;
        }
    } while (choix != 3);
    
}

void TriParleNome()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (strcmp(etudiant[j].nom , etudiant[j + 1].nom) > 0)
            {
                Etudiants temp;
                temp = etudiant[j];
                etudiant[j] = etudiant[j+1];
                etudiant[j+1] = temp;
            }
            
        }
        
    }

    afficher();
}

void TriParMoyenGeneral()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (etudiant[j].noteGenerale < etudiant[j + 1].noteGenerale )
            {
                Etudiants temp;
                temp = etudiant[j];
                etudiant[j] = etudiant[j+1];
                etudiant[j+1] = temp;
            }
            
        }
        
    }

    afficher();
}

void Triparseperieura10()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j > size - 1; j++)
        {
            if (etudiant[j].noteGenerale > etudiant[j + 1].noteGenerale )
            {
                Etudiants temp;
                temp = etudiant[j];
                etudiant[j] = etudiant[j+1];
                etudiant[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        if (etudiant[i].noteGenerale > 10)
        {
        printf("Etudiant numero : %d\n" , etudiant[i].numeroUnique);
        printf("Prenom : %s\n" , etudiant[i].prenom);
        printf("Nome : %s\n" , etudiant[i].nom);
        printf("Date de naissance : %d/%d/%d\n" , etudiant[i].jour , etudiant[i].mois , etudiant[i].annee);
        printf("Departement : %s\n" , etudiant[i].dpart);
        printf("Note generale : %.f\n", etudiant[i].noteGenerale);            
        }
        
    }
}

void tri()
{
    int choix;
    do
    {
        printf("\n");
        printf("_______________\n");
        printf("\n");
        printf("1. Tri par le nome.\n");
        printf("2. tries par moyenne generale.\n");
        printf("3. tries selone moyenne superieur ou egale a 10/20.\n");
        printf("4. Exite.\n");
        printf("Entrez votre choix: ");
        scanf("%d" , &choix);

        system("@cls||clear");

        switch (choix)
        {
        case 1:
            TriParleNome();
            break;
        
        case 2:
            TriParMoyenGeneral();
            break;
        case 3:
            Triparseperieura10();
            break;
        }
    } while (choix != 4);    
}