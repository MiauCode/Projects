#include <ctime>
#include <cstdlib>

#include <iostream>
#include <random>

using namespace std;

int main()
{
    while (true){
        string next;
        cin >> next;

        srand(time(NULL));

        int max = 3;
        int min = 1;

        int random;
        random = rand() % (max - min + 1) + min;


        cout << random << endl;
        }
    return 0;
}

/*
#include <iostream>
#include <cstdlib> // For rand() and RAND_MAX
#include <ctime>   // For time()

using namespace std;

// Function to generate a random integer within [min, max]
int generate_random_number(int min, int max) {
    // Generate a random number within the range [0, max-min], then add min
    return rand() % (max - min + 1) + min;
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random number within the range [1, 3]
    int randomNumber = generate_random_number(1, 3);
    cout << "Random number: " << randomNumber << endl;

    return 0;
}
*/
