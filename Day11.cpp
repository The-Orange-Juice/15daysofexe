#include <bits/stdc++.h>
using namespace std;
vector<char> chosen;
void printchosen(){
	cout<<"Your chosen letters: ";
	for(int i=0;i<chosen.size();i++){
		cout<<chosen[i];
		if(i<chosen.size()-1)cout<<", ";
	}
}
struct RandomGenerator{
	RandomGenerator(const size_t min, const size_t max) : dist(min, max) {}
	random_device rd;
	uniform_int_distribution<size_t> dist;
	unsigned operator()() { return dist(rd); }
};
struct Gallow {
	void Draw() const{
		printf(" ________\n"
		            "|        |\n"
			    "|       %c %c\n"
			    "|       %c%c%c\n"
			    "|       %c %c\n"
			    "|\n"
			    "|\n", body[0], body[1], body[2], body[3],
		            body[4], body[5], body[6]);
	}
	bool Increment(){
		switch (++errors){
			case 6: body[6] = '\\'; break;
			case 5: body[5] = '/'; break;
			case 4: body[4] = '\\'; break;
			case 3: body[3] = '|'; break;
			case 2: body[2] = '/'; break;
			case 1: body[0] = '(', body[1] = ')'; break;
		}
		return errors < 6;
	}
	char body[7] { '\0' };
	int errors { 0 };
};
struct Game {
	void Draw() const{
		#ifdef _WIN32
		system("cls");
		#else
		system("clear");
		#endif	
		gallow.Draw();
		for_each(guess.begin(), guess.end(), [](const char c) { printf("%c ", c); });
		putchar('\n');
	}
	bool Update(){
		printchosen();
		cout<<"\n";
		printf("Enter a letter: ");
		const char letter = tolower(getchar());
		while(getchar()!='\n'){}
		bool found = false;
		for (size_t i = 0; i < word.size(); ++i) {
			if (word[i] == letter) {
				guess[i] = letter;
				found = true;
				chosen.push_back(letter);
			}
		}
		const auto end_game = [this](const char* msg) {
			Draw();
			puts(msg);
			return false;
		};
		if (not found and not gallow.Increment()) return end_game("You lose! Try again.");
		else if (found and word == guess) return end_game("You win! Hint for today is: Score a loo!");
		return true;
	}

	RandomGenerator rand_gen { 0, words.size() - 1 };
	const string word { words[rand_gen()] };
	string guess { string().insert(0, word.size(), '_') };
	Gallow gallow;
	static const array<const string, 100> words;
};
const array<const string, 100> Game::words{"motorcycle"," pie"," health"," fresh"," curve"," record"," decline"," despair"," priority"," culture","user","play","password","publication","route","contradiction","enhance","popular","civilization","dough","shave","meaning","even","soar","monstrous","brain","senior","transition","entitlement","part","berry","want","widen","limit","spine","get","sculpture","teacher","personal","woman","taste","corpse","distance","lock","school","cause","baseball","deficit","perception","injury","strict","ensure","legislature","employee","indirect","roar","archive","voter","stumble","noble","meat","salt","partner","wound","hostile","lesson","raid","predict","bathtub","seller","impulse","polish","knee","position","launch","personality","quote","determine","grass","diamond","offense","dark","freshman","century","alive","sport","reflection","sausage","sum","spend","dimension","offer","plug","discreet","spread","cherry","approach","gravel","flourish"};
int main(){
	Game game;
	do {
		game.Draw();
	} while (game.Update());
	return EXIT_SUCCESS;
}
