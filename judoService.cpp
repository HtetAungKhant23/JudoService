//
// Created by User on 4/23/2023.
//

#include <iostream>
using namespace std;
#define USERSIZE 10

class Judo{
public:
    string trainingPlanName[5], athleteName[USERSIZE], plan[USERSIZE];
    float trainingPlanPrice[5], currentWeight[USERSIZE];
    int userID[USERSIZE], numberOfCompetition[USERSIZE], privateCoachingHours[USERSIZE], competitionWeight[USERSIZE];
    int totalUser = 5;
    int index[5] = {0,0,0,0,0};


    void mainMenu();
    void trainingPlan();
    void fakeUserInfo();

    Judo(){
        trainingPlan();
        fakeUserInfo();
        mainMenu();
    }

    string weightCat[6];
    int weight[5];

    void adminMenu();
    void viewAllUserInfo();
    void sortingByID();
    int searchUserInfoByID(int upd);
    void updateUserInfoByID();
    void deleteUserAccByID();
    void printInfo(int idx);
    int findIdx(string opt);
    int inputValidation(string opt);


// **** user part ****
//    void userMenu();
//    void priceView();
//    void planView();
//    void weightCategories();

};

void Judo::fakeUserInfo() {

    int uID[5] = {107,105, 106, 104, 101};
    string name[5] = {"htet", "aung", "khant", "hak", "phoo"};
    string trainPlan[5] = {"workout", "home workout", "gym", "walking", "swimming"};
    float curWeight[5] = {77.11, 55.12, 50.31, 90.42, 73};
    int competiWeight[5] = {73, 81, 90, 100, 73 };
    int numOfCompeti[5] = {1,2,1,1,2};
    int privateHours[5] = {5,3,4,2,5};

    for (int i = 0; i < 5; ++i) {
        userID[i] = uID[i];
        athleteName[i] = name[i];
        plan[i] = trainPlan[i];
        currentWeight[i] = curWeight[i];
        numberOfCompetition[i] = numOfCompeti[i];
        privateCoachingHours[i] = privateHours[i];
        competitionWeight[i] = competiWeight[i];
    }

}

void Judo::trainingPlan() {
    string name[5] = {"Beginner","Intermediate","Elite","Private tuition","Competition entry fee"};
    float price[5] = {25,30,35,9.5,22};
    for (int i=0; i<5; i++){
        trainingPlanName[i] = name[i];
        trainingPlanPrice[i] = price[i];
    }
    for (int i = 0; i < 10; ++i) {
        userID[i] = '\0';
        currentWeight[i] = '\0';
        competitionWeight[i] = '\0';
        numberOfCompetition[i] = '\0';
        privateCoachingHours[i] = '\0';
        if (i < 5) {
            weight[i] = '\0';
        }
    }
}

void Judo::mainMenu() {
    string option;
    cout << "1. Admin " << endl;
    cout << "2. User " << endl;
    cout << "3. Exit from program : ";
    cin >> option;
    if(option == "1"){
        cout << "\n*** welcome from admin menu ***\n"<<endl;
        adminMenu();
    } else if (option == "2"){
        cout << "\n*** welcome from user menu***\n"<<endl;
        mainMenu();
    } else if (option == "3"){
        cout << " \n Completely exit from program \n";
        exit(1);
    } else {
        cout << " Invalid option!!! Please choose carefully!!!" << endl;
        cout << "*******************\n" << endl;
        mainMenu();
    }
}

void Judo::adminMenu() {
    string adOption;
    cout << "1. View all user's training plans " << endl;
    cout << "2. Search information by using ID " << endl;
    cout << "3. Update information by using ID " << endl;
    cout << "4. Delete account by using ID " << endl;
    cout << "5. Exit >> ";
    cin >> adOption;
    if (adOption == "1"){
        cout << "\n";
        viewAllUserInfo();
        adminMenu();
    } else if(adOption == "2"){
        cout << "\n";
        searchUserInfoByID(0);
        adminMenu();
    } else if(adOption == "3"){
        cout << "\n";
        updateUserInfoByID();
        adminMenu();
    } else if (adOption == "4"){
        cout << "\n";
        deleteUserAccByID();
        adminMenu();
    } else if (adOption == "5"){
        cout << " **************************** \n" << endl;
        mainMenu();
    } else {
        cout << " Invalid option!!! Please choose carefully!!!" << endl;
        cout << "*******************\n" << endl;
        adminMenu();
    }
}

void Judo::sortingByID() {
    int copyID[5];
    int temp = 0;
    for (int i = 0; i < totalUser; i++) {
        copyID[i] = userID[i];
    }
    for (int i = 0; i < totalUser; i++) {
        for (int j = i+1; j < totalUser; j++) {
            if (copyID[i] > copyID[j]){
                temp = copyID[i];
                copyID[i] = copyID[j];
                copyID[j] = temp;
            }
        }
    }
// find index
    for(int i=0; i<totalUser; i++){
        for(int j=0; j<totalUser; j++){
            if(copyID[i] == userID[j]){
                index[i] = j;
            }
        }
    }

}

void Judo::printInfo(int idx) {
    cout << "\n";
    cout << "Athlete's ID   => " << userID[idx] << endl;
    cout << "Athlete's Name => " << athleteName[idx] << endl;
    cout << "Training Plan  => " << plan[idx] << endl;
    cout << "Current Weight => " << currentWeight[idx] << "kg" << endl;
    cout << "Number Of Competitions => " << numberOfCompetition[idx] << endl;
    cout << "Private Coaching Hours => " << privateCoachingHours[idx] << "hrs" << endl;
    cout << "Competition Weight     => " << competitionWeight[idx] << "kg" << endl;
    cout << "\n****************************************** \n" << endl;
}

int Judo::findIdx(string opt) {
    int findID = stoi(opt);
    for (int i = 0; i < totalUser; ++i) {
        for (int j = 0; j < totalUser; ++j) {
            if(userID[index[i]] == findID){
                return index[i];
            }
        }
    }
    return -1;
}

int Judo::inputValidation(string opt){
    int len = opt.size();
    for(int i=0; i<len; i++){
        if(opt[i] < 48 || opt[i] > 58 ){
            return -1;
        }
    }
    return 1;
}

int Judo::searchUserInfoByID(int upd){
    string option;
    if(upd == 1){
        cout << "Enter user's ID to update information => ";
    } else {
        cout << "Enter user's ID to search information => ";
    }
    cin >> option;
    int correct = inputValidation(option);
    if(correct==1){
        int found = findIdx(option);
        if(found != -1){
            printInfo(found);
            if (upd == 1){
                return found;
            }
        } else{
            cout << "\nUser Information is not found by this ID : " << option << "\n" << endl;
            if(upd == 1){
                adminMenu();
            }
        }
    } else{
        cout << " Invalid option!!! Please choose carefully!!!" << endl;
        cout << "*******************\n" << endl;
        if(upd == 1){
            searchUserInfoByID(1);
        } else{
            searchUserInfoByID(0);
        }
    }
}

void Judo::updateUserInfoByID() {
    int updUserIdx = searchUserInfoByID(1);
    string option;
    here:
    cout << "How many information do you want to update => ";
    cin >> option;
    int correct = inputValidation(option);
    if (correct == 1){
        int amount = stoi(option);
        int arr[amount];
        cout << "What information do you want to update" << endl;
        cout << "1. Athlete's ID \n2. Athlete's Name \n3. Training Plan \n4. Current Weight\n5. Number Of Competitions \n6. Private Coaching Hours\n7. Competition Weight \n";
        for (int i = 0; i < amount; i++) {
            cout << "=> ";
            cin >> arr[i];
        }
        for(int i=0; i<amount; i++){
            switch (arr[i]) {
                case 1:
                    cout << "Enter new ID => ";
                    cin >> userID[updUserIdx];
                    break;
                case 2:
                    cout << "Enter new name => ";
                    cin >> athleteName[updUserIdx];
                    break;
                case 3:
                    cout << "Enter new training plan => ";
                    cin >> plan[updUserIdx];
                    break;
                case 4:
                    cout << "Enter new current weight => ";
                    cin >> currentWeight[updUserIdx];
                    break;
                case 5:
                    cout << "Enter new Number Of Competitions => ";
                    cin >> numberOfCompetition[updUserIdx];
                    break;
                case 6:
                    cout << "Enter new Private Coaching Hours => ";
                    cin >> privateCoachingHours[updUserIdx];
                    break;
                case 7:
                    cout << "Enter new Competition Weight => ";
                    cin >> competitionWeight[updUserIdx];
                    break;
            }
        }
        cout << "****************************\n  new information updated!!!\n******************************\n" << endl;
    } else{
        cout << " Invalid option!!! Please choose carefully!!!" << endl;
        cout << "*******************\n" << endl;
        goto here;
    }

}

void Judo::deleteUserAccByID() {
    int delUserIdx = searchUserInfoByID(1);
    int i = delUserIdx;
    while (userID[i] != '\0'){
        userID[i] = userID[i+1];
        athleteName[i] = athleteName[i+1];
        plan[i] = plan[i+1];
        currentWeight[i] = currentWeight[i+1];
        numberOfCompetition[i] = numberOfCompetition[i+1];
        privateCoachingHours[i] = privateCoachingHours[i+1];
        competitionWeight[i] = competitionWeight[i+1];
        i++;
    }
    totalUser--;
    cout << "User account is completely deleted!!!\n\n**********************************************\n" << endl;
}

void Judo::viewAllUserInfo() {
    sortingByID();
    int i = 0;
    while (userID[i] != '\0'){

        printInfo(index[i]);
        i++;
    }
}

int main() {
    Judo obj;
    return 0;
};
