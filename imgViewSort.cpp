#include <iostream>
#include <stdlib.h>
#include <string>
#include <dirent.h>

using namespace std;

string checkDir();

int main()
{
    string command0 = "feh ";
    string command1 = "rm -r ";
    string command2 = "mv ";
    string help = "1: Delete file \n2: mv to destination 1 \n3: mv to destination 2 \nAny other key: This text. \n";
    DIR* currentdir = opendir(".");
    int a;

    string destination1 = checkDir();
    string destination2 = checkDir();

    cout << "Usage: \n" << help;

    while (1){
            dirent* d = readdir(currentdir);
            string file = d[0].d_name;
            if (file.find(".jpg") != string::npos | file.find(".png") != string::npos | file.find(".gif") !=string::npos) {

                        cout << "Image: " << file << "\n";
                        system((command0 + " '" + file + "'").c_str());

                        cin >> a;
                        switch(a){
                                        case 1: system((command1 + " '" + file + "'").c_str());
                                        case 2: system((command2 + " '" + file + "' '" + destination1 + "'").c_str());
                                        case 3: system((command2 + " '" + file + "' '" + destination2 + "'" ).c_str());
                                        default: cout << help;
                                    }
                    }
        }
    return 0;
}

string checkDir()
{
    string destination;
    DIR * wrongdir = 0;
    while (!wrongdir){
            cout << "Enter valid destination directory. ";
            cin >> destination;
            wrongdir = opendir(destination.c_str());
        }
    return destination;
}
