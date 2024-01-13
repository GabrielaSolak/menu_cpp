#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int Menu()
{
    int x;
    cout<<endl;
    cout<<"1. Dodaj element tablicy"<<endl;
    cout<<"2. Wstaw element tablicy"<<endl;
    cout<<"3. Usun element tablicy"<<endl;
    cout<<"4. Wyświetl elementy tablicy"<<endl;
    cout<<"5. Zapisz do pliku"<<endl;
    cout<<"6. Wczytaj z pliku"<<endl;
    cout<<"7. Wyjscie z programu"<<endl;
    cout<<"> ";
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
                tmp = new int[n+1]; //tworzenie nowej tablicy (o jeden większej niż poprzednia)
                if(p != NULL) //jeżeli istnieje poprzednia tablica to:
                {
                    for(int i=0;i<n;i++)
                    {//przekopiuj zawartość poprzedniej tablicy do nowej
                        tmp[i] = p[i];
                    }
                    //usuń poprzednią tablicę
                    delete[] p;

                }
                cout<<"Podaj wartosc elementu tablicy: ";
                cin>>tmp[n];  //wstaw nową wartość do tablicy (na koniec)
                p = tmp; //przekopiuj adres nowej tablicy do wskaźnika p
                n++; //zwiększ ilość elementów tablicy o 1
                break;
            }
        case 2:
            {
                //wstawienie elementu w dowolne miejsce
                int ind;
                int * tmp = NULL;
                tmp = new int[n+1];

                cout<<"Podaj indeks elementu: ";
                cin>>ind;

                if(p != NULL && ind >=0 && ind <=n)
                {
                    for(int i=n-1; i>=0; i--)
                    {
                        if(i>=ind)
                        {
                            tmp[i+1] = p[i];
                        }
                        else if(i<ind)
                        {
                            tmp[i] = p[i];
                        }
                    }
                    delete[] p;
                    cout<<"Podaj wartosc elementu tablicy: ";
                    cin>>tmp[ind];
                    p = tmp;
                    n++;
                }
                break;
            }
        case 3:
            {
                //usuwanie dowolnego elementu (po indeksie)
                int usu;
                int * tmp = NULL;
                tmp = new int[n-1];

                cout<<"Podaj indeks usuwanego elementu: ";
                cin>>usu;

                if(p != NULL && usu >= 0 && usu < n)
                {
                    for(int i=0, j=0; i<n; ++i)
                    {
                        if(i != usu)
                        {
                            tmp[j] = p[i];
                            ++j;
                        }
                    }
                    delete[] p;
                    p = tmp;
                    --n;
                }
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
                fstream menu_plik;
                menu_plik.open("C:\\Gabriela_Solak-menu\\menu.txt", ios::out | ios::trunc);
                if(menu_plik.is_open())
                {
                    for(int i=0; i<n; i++)
                    {
                        menu_plik << p[i] << endl;
                    }
                    menu_plik.close();
                }
                else
                {
                    cout << "Nieudana proba zapisu danych do pliku";
                }


                break;
            }
        case 6:
            {
                //wczytanie danych z pliku
                fstream menu_plik;
                menu_plik.open("C:\\Gabriela_Solak-menu\\menu.txt", ios::in);
                string el;
                if(!menu_plik.is_open())
                {
                    cout << "Proba wczytania danych z pliku nie powiodla sie";
                    break;
                }
                n = 0;
                while(getline(menu_plik, el))
                {
                    n++;
                }
                delete[] p;
                int * p = NULL;
                p = new int[n];
                int j = 0;

                menu_plik.close();
                menu_plik.open("C:\\Gabriela_Solak-menu\\menu.txt", ios::in);

                while(getline(menu_plik, el))
                {
                    p[j] = stoi(el); //zamiana string na int
                    //cout << p[j] << endl;
                    j++;
                }

                menu_plik.close();
                break;
            }
        default:
            {
                cout<<"Nieprawidlowa opcja"<<endl;
            }
        }
    }
    return 0;
