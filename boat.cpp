#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Sailboat
{
private:
    char manufacturer[40], name[40];
    int length, width, draught;
public:
    void setManufacturer(char input[40]) {strcpy(manufacturer, input);}
    void setName(char input[40]) {strcpy(name, input);}
    void setLength(int input) {length = input;}
    void setDraught(int input) {draught = input;}
    void setWidth(int input) {width = input;}
    void WriteInfo() {
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Name: " << name << endl;
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Draught: " << draught << endl;
    }

    bool operator > (Sailboat myBoat) {
        if (length > myBoat.length)
        {
            return true;
        }
        else if (length == myBoat.length && width > myBoat.width)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main(void)
{
    Sailboat myBoat[5];

    ofstream infile ("boat.txt");
    if (!infile.is_open())
    {
        cout << "Could not open boat.txt\n";
        return 1;
    }

    int total;
    infile >> total;

    for (int i = 0; i < total; i++)
    {
        infile >> myBoat[i].manufacturer >> myBoat[i].name >> myBoat[i].lenght;
        infile >> myBoat[i].width >> myBoat[i].draught;
    }

    for (int i = 0; i < total; i++)
    {
        cout << myBoat[i].manufacturer << endl
             << myBoat[i].name << endl
             << myBoat[i].lenght << myBoat[i].width << myBoat[i].draught << endl;
    }

    sort(myBoat, total);

    for (int i = 0; i < total; i++)
    {
        cout << myBoat[i].manufacturer << endl
             << myBoat[i].name << endl
             << myBoat[i].lenght << myBoat[i].width << myBoat[i].draught << endl;
    }

    // success
    return 0;
}

void sort(Sailboat myBoat, int total)
{
    for (int i = 0; i < total; i++)
    {
        for (int j = ; j < total - 1 - i; j++)
        {
            if (myBoat[j] > myBoat[j + 1])
            {
                char temp[40];
                int Temp;
                strcpy(myBoat[j].manufacturer, temp);
                strcpy(myBoat[j].manufacturer, myBoat[j + 1].manufacturer);
                strcpy(myBoat[j + 1].manufacturer, temp);

                strcpy(myBoat[j].name, temp);
                strcpy(myBoat[j].name, myBoat[j + 1].name);
                strcpy(myBoat[j + 1].name, temp);

                Temp = myBoat[j].lenght;
                myBoat[j].length = myBoat[j + 1].lenght;
                myBoat[j + 1].length = Temp;

                Temp = myBoat[j].width;
                myBoat[j].width = myBoat[j + 1].width;
                myBoat[j + 1].width = Temp;

                Temp = myBoat[j].width;
                myBoat[j].width = myBoat[j + 1].width;
                myBoat[j + 1].draught = Temp;
            }
        }
    }
}