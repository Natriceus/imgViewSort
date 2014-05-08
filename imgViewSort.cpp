#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <dirent.h>
#include <vector>
#include <sys/types.h>

using namespace std;

void checkDir(string &destination);

int main()
{
    int a;
    string command0 = "feh ";
    string command1 = "rm -r ";
    string command2 = "mv ";
    string help = "1: Delete file \n2: mv to destination 1 \n3: mv to destination 2 \nAny other key: This text. \n";

    DIR* currentdir = opendir(".");

    string destination1;
    string destination2;

    checkDir(destination1);
    checkDir(destination2);

    cout << "Usage: \n" << help;

    while (1){
        dirent* d = readdir(currentdir);
        string file = d[0].d_name;
        if (file.find(".jpg") != string::npos | file.find(".png") != string::npos) {

            cout << file <<  endl;
            system((command0 + " '" + file + "'").c_str());

            cin >> a;
            switch(a)
            {
                case 1: system((command1 + " '" + file + "'").c_str());//(combined string) to char, as required by command()
                case 2: system((command2 + " '" + file + "' '" + destination1 + "'").c_str());
                case 3: system((command2 + " '" + file + "' '" + destination2 + "'" ).c_str());
                default: cout << help;
            }
        }
    }
}

void checkDir(string &destination)  {
    DIR * wrongdir = opendir("deliberately wrong");
    while (wrongdir == 0){
        cout << "Enter valid destination directory. ";
        cin >> destination;
        wrongdir = opendir(destination.c_str());
    }
}
