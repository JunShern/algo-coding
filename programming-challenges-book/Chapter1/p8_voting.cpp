#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
struct candidate {
	string name;
	int votes; // Number of 1st-choice votes
};

struct voter {
	vector<int> choices;
};

void find_winners(vector<int>& winners,
		vector<candidate>& candidates, 
		vector<voter>& voters) {
	// Reset/empty previous votes
	for (int i=0; i<candidates.size(); i++) {
		candidates[i].votes = 0;
	}
	// Reset/empty previous winners
	winners.clear(); 	

	// Count first-choice votes received by each candidate
	for (int i=0; i<voters.size(); i++) {
		for (int j=0; j<voters[i].choices.size(); j++) {
			cout << voters[i].choices[j] << " ";
		}
		cout << endl;
		// Find first non-zero candidate choice
		// (choice==0 means the candidate was deleted)
		int n=0;
		while (voters[i].choices[n]==0) n++; 
		// Increase vote for first choice candidate
		int first_choice = voters[i].choices[n];
		candidates[first_choice-1].votes += 1;
	}

	// Find top and bottom candidate(s)
	int highest_vote = -1;
	int lowest_vote = 2000; // Sufficient, highest possible is 1000
	for (int i=0; i<candidates.size(); i++) {
		// Find highest and lowest votes
		if (candidates[i].votes > highest_vote) {
			highest_vote = candidates[i].votes;
		} else if (candidates[i].votes < lowest_vote) {
			lowest_vote = candidates[i].votes;
		}
	}
	vector<int> weakest;
	for (int i=0; i<candidates.size(); i++) {
		if (candidates[i].votes == highest_vote) {
			cout << "HIGH: " << candidates[i].name << endl;
			winners.push_back(i);
		} else if (candidates[i].votes == lowest_vote) {
			cout << "LOW: " << candidates[i].name << endl;
			weakest.push_back(i);
		}
	}

	// If there are winners, return
	if ((highest_vote > voters.size()/2) // More than 50% of vote?
		|| (highest_vote == lowest_vote)) { // All are tied?
		return;
	} else { // Else, eliminate weakest candidates from voter ballots
		for (int i=0; i<voters.size(); i++) {
			for (int j=0; j<candidates.size(); j++) {
				for (int k=0; k<weakest.size(); k++) {

					if (voters[i].choices[j] == weakest[k]+1) {
						voters[i].choices[j] = 0;
					}
				}
			}
		}
		// Recursive call with updated voters
		find_winners(winners, candidates, voters); 
		return;
	}
		
}
		
		

int main() {

	// Number of cases
	int n_cases;
	cin >> n_cases;

	cout << "Number of cases: " << n_cases << endl;
	// Go through each case
	for (int i=0; i<n_cases; i++) {
		cout << "Case #" << i << endl;
		// Number of candidates
		int n_candidates;
		cin >> n_candidates;
		cout << "Number of candidates: " << n_candidates << endl;
		
		// Candidate names
		vector<candidate> candidates;
		candidate tmp;
		getline(cin, tmp.name); // Finish reading off the \n from the last cin
		for (int j=0; j<n_candidates; j++) {
			getline(cin, tmp.name);
			candidates.push_back(tmp);
			cout << tmp.name << endl;
		}
	
		// Store ballot data
		vector<voter> voters;
		string ballot;
		getline(cin, ballot);
		while (!ballot.empty()) {
			cout << ballot << endl;
			voter tmp_voter;
			// Parse ballot line, save in (voters)
			stringstream ballot_stream(ballot);
			for (int k=0; k<n_candidates; k++) {
				int tmp_choice;
				ballot_stream >> tmp_choice;
				tmp_voter.choices.push_back(tmp_choice);
			}
			voters.push_back(tmp_voter);

			getline(cin, ballot);
		}
		cout << "Done with ballot data!" << endl;

		// Solve
		vector<int> winners;
		find_winners(winners, candidates, voters);

		// Produce output
		for (int l=0; l<winners.size(); l++) {
			int index = winners[l];
			cout << candidates[index].name << endl;
		}
	}

	return 0;
}
