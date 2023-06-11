#include<iostream>
#include<string>
#include<fstream>
#include"TrieTree.h"
#include<Windows.h>
#include<conio.h>
#include"Huffman.h"
#include<iostream>
#include<conio.h>

using namespace std;
// console handle add color to text
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

int main() {
    TrieTree t;
    encode e;
    int option = 0;
    fstream dictionary, editior;
    dictionary.open("Dictionary.txt", ios::in);

    string s;
    //loading a dictionary words from file
    while (!dictionary.eof()) {
        dictionary >> s;
        t.LoadData(s);
    }
    dictionary.close();

    //text editior menu
    cout << "1-New File\n2-Edit File\n3-Exit\n";
    cout << "Enter an option: ";
    cin >> option;

    char key_press;
    string para = "";
    string word = "";
    string* suggested = NULL;
    string loaded_para = "";
    s = "";
    std::cout << "\t\tText Editior\n";

    //if user to add previous data load it
    if (option == 2) {
        editior.open("editior.txt", ios::in);
        editior.seekg(0, ios::end);
        int length = editior.tellg();
        editior.close();
        if (length != 0) {
            e.encodeText("editior.txt");
            s = e.decode("compressedFile.txt");

            for (int i = 0; i < s.size() - 1; i++) {
                cout << s[i];
                para += s[i];
            }
            cout << ' ';
        }
    }

    editior.open("editior.txt", ios::out);

    while (true) {
        key_press = _getch();
        std::cout << key_press << endl;
        if (key_press == '=') {
            editior << para;
            editior.close();
            fstream comp;
            comp.open("compressedFile.txt", ios::out);
            comp.clear();
            comp.close();

            e.encodeText("editior.txt");
            std::cout << "File has been compressed\n";
            exit(1);
        }



        if (key_press != ' ') {

            if (key_press == '/')
            {
                suggested = t.suggest(word);

            }
            if (key_press != '/')
            {
                para += key_press;
                word += key_press;
               //  para += key_press; 
            }

            // suggested = t.suggest(word);
        }
        else {
            para += " ";
            word = "";
        }
        std::system("cls");
        int count = 0;

        if (suggested != NULL && suggested[10] == "true")
            while (count < 10) {
                std::cout << "Text Editior\n";
                std::cout << "word: " << word << endl;
                std::cout << para << endl;
                std::cout << "\nSuggestion" << endl;
                for (int i = 0; i < 10; i++) {
                    if (i == count && suggested[i] != "NULL") {
                        SetConsoleTextAttribute(console, 121);
                        std::cout << "/:";
                    }
                    if (suggested[i] != "NULL")
                        std::cout << suggested[i] << endl;
                    SetConsoleTextAttribute(console, 15);
                }
                std::cout << "choose Suggestion: ";
                key_press = _getch();
                if (key_press == ',')
                    break;
                if (key_press == 'à') {
                    count++;
                }

                if (key_press == ';') {
                    string selected = suggested[count];
                    for (int i = word.length(); i < selected.length(); i++) {
                        para += selected[i];
                    }

                    count = 11;
                }
                suggested[10] = "false";
                std::system("cls");
            }

        std::system("cls");
        std::cout << "\t\tText Editior\n";
        std::cout << "word: " << word << endl;
        std::cout << para;
    }
    return 0;
}