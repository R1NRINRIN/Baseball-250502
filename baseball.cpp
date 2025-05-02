#include <stdexcept>

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question)
		: question(question) {
	}

	bool isDuplicatedNumber(const string& guessNumber) {
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}

	void assertIllegalArgument(const string& guessNumber) {
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters.");
		}

		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			throw invalid_argument("Must be number.");

		}

		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number.");
		}
	}

	int countStrike(const string& guessNumber) {
		int cnt = 0;
		for (int i = 0; i < 3; ++i) {
			if (question[i] == guessNumber[i]) cnt += 1;
		}
		return cnt;
	}

	GuessResult guess(const string& guessNumber) {
		GuessResult rst = { false, 2, 0 };
		assertIllegalArgument(guessNumber);
		if (guessNumber == question) {
			return { true, 3, 0 };
		}
		rst.strikes = countStrike(guessNumber);
		return rst;
	}

private:
	string question;
};