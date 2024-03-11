#include <iostream>
#include <ctime>
#include <cstdlib>
#include <set>
#include <cctype>

using namespace std;

string WIN = "> You win! New game?: Yes (Y) No (N)";
string LOSE = "> You lost... Rematch?: Yes (Y) No (N)";
string WRONG_INPUT = "Incorrect input";

bool input_cheker(char input){

    input = tolower(input);

    set<char> inputs = {'r', 's', 'p', 'y', 'n'};
    if (inputs.find(input) == inputs.end() ){
        return false;
    }
    return true;
}

char generate_random_hand(){




    //Generating the ranfom number for deciding the opponents hand
    srand(time(NULL));
    int max = 3;
    int min = 1;

    int number;
    number = rand() % (max - min + 1) + min;




    //Choosing the right path to return the correct hand
    if (number == 1){
        return 'r';
    }
    else if (number == 2){
        return 'p';
    }
    else{
        return 'p';
    }


}

int main()
{

    while (true){

        cout << "> Choose your hand Rock (R), Paper (P), Scissors (S): " << endl;

        char hand;



        while (true){


            cout << "> ";
            cin >> hand;
            cout << endl;

            if (!input_cheker(hand)){
                cout << WRONG_INPUT << endl << endl << "> ";
            }
            else{
                break;
            }
        }

        char opponent_hand;
        opponent_hand = generate_random_hand();


        if ((hand == 'p' && opponent_hand == 'r') || (hand == 's' && opponent_hand == 'p')
            || (hand == 'r' && opponent_hand == 's')){

            cout << WIN << endl << "> ";

        }

        else{
            cout << LOSE << endl << "> ";
        }



        while (bool flag = true){

            char rematch;
            cin >> rematch;
            cout << endl;

            if (input_cheker(rematch)){
                if (rematch == 'n'){
                    cout << "> See you later fighter.";
                    return 0;
                }
                else if(rematch == 'y'){
                    break;
                }
            }
            else{
                cout << WRONG_INPUT << endl << endl << "> ";
            }
        }
    }
}
