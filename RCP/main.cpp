#include <iostream>
#include <ctime>
#include <cstdlib>
#include <set>
#include <cctype>


using namespace std;

string WIN = "> You win! New game?: Yes (Y) No (N)";
string LOSE = "> You lost... Rematch?: Yes (Y) No (N)";
string TIE = "> It's a tie! Rematch?: Yes (Y) No (N)";
string WRONG_INPUT = "Incorrect input";

void to_lower(string& input){


    for (char& i : input){
        i = tolower(i);
    }

}

void get_results(string player, string bot){

    //Cheking if the player has won
    if ((player == "p" && bot == "r") ||
        (player == "s" && bot == "p") ||
        (player == "r" && bot == "s") ){

        cout << WIN << endl << "> ";
    }

    //Cheking if the results are a tie
    else if ((player == "p" && bot == "p") ||
            (player == "s" && bot == "s") ||
             (player == "r" && bot == "r") ){

        cout << TIE << endl << "> ";
    }

    //The player has lost
    else{
        cout << LOSE << endl << "> ";
    }

}


bool input_cheker(string input, int type){

    to_lower(input);

    set<string> inputs = {"r", "s", "p"};
    set<string> rematch_inputs = {"y", "n"};

    if (type == 1){
        if (inputs.find(input) == inputs.end() ){
            return false;
        }
        return true;
    }
    else{
        if (rematch_inputs.find(input) == inputs.end() ){
            return false;
        }
        else{
            //cout << input << " chekkaa tää" << endl;
            return true;
        }


    }


}


string generate_random_hand() {
    srand(time(NULL));
    int max = 3;
    int min = 1;

    int number = rand() % (max - min + 1) + min;

    if (number == 1) {
        return "r";
    }
    else if (number == 2) {
        return "p";
    }
    else {
        return "s";
    }
}

string get_players_choice(){
    while (true){

        //Players hand
        string hand;

        cout << "> ";
        getline(cin, hand);
        cout << endl;

        if (!input_cheker(hand, 1)){
            cout << WRONG_INPUT << endl << endl << "> ";
        }
        else{
            return hand;
        }
    }
}

bool ask_rematch(){

    while (bool flag = true){

        string rematch;
        getline(cin, rematch);
        cout << endl;

        if (input_cheker(rematch, 2)){
            if (rematch == "n"){
                cout << "> See you later fighter.";
                return false;
            }
            else if(rematch == "y"){
                return true;
            }
        }
        else{
            cout << WRONG_INPUT << endl << endl << "> ";
        }
    }
    return true;
}


int main()
{

    while (true){

        cin.clear();
        cout << "> Choose your hand Rock (R), Paper (P), Scissors (S): " << endl;




        string players_hand = get_players_choice();
        string bot_hand = generate_random_hand();

        get_results(players_hand, bot_hand);

        if (!ask_rematch()){
            return 0;
        }



    }
}
