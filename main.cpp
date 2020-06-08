#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<string>
#include<conio.h>
#include<fstream>
using namespace std;

int i, j, p, q, z, k=0, r, e=0;
int brojac, del, gen, bodovi, hintovi[9][9], kop1, kop2, tab[9][9], provjera, ctr1, ctr2, hint, cl, ctr=0, l=0;
int c, o, d, b, vr, a[9][9], m[50], v[50], w[50], n[50], org[9][9];
int odabir, razina, pizl=0, prazno, spr, brpomoc, t, u;
char ime[50];
float vr1;
void generator(void);
void rezultati(void);
void pauzavr(void);
void play(void);
void ispisi(void);
void pomoc(void);
void sudoku(void);
void igra(void);
void poc(void);
void ispisi()
{
    cout << endl << "ST --> 0  1  2  3  4  5  6  7  8";
    printf ("\n---------------------------------\n");
       for(p=0;p<9;p++)
        {
            for(q=0;q<9;q++)
             { 	if(q==0)
                  {
                    printf("RED %d ",p);
                    if(a[p][q]==0)
                    {
                        printf("|");

                        printf("_");

                        printf("|");
                    }
                    else
                    {printf("|");
                    printf("%d",a[p][q]);
                    printf("|");}
                  }
                else if (q==2||q==5)
                  {
                    if(a[p][q]==0)
                  {
                    printf("|_|");}
                    else
                    {
                    printf ("|%d",a[p][q]);
                     printf("|");
                     }
                }
                else
                {
                if(a[p][q]==0)
                  {
                      printf("|_|");
                  }
                else
                 {

                   printf("|%d",a[p][q]);


                   printf("|");}
                }


            }
            if (p==2||p==5||p==8)
            {
            printf ("\n---------------------------------");
            }
            printf("\n");
        }

}

void sudoku()
{
 for(k=0; k<i; k++)
{
  if(i==0)
    break;
  if(a[k][j] == a[i][j])
  {
   a[i][j]=(rand()%9)+1;
   ctr++;
   if(ctr == 100)
  {
   ctr=0;
   for(j=0; j<9; j++)
   a[i][j] = 0;
   j = 0;
   a[i][j] = (rand()%9)+1;
   sudoku();
  }
  sudoku();
 }
}
for(l=0; l < j; l++)
{
  if(j == 0)
    break;
 if(a[i][j] == a[i][l])
 {
  a[i][j] = (rand()%9)+1;
  sudoku();
 }
}
o=0;
for(c=0; c<=6; c+=3)
{if(i>=c&&i<(c+3))
 {
  r=c;
  break;
 }
}

for(d=0;d<=6;d+=3)
{
 if(j>=d && j<(d+3))
 {
  cl=d;
  break;
 }
}

for (r=c; r<(c+3); r++)
{
 for(cl=d; cl<(d+3); cl++)
 {
   if(cl==j && r==i)
  {
   o=1;
   break;
  }
 if(a[r][cl] == a[i][j])
 {
  a[i][j] = (rand()%9)+1;
  sudoku();
 }
 }
 if(o == 1)
    break;
}
}

void rupa()
{
for(z=0; z<prazno; z++)
{
 e=0;
 i=rand() % 9;
 m[z] = i;
 j = rand() % 9;
 n[z] = j;
 if(z != 0)
 {
  for(l=2; l<z; l++)
  {
   if(i == m[l] && j == n[l])
   {
     z--;
     e = 1;
     break;
   }
  }
 }

if(e != 1)
 a[i][j] = 0;
}
for(kop1=0; kop1<9; kop1++)
{
for(kop2=0; kop2<9; kop2++)
 {
  tab[kop1][kop2] = a[kop1][kop2];
  }
 }
}

void pomoc()
{
    system("cls");
    cout << "     " << "** PRAVILA I UPUTE **" << "     ";
    cout << endl;
    cout << "Pozdrav " << ime << ", dobrodosli u Sudoku pomoc. " << endl << "Iako ste novi u Sudoku, mozete ga nauciti ovdje." << endl;
    cout << "Sudoku je vrsta matematicke zagonetke cije je rjesavanje temeljeno na logici. " << endl;
    cout << "Sastoji se od jednog velikog kvadratnog polja, podijeljenog na 81 manjih kvadratica. " << endl;
    cout << "Nadalje, unutar velikog kvadrata, oznaceno je 9 odjeljaka velikih 3x3 polja. " << endl;
    cout << "Postoje razlicite tezine te igre, a koristi se za zabavu ili testiranje inteligencije. " << endl;
    cout << "Polje ce sadrzavati odredene brojeve koji su prethodno generirani i sluziti ce kao pomoc u igri." << endl;
    cout << "Potrebno je popuniti cijelo polje brojevima od 1 do 9, s time da se svaki broj smije pojaviti tocno 9 puta." << endl << "No, jedan broj smije pojaviti samo jednom u svakom retku, svakom stupcu i svakom odjeljku od 3x3 polja. " << endl;
    cout << endl;
    cout << "Stoga, " << ime << ", morate popuniti cijelo 9x9 polje sa 81 brojem bez krsenja ovih pravila." << endl;
    cout << "Takoder, " << ime << ", morati cete pogledati lokaciju celije i upisati broj tj. njezine koordinate." << endl;
    cout << "Naprimjer, 0 2 ili 3 4 itd." << endl;
    cout << endl;
    cout << "Ako ste shvatili upute, pritisnite bilokoju tipku: ";
    getch();
    system("cls");
    cout << "Dostupno je 5 razina prema slozenosti polja. Prema razinama, za svaki tocan odgovor dobivate odredeni broj bodova: " << endl;
    cout << "Pocetnicka razina - 1 bod "  << endl << "Laka razina - 2 boda " << endl << "Srednja razina - 3 boda " << endl << "Teska razina - 4 boda " << endl << "Profesionalna razina - 5 bodova " << endl;
    cout << "Ovo su sva pravila koja su Vam potrebna prije pocetka igranja. Uzivajte u igri Sudoku, sigurni smo da cete se zabaviti. " << endl;
    cout << "Pritisnite bilokoju tipku kako biste vidjeli primjer kako Sudoku izgleda: ";
    getch();
    system("cls");
    cout << "PRIMJER ISPUNJENOG SUDOKU POLJA " << endl;
    ispisi();
    cout << "Pritisnite bilokoju tipku kako biste nastavili i vratili se na prethodni izbornik. " << endl;
    getch();
    system("cls");
    pizl = 1;
}

void igra()
{

    system("cls");
    if(pizl != 1)
    {
     cout << "Unesite ime: " << endl;
     gets(ime);
     cout << "Pozdrav " << ime << "!" << endl;
    }
    do
    {
    for(t=0; t<9; t++)
    {
     for(u=0; u<9; u++)
        hintovi[t][u]=0;
    }

    brpomoc = 0;
    generator();
    cout << "*** DOBRODOSLI U NEOGRANICEN SUDOKU SVIJET ***" << endl;
    cout << endl;
    cout << "*** IZBORNIK ***" << endl;
    cout << "1. IGRAJTE SUDOKU " << endl;
    cout << "2. NAUCITE IGRATI SUDOKU " << endl;
    cout << "3. IZLAZ " << endl;
    cout << endl;
    cout << "Molimo Vas, " << ime << " unesite svoj odabir (1-3)." << endl;
    cin >> odabir;

    switch(odabir)
    {
    case 1: cout << "*** DOSTUPNE RAZINE *** " << endl;
        cout << "1. POCETNICKA RAZINA " << endl;
        cout << "2. LAKA RAZINA " << endl;
        cout << "3. SREDNJA RAZINA " << endl;
        cout << "4. TESKA RAZINA " << endl;
        cout << "5. PROFESIONALNA RAZINA " << endl;
        cout << endl;
        cout << ime << ", unesite svoj odabir (1-5)." << endl;
        cin >> razina;
        switch(razina)
        {
            case 1:
                prazno=40;
                rupa();
                pauzavr();
                poc();
                rezultati();
                break;
            case 2:
                prazno=50;
                rupa();
                pauzavr();
                poc();
                rezultati();
                break;
            case 3:
                prazno=56;
                rupa();
                pauzavr();
                poc();
                rezultati();
                break;
            case 4:
                prazno=60;
                rupa();
                pauzavr();
                poc();
                rezultati();
                break;
            case 5:
                prazno=65;
                rupa();
                pauzavr();
                poc();
                rezultati();
                break;
            default:
            cout << ime << ", molimo Vas pravilno odaberite razinu. Biti cete preusmjereni na prethodni izbornik. " << endl;
                break;
        }
                   break;
        case 2:
            pomoc();
            break;
        case 3:
            cout << ime << ", hvala Vam na igranju, vratite nam se ponovno! " << endl;
            getch();
            exit(0);
            default:
            cout << ime << ", molimo Vas pravilno odaberite opciju." << endl;
            break;
        }
}while(odabir != 3);
}

void generator()
{
 for(i=0; i<9; i++)
 {
  for(j=0; j<9; j++)
   {
    a[i][j] = 0;
   }
 }
 for(i=0; i<9; i++)
 {
  for(j=0; j<9; j++)
   {
    b = rand();
    vr = (b%9)+1;
    a[i][j] = vr;
    if ((i==j) && (i==0))
     {
        if ((k==l) && (k==0))
        {
         continue;
        }
         }
        else
    {
     sudoku();
    }
   }
 }
 for(i=0; i<9; i++)
 {
  for(j=0; j<9;j++)
   {
    org[i][j] = a[i][j];
   }
 }

}

void poc()
{
  ispisi();
  while(1)
  {
  gen = 0;
  hint = -1;
  cout << ime << ", unesite polozaj celije (stupac redak). " << endl << "Kada smatrate da ste gotovi, unesite 10 10 kako biste podnijeli svoj Sudoku napredak." << endl << "Kada podnesete svoj napredak, prikazat ce Vam se rijesena Sudoku tablica. " << endl;
  cin >> i >> j;
  if(i <= 8 && j <= 8)
  {
  if(tab[i][j] != 0)
  {
   gen=1;
   cout << ime << ", ovo je prethodno generirani broj. Ne mozete ga promijeniti. Pritisnite bilokoju tipku za nastavak igre. " << endl;
   getch();
   system("cls");
   ispisi();
  }
  if(gen != 1)
  {
  if(hintovi[i][j] != 0)
  {
    cout << "Uzeli ste pomoc za ovaj element. Ne pokusavajte ga promijeniti. Pritisnite bilokoju tipku za nastavak igre. " << endl;
    getch();
    system("cls");
    ispisi();
    continue;
  }
  v[brojac] = i;
  w[brojac] = j;
  brojac++;
  cout << "Za pomoc, upisite 0, inace upisite 1. " << endl;
  cin >> hint;

  if(hint == 0)
  {
   brpomoc++;
   a[i][j] = org[i][j];
   hintovi[i][j] = a[i][j];
   system("cls");
   ispisi();
  }
  else if(hint==1)
  {
   cout << "Unesite broj od 1-9 ili 0 kako biste izbrisali. " << endl;
   cin >> spr;
   if(spr == 0 && hintovi[i][j] == 0)
   {
     a[i][j]=0;
     system("cls");
     ispisi();
     continue;
   }
  if(spr >= 1 && spr <= 9)
  {
   a[i][j] = spr;
   if(spr == org[i][j])
     bodovi++;
  system("cls");
  ispisi();
  }
 else
 {
   cout << "!!!!!!! " <<ime << ", molim Vas unesite valjani broj !!!!!!! " << endl;
   cout << "Pritisnite bilokoju tipku za nastavak. Ako niste sigurni, zatrazite pomoc (hint). " << endl;
   getch();
   system("cls");
   ispisi();
 }
 }
}
}
   else
   {
     if(i == 10 && j == 10)
       break;
    else
    {
     cout << "NEVAZECA LOKACIJA CELIJE! " << endl;
     system("cls");
     ispisi();
    }
 }
}
cout << ime << ", hvala Vam na igranju! " << endl;
}

void pauzavr()
{
    for(del=1,l=0; del<=25; del++)
    {
    system("cls");
    cout << "Ovo bi moglo potrajati. Molim Vas ne izlazite! " << endl;
    cout << endl;
    cout << "GENERIRANJE IGRE SUDOKU PO VASEM ZAHTJEVU...     ";
    cout << ++l << "% GENERIRANO";
    for(vr1=0;vr1<250000;vr1++)
        ;
    system("cls");
    cout << "Ovo bi moglo potrajati. Molim Vas ne izlazite! " << endl;
    cout << endl;
    cout << "GENERIRANJE IGRE SUDOKU PO VASEM ZAHTJEVU...     ";
    cout << ++l << "% GENERIRANO";
    for(vr1=0; vr1<250000; vr1++)
        ;
    system("cls");
    cout << "Ovo bi moglo potrajati. Molim Vas ne izlazite! " << endl;
    cout << endl;
    cout << "GENERIRANJE IGRE SUDOKU PO VASEM ZAHTJEVU...     ";
    cout << ++l << "% GENERIRANO";
    for(vr1=0; vr1<250000; vr1++)
        ;
    system("cls");
    cout << "Ovo bi moglo potrajati. Molim Vas ne izlazite! " << endl;
    cout << endl;
    cout << "GENERIRANJE IGRE SUDOKU PO VASEM ZAHTJEVU...     ";
    cout << ++l << "% GENERIRANO";
    for(vr1=0; vr1<250000; vr1++)
        ;
    }
}

void rezultati()
{
    system("cls");
if(bodovi == prazno)
   cout << "Bravo! Rijesili ste Sudoku u potpunosti tocno. " << ime << ", dobro ste igrali! " <<endl;
if(razina==2)
  bodovi*=2;
else if(razina==3)
  bodovi*=3;
else if(razina==4)
  bodovi*=4;
else if(razina==5)
  bodovi*=5;
cout << "Molimo Vas pricekajte dok se zbroje Vasi bodovi. " << endl;
for(vr1=0; vr1<5000000; vr1++)
    ;
cout << endl << "--------------------------------------------------" << endl;
cout << "Ime igraca je: " << ime << endl;
if(razina == 1)
 {
    cout << "Odabrana Sudoku razina: POCETNICKA " << endl;
    cout << "Broj praznih celija koje ste trebali popuniti: 40" << endl;
    cout << "Broj praznih celija koje ste ispravno popunili: " << bodovi << endl;
    if(bodovi > 30)
       cout << ime << ", dobro ste igrali! " << endl;
   }
else if(razina == 2)
 {
    cout << "Odabrana Sudoku razina: LAKA " << endl;
    cout << "Broj praznih celija koje ste trebali popuniti: 50" << endl;
    cout << "Broj praznih celija koje ste ispravno popunili: " << bodovi/2 << endl;
      if(bodovi>80)
     cout << ime << ", dobro ste igrali! " << endl;
 }
else if(razina==3)
 {
    cout << "Odabrana Sudoku razina: SREDNJA " << endl;
    cout << "Broj praznih celija koje ste trebali popuniti: 56" << endl;
    cout << "Broj praznih celija koje ste ispravno popunili: " << bodovi/3<< endl;
      if(bodovi>85)
    cout << ime << ", dobro ste igrali! " << endl;
 }
else if(razina==4)
 {
    cout << "Odabrana Sudoku razina: TESKA " << endl;
    cout << "Broj praznih celija koje ste trebali popuniti: 60" << endl;
    cout << "Broj praznih celija koje ste ispravno popunili: " << bodovi/4<< endl;
   if(bodovi>100)
     cout << ime << ", dobro ste igrali! " << endl;
 }
else if(razina == 5)
 {
    cout << "Odabrana Sudoku razina: PROFESIONALNA " << endl;
    cout << "Broj praznih celija koje ste trebali popuniti: 65" << endl;
    cout << "Broj praznih celija koje ste ispravno popunili: " << bodovi/5 << endl;
  if(bodovi > 110)
     cout << ime << ", dobro ste igrali! " << endl;
 }
cout << "Broj osvojenih bodova: " << bodovi << endl;
ifstream popis2;
popis2.open("DATA/Ukbod.txt", ios::binary);
int cita;
popis2.read((char*)&cita, sizeof(cita));
cout<<"Broj osvojenih bodova prosle igre: "<<cita<<endl;
popis2.close();
ofstream popis;
popis.open("DATA/Ukbod.txt", ios::binary);
popis.write((char*)&bodovi, sizeof(bodovi));
popis.close();
if(bodovi > 0)
cout << "--------------------------------------------------" << endl;
cout << "Pritisnite bilokoju tipku. " << endl;
getch();
system("cls");
cout << "VAS SUDOKU. " << endl;
ispisi();
for(vr1=0; vr1<10000000; vr1++)
    ;
cout << "RIJESEN SUDOKU. " << endl;
for(ctr1=0; ctr1<9; ctr1++)
{
 for(ctr2=0; ctr2<9; ctr2++)
   {
    a[ctr1][ctr2] = org[ctr1][ctr2];
   }
}
}

int main()
{
  srand(time(NULL));
  generator();
  igra();
  return 0;
}
