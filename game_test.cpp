#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game_draw.h"
#include "open_the_treasure.h"
using namespace std;

const int numSteps = 20;
const int numTurns = 10;
int position = 0;
int rollDice(){
    return rand() % 6 + 1; //Generate a random number between 1 and 6
}

//check win or lose condition
void winOrLose(int &position, int &turns){
    if(position == numSteps){
        cout << "Congratulations! You have found the treasure!" << endl;
        cout << "It is time to open it" << endl;
            PrintIntro();
            PlayGame();
        std::cout << std::endl << "See you soon!" << std::endl;
    }else if(turns <= 0){
        cout << "Oops! You lose!" << endl;
    }
}

// print turns left
int turnsLeft(int &turns){
    turns--;
    cout << "Your turn(s) left: " << turns << endl;
    return turns;
}

//save the last position
int moves(int &position, int step){
    if(position + step <= numSteps){
        position += step;
    }
    cout << "The character's position: " << position << endl;
    return position;
}

//press enter to roll the dice and print the score
int playerTurn() {
    int step;
    string playerPress;
    do {
        cout << "Press enter to roll the dice: ";
        getline(cin, playerPress);

        if (playerPress.empty()) {
            step = rollDice();
            cout << endl << "Your score: " << step << " point(s)" << endl;
            break;
        }
    } while (!playerPress.empty());
    return step;
}

bool item = false;

// position = 4: trap (further decrease the turns left by 2)
int trap(int turns){
    char choice;
    if(item){
        do{
            cout << "Do you want to use special item? [y/n]" << endl;
            cin >> choice;
            if(choice == 'y'){
                cout << "The character skips the obstacle." << endl;
                item = false;
                break;
            }else if(choice == 'n'){
                cout << "The character is trapped. Your turns are further decreased by 2." << endl;
                turns -= 2;
                cout << "Your turn(s) left: " << turns << endl;
                break;
            }
        }while(choice != 'y' || choice != 'n');
    }else{
        cout << "The character is trapped. Your turns decrease by 2." << endl;
        turns -= 2;
        cout << "Your turn(s) left: " << turns << endl;
    }
    return turns;
}


// position = 13: take 3 steps back
int threeSteps(int &position){
    char choice;
    if(item){
        do{
            cout << "Do you want to use special item? [y/n]" << endl;
            cin >> choice;
            if(choice == 'y'){
                cout << "The character skips the obstacle." << endl;
                item = false;
                break;
            }else if(choice == 'n'){
                cout << "The character moves back 3 steps." << endl;
                position -= 3;
                cout << "The character's position: " << position << endl;
                break;
            }
        }while(choice != 'y' || choice != 'n');
    }else{
        position -= 3;
        cout << "The character move back 3 steps." << endl;
        cout << "The character's position: " << position << endl;
    }
    return position;
}

//position = 19: return to starting point
int returnStartingPoint(int &position){
    char choice;
    if(item){
        do{
            cout << "Do you want to use special item? [y/n]" << endl;
            cin >> choice;
            if(choice == 'y'){
                cout << "The character skips the obstacle." << endl;
                item = false;
                break;
            }else if(choice == 'n'){
                cout << "The character return to the starting point." << endl;
                position = 1;
                cout << "The character's position: " << position << endl;
                break;
            }
        }while(choice != 'y' || choice != 'n');
    }else{
        cout << "The character return to the starting point." << endl;
        position = 1;
        cout << "The character's position: " << position << endl;
    }
    return position;
}

void draw(const int& position){
    switch (position){
    case 0:
        position0();
        break;
    case 1:
        position1();
        break;
    case 2:
        position2();
        break;
    case 3:
        position3();
        break;
    case 4:
        position4();
        break;
    case 5:
        position5();
        break;
    case 6:
        position6();
        break;
    case 7:
        position7();
        break;
    case 8:
        position8();
        break;
    case 9:
        position9();
        break;
    case 10:
        position10();
        break;
    case 11:
        position11();
        break;
    case 12:
        position12();
        break;
    case 13:
        position13();
        break;
    case 14:
        position14();
        break;
    case 15:
        position15();
        break;
    case 16:
        position16();
        break;
    case 17:
        position17();
        break;
    case 18:
        position18();
        break;
    case 19:
        position19();
        break;
    case 20:
        position20();
        break;
    }
}

int main(){
    srand(time(nullptr)); //Seed the random number generator with the current time
    int turns = numTurns;
    draw(position);
    while(position < numSteps){
        int step = playerTurn();
        position = moves(position, step);
        turns = turnsLeft(turns);
        draw(position);
        if(position == 8){
            item = true;
            cout << "You have a special item!" << endl;
        }
        if(position == 4){
            turns = trap(turns);
            draw(position);
        }
        if(position == 13){
            position = threeSteps(position);
            draw(position);
        }
        if(position == 19){
            position = returnStartingPoint(position);
            draw(position);
        }
        cout << endl;
        if(position == numSteps || turns <= 0){
            winOrLose(position, turns);
            break;
        }
    }
    return 0;
}
