#include <iostream>
#include <fstream>
#include <string>
#include <exeption>
#include <algorithm>
#include <vector>
#include <stringstream>
using namespace std;

template <typename Data_type> //must explicitly introduce type, cannot deduce
vector<Data_type> get_data(char* file_name , int i = -1){
    ifstream reader(file_name);
    if (!reader){
        throw logic_error("input file does not exist");
        }
    vector<Data_type> data;
    Data_type data_regist;
    if (i > 0){
        for (int num=0 ; num<i ; num++){
            reader>>data_regist;
            data.push_back(data_regist);
            }
        }
    else {
        while(reader>>data_regist){
            data.push_back(data_regist);
            }
         }
    return data;
    }
    
int main(int argc,char** argv){
    vector<int> data;
    if (argc == 2){
        data = get_data<int>(argv[1]);
        }
    else if (argc == 3){
        istringstream getint(argv[2]);
        int datanum;
        getint>>datanum;
        data = get_data<int>(argv[1],datanum);
        }
    else if (argc == 1){
        cout<<"enter file name:";
        char* file;
        cin>>file;
        cout<<"enter number for data (or -1 if you do not know how much data there is):";
        int datanum;
        cin>>datanum;
        data = getdata<int>(file,datanum);
        }
    else{
        cerr<<"too much arguments!";
        exit(1);
        }
    int total = accumulate(data.begin(),data.end(),0);
    double moneytot;
    cout<<"input total number of money";
    cin>>moneytot;
    vector<double> moneypp;
    for (auto x : data){
        moneypp.push_back(moneytot*(x/total));
        }
    ofstream calculated("outdata.txt");
    for (auto x : moneypp){
        calculated<<x<<endl;
        }
    }
