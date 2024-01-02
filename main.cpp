#include <iostream>

using namespace std;

int Menu()
{
    int x;
    cout<<endl;
    cout<<"1. Dodaj element tablicy"<<endl;
    cout<<"2. Wstaw element tablicy"<<endl;
    cout<<"3. Usun element tablicy"<<endl;
    cout<<"4. Wyœwietl elementy tablicy"<<endl;
    cout<<"5. Zapisz do pliku"<<endl;
    cout<<"6. Wczytaj z pliku"<<endl;
    cout<<"7. Wyjscie z programu"<<endl;
    cin>>x;
    cout<<endl;
    return x;
}

int main()
{
    int m;
    int *p = NULL;
    int n = 0;
    while(true)
    {
        m = Menu();
        switch(m)
        {
        case 7:
            {
                return 0;
            }
        case 1:
            {
                int * tmp = NULL;
                tmp = new int[n+1]; //tworzenie nowej tablicy (o jeden wiêkszej ni¿ poprzednia)
                if(p != NULL) //je¿eli istnieje poprzednia tablica to:
                {
                    for(int i=0;i<n;i++)
                    {//przekopiuj zawartoœæ poprzedniej tablicy do nowej
                        tmp[i] = p[i];
                    }
                    //usuñ poprzedni¹ tablicê
                    delete[] p;

                }
                cout<<"Podaj wartosc elementu tablicy: ";
                cin>>tmp[n];  //wstaw now¹ wartoœæ do tablicy (na koniec)
                p = tmp; //przekopiuj adres nowej tablicy do wskaŸnika p
                n++; //zwiêksz iloœæ elementów tablicy o 1
                break;
            }
        case 2:
            {
                //wstawienie elementu w dowolne miejsce
                break;
            }
        case 3:
            {
                //usuwanie dowolnego elementu (po indeksie)
                break;
            }
        case 4:
            {
                cout<<"Zawartosc tablicy:"<<endl;
                for(int i=0;i<n;i++)
                {
                    cout<<p[i]<<", ";
                }
                cout<<endl;
                break;
            }
        case 5:
            {
                //zapis danych do pliku
                break;
            }
        case 6:
            {
                //wczytanie danych z pliku
                break;
            }
        default:
            {
                cout<<"Nieprawidlowa opcja"<<endl;
            }

        }
    }

    return 0;
}
