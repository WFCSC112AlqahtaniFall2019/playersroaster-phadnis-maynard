#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Player {
  /*your code here*/
  string playerName;
  int playerJersey;
  int playerRating;
};

void initialize(vector<Player>& v);
void output(const vector<Player>& v);
void addPlayer(vector<Player>& v, Player player1);
void deletePlayer(vector<Player>& v, int playerNumber);
void updateRating(vector<Player>& v);
void aboveRating(const vector<Player>& v);

int main() {

    vector<Player> playerList(5);
    vector<string> Names(5);
    vector<int> jerseyNums(5);
    vector<int> ratingNums(5);

    unsigned int i;
    string playerName;
    int playerJersey;
    int playerRating;
    char menuOp;
    Player player1;

    //initialize the roasters
    cout << "ROSTER:" << endl;
    initialize(playerList);

    //output
    /*cout << "ROSTER" << endl;
    for (i = 0; i < jerseyNums.size(); ++i) {
        cout << "Player " << i + 1 << " -- Name: " <<Names.at(i)<<" -- Jersey number: "
             << jerseyNums.at(i) << ", Rating: " << ratingNums.at(i) << endl;
    }
    cout << endl; */

    do {
        cout << "MENU" << endl;
        cout << "a - Add player" << endl;
        cout << "d - Remove player" << endl;
        cout << "u - Update player rating" << endl;
        cout << "r - Output players above a rating" << endl;
        cout << "o - Output roster" << endl;
        cout << "q - Quit" << endl << endl;

        cout << "Choose an option:" << endl;
        cin >> menuOp;

        //Add
        if (menuOp == 'a') {
            /*cout << "Enter a new player's jersey number:" << endl;
            cin >> playerJersy;
            jerseyNums.push_back(playerJersy);


            cout << "Enter the player's rating:" << endl;
            cin >> playerRating;
            ratingNums.push_back(playerRating);
            cout << endl;*/

            addPlayer(playerList, player1);
        }

            //Delete
        else if (menuOp == 'd') {
            /*
            cout << "Enter a jersey number:" << endl;
            cin >> playerJersy;
            //find the player using her/his jersey number
            for (i = 0; i < jerseyNums.size(); ++i) {
                if (playerJersy == jerseyNums.at(i)) {
                    playerJersy = i;
                }
            }
            //shift the vectors' elements up to remove the element
            for (i = 0; i < jerseyNums.size() - 1; ++i) {
                if (i >= playerJersy) {
                    Names.at(i) = Names.at(i + 1);
                    jerseyNums.at(i) = jerseyNums.at(i + 1);
                    ratingNums.at(i) = ratingNums.at(i + 1);
                }
            }
            Names.pop_back();
            jerseyNums.pop_back();
            ratingNums.pop_back();
            cout << endl;
            */
        deletePlayer(playerList, playerJersey);
        }

            //Update
        else if (menuOp == 'u') {
            /*
            cout << "Enter a jersey number:" << endl;
            cin >> playerJersy;

            cout << "Enter a new rating for player:" << endl;
            cin >> playerRating;

            for (i = 0; i < jerseyNums.size(); ++i) {
                if (jerseyNums.at(i) == playerJersy) {
                    ratingNums.at(i) = playerRating;
                }
            }
            cout << endl;
             */
            updateRating(playerList);
        }

            // > Rating
        else if (menuOp == 'r') {
            /*
            cout << "Enter a rating:" << endl;
            cin >> playerRating;
            cout << endl;

            cout << "ABOVE " << playerRating << endl;
            for (i = 0; i < jerseyNums.size(); ++i) {
                if (ratingNums.at(i) > playerRating) {
                    cout << "Player " << i + 1 << " -- Jersey number: "
                         << jerseyNums.at(i) << ", Rating: "
                         << ratingNums.at(i) << endl;
                }
            }
            cout << endl;
             */
            aboveRating(playerList);
        }

        //output
        else if (menuOp == 'o') {
            /*
            cout << "ROSTER" << endl;
            for (i = 0; i < jerseyNums.size(); ++i) {
                cout << "Player " << i + 1 << " -- Name: " <<Names.at(i)<<" -- Jersey number: "
                     << jerseyNums.at(i) << ", Rating: " << ratingNums.at(i) << endl;
            }
            cout << endl;
             */
            output(playerList);
        }

    } while(menuOp != 'q');

    return 0;
}

void initialize(vector<Player>& v)
{
    for (int i = 0; i < v.size(); ++i) {

        cout << "Enter player " << i + 1 << "'s name:" << endl;
        cin >> v.at(i).playerName;

        cout << "Enter player " << i + 1 << "'s jersey number:" << endl;
        cin >> v.at(i).playerJersey;

        cout << "Enter player " << i + 1 << "'s rating:" << endl;
        cin >> v.at(i).playerRating;
        cout << endl;
    }
}

void addPlayer(vector <Player>& v, Player player)
{
    //add
    string playerName;
    int playerJersey;
    int playerRating;
    cout << "Enter a new player's name: " << endl;
    cin >> playerName;
    player.playerName = playerName;
    cout << "Enter a new player's jersey number:" << endl;
    cin >> playerJersey;
    player.playerJersey = playerJersey;
    cout << "Enter the player's rating:" << endl;
    cin >> playerRating;
    player.playerRating = playerRating;

    v.push_back(player);
    cout << endl;
}

void deletePlayer(vector<Player>& v, int playerNumber) {
    //delete
    cout << "Enter a jersey number:" << endl;
    cin >> playerNumber;
    //find the player using her/his jersey number
    for (int i = 0; i < v.size(); ++i) {
        if (playerNumber == v.at(i).playerJersey) {
            playerNumber = i;
        }
    }
    //shift the vectors' elements up to remove the element
    for (int i = 0; i < v.size() - 1; ++i) {
        if (i >= playerNumber) {
            v.at(i).playerName = v.at(i + 1).playerName;
            v.at(i).playerJersey = v.at(i + 1).playerJersey;
            v.at(i).playerRating = v.at(i + 1).playerRating;
        }
    }
    v.pop_back();
    cout << endl;
}

void updateRating(vector<Player>& v)
{
    int playerNumber;
    int rating;
    //update
    cout << "Enter a jersey number:" << endl;
    cin >> playerNumber;

    cout << "Enter a new rating for player:" << endl;
    cin >> rating;

    for (int i = 0; i < v.size(); ++i) {
        if (v.at(i).playerJersey == playerNumber) {
            v.at(i).playerRating = rating;
        }
    }
    cout << endl;
}

void aboveRating(const vector<Player>& v)
{
    //rating
    int rating;
    cout << "Enter a rating:" << endl;
    cin >> rating;
    cout << endl;

    cout << "ABOVE " << rating << endl;
    for (int i = 0; i < v.size(); ++i) {
        if (v.at(i).playerRating > rating) {
            cout << "Player " << i + 1 << " -- Jersey number: "
                 << v.at(i).playerJersey << ", Rating: "
                 << v.at(i).playerRating << endl;
        }
    }
    cout << endl;
}

void output(const vector<Player>& v)
{
    cout << "ROSTER" << endl;
    for (int i = 0; i < v.size(); ++i) {
        cout << "Player " << i + 1 << " -- Name: " <<v.at(i).playerName<<" -- Jersey number: "
             << v.at(i).playerJersey << ", Rating: " << v.at(i).playerRating << endl;
    }
    cout << endl;
}