#include <bits/stdc++.h>
using namespace std;

// Function to print frequency of each word
void printFrequency(string str)
{
	map<string, int> M;
    cout<<"hi"<<endl;
	/// String for storing the words
	string word = "";

	for(int i =0 ; i < str.size();i++)
    {
        str[i] = tolower(str[i]);
    }

    ///to ignore punctuation
    auto it = remove_if(str.begin(), str.end(), ::ispunct);
    str.erase(it, str.end());


	for (int i = 0; i < str.size(); i++) {

		/// Check if current character is blank space then it means we have got one word

		if (str[i] == ' ')
		{
			/// If the current word is not found then insert current word with frequency 1
			if (M.find(word) == M.end())
            {
				M.insert(make_pair(word, 1));
				word = "";
			}

			/// update the frequency
			else
            {
				M[word]++;
				word = "";
			}
		}

		else
        {
			word += str[i];
        }
	}

	/// Storing the last word of the string
	if (M.find(word) == M.end()){
		M.insert(make_pair(word, 1));
	}

	/// Update the frequency
	else{
		M[word]++;
	}

	/// print the frequency
	for (auto& it : M) {
		cout << it.first << " --> "<< it.second << endl;
	}
}

int main()
{
    fstream f1;
    string line;
    cout<<"Enter the file name: ";
    string n; cin>>n;
    f1.open(n+".txt",ios::app);
    cout<<"start writing your text and if you finished press 0: "<<endl;
    string str;
    while(f1)
    {
        getline(cin,line);

        if(line == "0")
            break;

        f1 << line << endl;
        str = line;
    }
    f1.close();

	printFrequency(str);
	return 0;
}


