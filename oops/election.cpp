#include <iostream>
using namespace std;

int main(){
    const int NUM_CANDIDATES = 5;
    int count[NUM_CANDIDATES+1] = {0};
    int spoiltBallots = 0;
    int vote;
    int TotalNotes;
    int total_votes;

    cout << "Enter total number of votes:";
    cin >> total_votes;

    cout << "Enter candidate number for each vote";

    for(int i = 1; i <= total_votes; i++)
    {
        cout << "vote " << i << ": ";
        cin >> vote;

        if (vote >= 1 && vote <= NUM_CANDIDATES)
        {
            count[vote]++;
        }
        else
        {
            spoiltBallots++;
        }
    }

    cout << "\n_Election result_\n";

    for(int i = 1; i <= NUM_CANDIDATES; i++)
    {
        cout << "\nCandidate " << i << " received " << count[i] << " votes\n";
    }

    cout << "NUMBER OF SPOILT Ballot: " << spoiltBallots << endl;

    return 0;
}
