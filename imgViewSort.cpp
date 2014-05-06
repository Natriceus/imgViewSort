#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <dirent.h>
#include <vector>
#include <sys/types.h>

using namespace std;

int main()
{
    int a;
    string command0 = "feh ";
    string command1 = "rm -r ";
    string command2 = "mv ";

    DIR* currentdir = opendir(".");

    string destination1 = "/media/storage/traditional games/Images/Landscapes/Fantasy";
    string destination2 = "/media/storage/traditional games/Images/Landscapes/Future";

    while (1){
        dirent* b = readdir(currentdir);
        string file = b[0].d_name;
        if (file.find(".jpg") != string::npos | file.find(".png") != string::npos) {

            cout << file;

            //system((command0 + file).c_str());
            cout <<"choices: 1, 2, 3." << "\n";
            cin >> a;
            switch(a)
            {
                case 1: system((command1 + file).c_str());//(combined string) to char, as required by command()
                case 2: system((command2 + file + destination1).c_str());
                case 3: system((command2 + file + destination2).c_str());
                default: cout << "1: delete \n2:mv1\n3:mv2 \n";

            }
        }
    }
}
