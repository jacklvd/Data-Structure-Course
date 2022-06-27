#ifndef WORDS
#define WORDS
#include <string>
#include <iostream>
using namespace std;

class Words {

	protected:
		string data;
		int wordCounts;

	public:
		// constructors
		Words() {

			data = "";
			wordCounts = 1;
		}

		Words(string input) {

			data = input;
			wordCounts = 1;
		}

		bool operator ==(const Words& obj) {
			return this->data.compare(obj.data) == 0;
		}

		bool operator <(const Words& obj) {
			return this->data.compare(obj.data) < 0;
		}

		bool operator >(const Words& obj) {
			return this->data.compare(obj.data) > 0;
		}

		bool operator >=(const Words& obj) {
			return this->data.compare(obj.data) >= 0;
		}

		bool operator <=(const Words& obj) {
			return this->data.compare(obj.data) <= 0;
		}

		friend ostream& operator <<(ostream& os, const Words& obj) {
			os << obj.data << ": " << obj.wordCounts;
			return os;
		}

		string getWords() { return data; }

		void setWords(string input) { data = input; }

		int getWordsNum() { return wordCounts; }

		void increaseWords() { wordCounts++; }
};

#endif