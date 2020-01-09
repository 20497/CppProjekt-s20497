#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <Windows.h>

#define LEFT_KEY 75
#define RIGHT_KEY 77
#define DOWN_KEY 72
#define UP_KEY 80

void wspolrzedne(int X, int Y);
void Wstep();
void WczytajDane(float &size, char &znak);
void Rysuj(float size, float x, float y, char znak);
void Przesuwanie(float size, float &x, float &y, char znak);

using namespace std;

int main()
{
    float x = 1, y = 1;
    float size;
    char znak;
    system("cls");

    Wstep();
    WczytajDane(size, znak);
    Rysuj(size, x, y, znak);
    _getch();
    Przesuwanie(size, x, y, znak);
    return 0;
}

void Wstep()
{

    cout << "\t********** Program rysowania figury ,, Y '' poziomo znakami ASCII ******** \n"
        "\t************************** Program umozliwia: ******************************** \n"
        "\t* wybor znaku kodu ASCII \n"
        "\t* wczytanie poczatkowych rozmiarow figury (limit od 5 do 22) \n"
        "\t* przesuwanie figury klawiszami strzalek \n"
        "\t* powiekszanie oraz zmniejszanie figury za pomoca + oraz - \n"
        "\t* ograniczenie przesuwania figury do rozmiaru ekranu \n"
        "\t \n"
		"\t Nacisnij dowolny przycisk aby kontynuowac \n";
    _getch();
}

void WczytajDane(float &size, char &znak)  //wczytanie od uzytkownika znaku ascii oraz poczatkowego rozmiaru figury
{
    system("cls");
    int max = 22, min = 5, rozmiar;
    do
    {
        cout << "Podaj rozmiar figury z zakresu (5-22): ";
        cin >> rozmiar;
        if(rozmiar > max)
        	cout<<"Podaj mniejszy rozmiar "<<endl;
        if(rozmiar < min)
        	cout<<"Podaj wiekszy rozmiar "<<endl;
    } while (rozmiar < min || rozmiar > max);
    size = rozmiar;

    cout << "Podaj znak kodu ASCII: ";
    cin >> znak;

}

void Rysuj(float size, float x, float y, char znak)
{
    system("cls");

    for (int i = 0; i < size / 2; i++)   // petla rysujaca kazda z 3 linii figury ,, Y '' 
	{
        wspolrzedne(x+i, y+i), cout << znak;	
											
    	wspolrzedne(x + i, y + size - i), cout << znak;
    	
		wspolrzedne(x+size/2+i, y+size/2), cout << znak;
	}
    wspolrzedne(0, 25), cout << "strzalki: przesuwanie; +/-: powieksz, zmniejsz; ESC: wyjscie";
}

void Przesuwanie(float size, float &x, float &y, char znak) // przesuwanie figury klawiszami strzalek na osi x oraz y
{
    char klawisz;

    do
    {
        klawisz = _getch();

        switch (klawisz)
        {
        case RIGHT_KEY:                  
        {
        	x++;
            break;
        }

        case LEFT_KEY:           
        {
            x--;
            break;
        }

        case DOWN_KEY:
        {
            y--;
            break;
        }
        case UP_KEY:
        {
            y++;
            break;
        }

        case '+':						// zwiekszanie figury jezeli miesci sie w limicie
        {
            size++;

            if (size < 5 || size > 23)
                size--; y--;
            break;
        }

        case '-':					 // zmniejszanie figury jezeli miesci sie w limicie
        {
            size--;
            if (size < 5 || size > 23)
                size++;
            break;
        }

        }
            Rysuj(size, x, y, znak); 

    } while (klawisz != 27);

}
void wspolrzedne(int X, int Y)		// wspolrzedne na osi x oraz y
{
    COORD coord;
    coord.X = X;
    coord.Y = Y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
