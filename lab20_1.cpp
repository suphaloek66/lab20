#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string filename,vector<string> &names,vector<int> &scores,vector<char> &grades){
    ifstream data(filename);
        char text[100];
        char name[100];
        int a,b,c;
        while(data.getline(text,100)){
            sscanf(text,"%[^:]: %d %d %d",name,&a,&b,&c);
            names.push_back(name);
            scores.push_back(a+b+c);
            grades.push_back(score2grade(a+b+c));
        }
    }

void getCommand(string &command, string &key){
    string inc,ink;
    cout << "Please input your command: ";
    cin >> inc;
    command = inc;
    if(toUpperStr(inc) == "EXIT"){command = inc;}
    else if(toUpperStr(inc) == "GRADE") {command = inc; cin >> ink; key = ink;}
    else if(toUpperStr(inc) == "NAME") {command = inc; cin.ignore(); getline(cin,ink); key = ink;}
    }

void searchName(vector<string> names,vector<int> scores,vector<char> grades, string key){
    bool found;
        for(unsigned int i = 0; i < scores.size(); i++){
        if(key == toUpperStr(names[i])){
                cout << "---------------------------------" << endl;
                cout << names[i] << "'s score = " << scores[i] <<endl;
                cout << names[i] << "'s grade = " << grades[i] <<endl;
                cout << "---------------------------------" << endl;
                found = true;
            }
        }
        if(!found){
            cout << "---------------------------------\n";
            cout << "Cannot found." << endl;
            cout << "---------------------------------\n";
        }
    }

void searchGrade(vector<string> &names, vector<int> &scores, vector<char> &grades, string key){
    bool found;
                cout << "---------------------------------" << endl;
        for(unsigned int i = 0; i < scores.size(); i++){
        if(*key.c_str() == grades[i]){
                cout << names[i] << " (" << scores[i] << ")" <<endl;
                found = true;
            }
        }
        if(!found){
        cout << "Cannot found." << endl;
        cout << "---------------------------------\n";
        }
        else
            cout << "---------------------------------\n";
    }

int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}
