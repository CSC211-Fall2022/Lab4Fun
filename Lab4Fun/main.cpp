#include <iostream>
#include <iomanip>
using namespace std;

void rollDice(int&, int&, int&);

int point = 0;
int d1, d2, sum;

int main() {
    
    srand(time(0));
    bool play;
    int win{0}, lose{0};
    
    
    for (int i = 0; i < 10000; i++){
        
        play = true;
        while (play){
            
            play = false;
            rollDice(d1, d2, sum);
            
            cout << "You rolled a " << d1 << " and a " << d2 << "... " << sum << endl;
            
            if (((sum == 7 || sum == 1) && point == 0) || sum == point){
                cout << "You win!" << endl;
                win++;
            } else if (sum == 2 || sum == 3 || sum == 12){
                cout << "Craps! You lose!" << endl;
                lose++;
            } else if (sum == 7){
                cout << "You rolled a 7... Game over!" << endl;
                lose++;
            } else {
                point = sum;
                cout << "Point: " << point << endl << endl << endl;
                play = true;
            }
        
        }
        
    }
    
    
    cout << "\nWins: " << win << '\n' << "Losses: " << lose << endl;
    cout << fixed << setprecision(2);
    cout << "Probability of winning: " << (static_cast<double>(win) / (win + lose))*100 << '%' << endl;
        
    cout << endl << endl;
    return 0;
}

void rollDice(int&, int&, int&){
    
    d1 = rand() % 6 + 1;
    d2 = rand() % 6 + 1;
    sum = d1 + d2;
    
}
