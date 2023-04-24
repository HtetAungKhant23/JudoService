#include <iostream>
#include "iomanip"
using namespace std;
#define USERSIZE 10

class Judo{
public:
    string trainer_name[5]={"Trainer A","Trainer B","Trainer C","Trainer D","Trainer E"};
    string trainingPlanName[5], athleteName[USERSIZE], plan[USERSIZE], competitionWeight[USERSIZE];
    float trainingPlanPrice[5], currentWeight[USERSIZE];
    int userID[USERSIZE], numberOfCompetition[USERSIZE], privateCoachingHours[USERSIZE], total_fees[USERSIZE];
    int totalUser = 0;
    int index[USERSIZE];

    int weight_list[6]={100,100,90,81,73,66};
    string comWeightCat[6] = {"Heavy weight", "Light Heavy weight", "Middle weight", "Light middle weight", "Light weight", "Fly weight"};

    void mainMenu();
    void trainingPlan();

    Judo(){
        trainingPlan();
        mainMenu();
    }

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
    void userMenu();
    void registration();
    void view_trainer_and_price();
    void view_training_plan(int flag);
    void view_weight_categories();
    int private_coach();
    void userOutput(int lvl, int pHour, int resWeight);
    float priceOutput(int plan);
    int choicePlan();
    int choiceWeightCat();

};

void Judo::trainingPlan() {
    string name[5] = {"Beginner","Intermediate","Elite","Private tuition","Competition entry fee"};
    float price[5] = {25,30,35,9.5,22};
    for (int i=0; i<5; i++){
        trainingPlanName[i] = name[i];
        trainingPlanPrice[i] = price[i];
    }
    for (int i = 0; i < USERSIZE; ++i) {
        userID[i] = '\0';
        currentWeight[i] = '\0';
        competitionWeight[i] = '\0';
        numberOfCompetition[i] = '\0';
        privateCoachingHours[i] = '\0';
        index[i] = '\0';
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
        userMenu();
    } else if (option == "3"){
        cout << " \n Completely exit from program \n";
        exit(1);
    } else {
        cout << " Invalid option!!! Please choose carefully!!!" << endl;
        cout << "*******************\n" << endl;
        mainMenu();
    }
}




void Judo::userMenu() {
    string user_op;
    flag1:
    cout<<"\n\nEnter option \n1-View Trainer and trainner price\n2-View trinning plan\n3-Registration\n4-Exit : ";
    cin>>user_op;
    int check = inputValidation(user_op);
    if(check == 1){
        int op = stoi(user_op);
        switch (op) {
            case 1:
                view_trainer_and_price();
                userMenu();
                break;
            case 2:
                view_training_plan(0);
                userMenu();
                break;
            case 3:
                registration();
                userMenu();
                break;
            case 4:
                cout << "\n";
                mainMenu();
        }
    }else{
        cout<<"Invalid input\n";
        goto flag1;
    }
}

void Judo::view_trainer_and_price() {
    cout<<"\nTrainer name       Price\n";
    int idx= sizeof(trainer_name)/ sizeof(trainer_name[0]);
    for(int i=0;i< idx;i++){
        cout<<trainer_name[i]<<"          $9.50\n";
    }
}

void Judo::view_training_plan(int flag) {
    cout << "\n";
    int k = 2;
    for ( int i = 0; i < 5; i++){
        if (i < 3){
            if(i==2){
                k = 5;
            }
            cout << i+1 << ". " << trainingPlanName[i] << "(" << k << " sessions per week)" << "-weekly fee => $" << trainingPlanPrice[i] << endl;
            k++;
        }else if (i==3 && flag != 1){
            cout << i+1 << ". " << trainingPlanName[i] << "-per hour => $" << trainingPlanPrice[i] << endl;
        } else if (i==4 && flag != 1){
            cout << i+1 << ". " << trainingPlanName[i] << "-per competition => $" << trainingPlanPrice[i] << endl;
        }
    }
    cout << " *************************************" << endl;
}

void Judo::view_weight_categories() {
    cout<<"\nThis is weight categories(kg)\n";
    for(int i=0; i<6; i++){
        if(i==0) {
            cout << i+1 << ". " << comWeightCat[i] << ":Unlimited (over" << weight_list[i] << ")" << endl;
        } else{
            cout << i+1 << ". " << comWeightCat[i] << " => " << weight_list[i] << endl;
        }
    }
}

int Judo::private_coach(){
    string opt;
    int priHour = 0;
    flag1:
    cout << "If u want private coaching enter 1 \nIf u don't want enter 2 : ";
    cin >> opt;
    int check = inputValidation(opt);
    if(check == 1){
        int ch = stoi(opt);
        switch (ch) {
            case 1:
                flag2:
                cout << "Enter number of hour for private coaching a week : ";
                cin >> priHour;
                if(priHour > 5){
                    cout << "Athletes can receive a maximum of five hour's private coaching a week\n";
                    goto flag2;
                } else{
                    return priHour;
                }
            case 2:
                return -1;
            default:
                cout << "****" << endl;
                break;
        }
    } else{
        cout << " Invalid option!!! Please choose carefully!!!" << endl;
        cout << "*******************\n" << endl;
        goto flag1;
    }
}










int Judo::choicePlan(){
    int ret = 0;
    view_training_plan(1);
    cout<<"Enter your plan number that u want to buy(1 or 2 etc...) : ";
    cin >> ret;
    return ret;
}

int Judo::choiceWeightCat(){
    int ret_weight = 0;
    view_weight_categories();
    cout << "Enter competition weight category that u want to participate(1 or 2 etc..):\n";
    cin >> ret_weight;
    return ret_weight;
}


void Judo::registration() {
    int id = 0;
    int lev_option = 0;
    int numOfCompeti = 0;
    int priCoachHour = 0;
    int com_weight = 0;
    int toFees = 0;
    string name;
    float curWeight;
    cout << "Enter your ID number :";
    cin >> id;
    cout << "Enter your name : ";
    cin >> name;
    cout << "Enter your current weight in kg : ";
    cin >> curWeight;
    lev_option = choicePlan();
    if(lev_option == 2 || lev_option == 3){
        flag1:
        cout << "Number of competitions entered this month : ";
        cin >> numOfCompeti;
        if(numOfCompeti > 2){
            cout << "Only Two competitions are held in each month!!!\n";
            goto flag1;
        }
        com_weight = choiceWeightCat();
        int che = private_coach();
        if(che != -1){
            priCoachHour = che;
        }
    } else if(lev_option == 1){
        cout<<"Only intermediate and elite athletes can enter competions\n";
        int che = private_coach();
        if(che != -1){
            priCoachHour = che;
        }
    }else{
        cout<<"Invalid input\n";
    }

    userID[totalUser] = id;
    athleteName[totalUser] = name;
    currentWeight[totalUser] = curWeight;
    privateCoachingHours[totalUser] = priCoachHour;
    plan[totalUser] = trainingPlanName[lev_option-1];
    if(plan[totalUser] == trainingPlanName[0]){
        numberOfCompetition[totalUser] = 0;
        competitionWeight[totalUser] = "";
    } else {
        numberOfCompetition[totalUser] = numOfCompeti;
        competitionWeight[totalUser] = comWeightCat[com_weight-1];
    }
    totalUser++;
    cout << "\nRegistration Completely Done !!!\n ";
    userOutput(lev_option, priCoachHour, com_weight);
    userMenu();
}

float Judo::priceOutput(int pPlan) {
    float fee = 0;
    switch (pPlan) {
        case 1:
            cout << "| Beginner (8 sessions per month)-monthly fee => " << fixed << setprecision(2) << trainingPlanPrice[0]*4 << "$" << endl;
            cout << "| As u are beginner there is no cost for competition " << endl;
            fee = trainingPlanPrice[0] * 4;
            return fee;
        case 2:
            cout<<"| Intermediate (12 sessions per month)-monthly fee => " << fixed << setprecision(2) << trainingPlanPrice[1]*4 << "$" << endl;
            cout<<"| Competition entry fee                            => " << fixed << setprecision(2) << numberOfCompetition[totalUser-1] * trainingPlanPrice[4] << "$" << endl;
            fee = (trainingPlanPrice[1]*4) + (numberOfCompetition[totalUser-1] * trainingPlanPrice[4]);
            return fee;
        case 3:
            cout<<"| Elite (20 sessions per month)-monthly fee => " << fixed << setprecision(2) << trainingPlanPrice[2]*4 << "$" << endl;
            cout<<"| Competition entry fee                     => " << fixed << setprecision(2) << numberOfCompetition[totalUser-1] * trainingPlanPrice[4] << "$" << endl;
            fee = (trainingPlanPrice[2]*4) + (numberOfCompetition[totalUser-1] * trainingPlanPrice[4]);
            return fee;
    }
}

void Judo::userOutput(int lvl, int pHour, int resWeight) {
    cout << "\nThis is output\n################################################################################\n";
    cout << "| Id => " << userID[totalUser-1] << endl;
    cout << "| Athlete name => " << athleteName[totalUser-1] << endl;
    cout << "| ________________________________________________________________________________" << endl;
    cout << "|                   Itemised list of all costs for month" << endl;
    cout << "| ________________________________________________________________________________" << endl;
    float fees = priceOutput(lvl);
    if(pHour != 0){
        cout<<"\n| Private tution per hour                          => " << fixed << setprecision(2)<< pHour * trainingPlanPrice[3] << "$" << endl;
        fees = fees + (pHour * trainingPlanPrice[3]);
    }
    total_fees[totalUser-1] = fees;
    cout << "\n| ###################################################################################";
    cout << "\n";
    cout<<"\n| The total cost of training and competitions for the month => "<< fixed << setprecision(2) << total_fees[totalUser-1] << "$" << endl;
    
    if (lvl != 1) {
        cout << "\nYour current weight        => " << currentWeight[totalUser - 1] << "kg" << endl;
        if(resWeight == 1){
            cout << "\nYour competition weight over  => " << weight_list[resWeight-1] << "kg" << endl;
            cout << "\nYou weight can join competition automatically!!!" << endl;
        } else{
            cout << "\nYour competition weight max limit   => " << weight_list[resWeight-1] << "kg" << endl;
            float resultWeight = weight_list[resWeight-1] - currentWeight[totalUser - 1];
            if (resultWeight > 0){
                cout << "\nYou need to weight gain => " << resultWeight << "kg" << endl;
            } else if (resultWeight < 0){
                cout << "\nYou need to weight loss => " << resultWeight * (-1) << "kg" << endl;
            } else {
                cout << "\nYour weight is ready for competition" << endl;
            }
        }

    }
    cout << "\n******************************************************************************" << endl ;
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
    if (privateCoachingHours[idx] != 0) {
        cout << "Private Coaching Hours => " << privateCoachingHours[idx] << "hrs" << endl;
    }
    if(plan[idx] != trainingPlanName[0]){
        cout << "Number Of Competitions => " << numberOfCompetition[idx] << endl;
        cout << "Competition Weight     => " << competitionWeight[idx] << "kg" << endl;
    }
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
            if (arr[i] == 1){
                cout << "Enter new ID => ";
                cin >> userID[updUserIdx];
            } else if (arr[i] == 2){
                cout << "Enter new name => ";
                cin >> athleteName[updUserIdx];
            } else if (arr[i] == 3){
                int resultPlan = choicePlan();
                plan[updUserIdx] = trainingPlanName[resultPlan-1];
            } else if (arr[i] == 4){
                cout << "Enter new current weight => ";
                cin >> currentWeight[updUserIdx];
            } else if (arr[i] == 5){
                cout << "Enter new Number Of Competitions => ";
                cin >> numberOfCompetition[updUserIdx];
            } else if (arr[i] == 6){
                cout << "Enter new Private Coaching Hours => ";
                cin >> privateCoachingHours[updUserIdx];
            } else if (arr[i] == 7){
                int resComWeight = choiceWeightCat();
                competitionWeight[updUserIdx] = comWeightCat[resComWeight-1];
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
    if (totalUser == 0){
        cout << "\nThere is no user information!!!\n" << endl;
        return;
    }
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
