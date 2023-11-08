#include <bits/stdc++.h>

using namespace std;

// Function to trim leading whitespaces from a string
string ltrim(const string &);

// Function to trim trailing whitespaces from a string
string rtrim(const string &);

// Function to split a string by spaces and return a vector of tokens
vector<string> split(const string &);

/*
 * Complete the 'simpleArraySum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY ar as a parameter.
 */
int simpleArraySum(vector<int> ar) {
    // Initialize the sum
    int sum = 0;

    // Loop through the array and accumulate the sum
    for (int i : ar) {
        sum += i;
    }

    // Return the calculated sum
    return sum;
}

int main() {
    // Open a file for output
    ofstream fout(getenv("OUTPUT_PATH"));

    // Input: number of elements in the array
    string ar_count_temp;
    getline(cin, ar_count_temp);

    // Convert string to integer
    int ar_count = stoi(ltrim(rtrim(ar_count_temp)));

    // Input: array elements as space-separated string
    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    // Split the string into a vector of strings representing array elements
    vector<string> ar_temp = split(rtrim(ar_temp_temp));

    // Convert vector of strings to vector of integers
    vector<int> ar(ar_count);
    for (int i = 0; i < ar_count; i++) {
        int ar_item = stoi(ar_temp[i]);
        ar[i] = ar_item;
    }

    // Call the function to calculate the sum of array elements
    int result = simpleArraySum(ar);

    // Output the result to the file
    fout << result << "\n";

    // Close the output file
    fout.close();

    return 0;
}

// Function to trim leading whitespaces from a string
string ltrim(const string &str) {
    string s(str);

    // Erase leading whitespaces using find_if and not1
    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

// Function to trim trailing whitespaces from a string
string rtrim(const string &str) {
    string s(str);

    // Erase trailing whitespaces using find_if and not1
    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

// Function to split a string by spaces and return a vector of tokens
vector<string> split(const string &str) {
    vector<string> tokens;

    // Initialize start and end indices for token extraction
    string::size_type start = 0;
    string::size_type end = 0;

    // Extract tokens separated by spaces
    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }

    // Add the last token
    tokens.push_back(str.substr(start));

    return tokens;
}
