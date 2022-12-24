// Copyright (c) 2022 Immaculata HS All rights reserved.
//
// Created by: Joseph Kwon
// Created on: December 21 2022
// This program asks the user for sentences and
// translates them to pig latin, frames them, and shuffles the words

#include <iostream>
#include <list>
#include <algorithm>  // for std::shuffle
#include <random>  // for std::random_device and std::mt19937
#include <string>


// Translate a word to Pig Latin
std::string translate_word(const std::string& word) {
    // Take the first letter of the word and move it to the end
    char first_letter = word[0];
    std::string translated_word = word.substr(1) + first_letter;
    // Add "ay" to the end of the word
    translated_word += "ay";
    return translated_word;
}

// Split a string into a list of words
std::list<std::string> split(const std::string& str) {
    std::list<std::string> words;  // List to store the words
    // Temporary string to store the current word being built
    std::string word;
    // Iterate over the characters in the string
    for (char words5 : str) {
        // If the character is a space,
        // add the current word to the list and reset it
        if (words5 == ' ') {
            words.push_back(word);
            word.clear();
        } else {  // Otherwise, add the character to the current word
            word += words5;
        }
    }
    if (!word.empty()) {  // If there is a remaining word, add it to the list
        words.push_back(word);
    }
    return words;
}

// Frame a list of strings
std::list<std::string> frame(const std::list<std::string>& lst) {
    // Find the longest string in the list,
    // this will be used to calculate the width of the frame border
    size_t max_len = 0;
    for (const std::string& string : lst) {
        for (const std::string& word : split(string)) {
            // Update the maximum length if the current word is longer
            max_len = std::max(max_len, word.length());
        }
    }

    // Create the top and bottom border of the frame using the maximum length
    std::string border(max_len + 4, '*');

    // Create the framed list
    std::list<std::string> framed_list;
    framed_list.push_back(border);  // Add the top border
    for (const std::string& string : lst) {
        for (const std::string& word : split(string)) {
            // Add the framed version of the current word to the list
            std::string framed_string = "* " + word + " *";
            size_t num_spaces = max_len - word.length();
            framed_list.push_back(framed_string);
        }
    }
    framed_list.push_back(border);  // Add the bottom border

    return framed_list;
}

int main() {
    std::cout << "Pig Latin Program:\n";
    std::cout << "Enter a string: ";

    // Read the string from the user
    std::string input_string;
    std::getline(std::cin, input_string);

    // Split the string into a list of words
    std::string words[100];  // initialize an array to hold up to 100 words
    std::string word;
    int word_count = 0;
    for (char words5 : input_string) {
        // If the character is a space,
        // add the current word to the array of words
        // and reset the current word
        if (words5 == ' ') {
            words[word_count] = word;
            word.clear();
            ++word_count;
        } else {
            // Otherwise, add the character to the current word
            word += words5;
        }
    }
    // If there is a remaining word after the loop, add it to the array of words
    if (!word.empty()) {
        words[word_count] = word;
        ++word_count;
    }

    // Translate the words to Pig Latin
    // initialize an array to hold the translated words
    std::string translated_words[100];
    for (int i = 0; i < word_count; ++i) {
        translated_words[i] = translate_word(words[i]);
    }

    // Print the translated words
    std::cout << "The translated words are: ";
    for (int i = 0; i < word_count; ++i) {
        std::cout << translated_words[i];
        // Only add a space after the word
        // if it is not the last word in the string
        if (i != word_count - 1) {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;

    // Next program, inform the user
    std::cout << "\nRectangular Frame Program:\n";
    std::cout << "Enter a sentence to be framed: ";
    std::list<std::string> lst;
    std::string string;
    while (std::getline(std::cin, string)) {
        if (string.empty()) {
            break;
        }
        lst.push_back(string);
    }

    // Frame the list of strings
    std::list<std::string> framed_list = frame(lst);

    // Print the framed list
    std::cout << "The framed list is:" << std::endl;
    for (const std::string& string : framed_list) {
        std::cout << string << std::endl;
    }

    // Next program, inform the user
    std::cout << "\nSentence Mixer Program";
    std::cout << "\nPS: I came up with this ";
    std::cout << "program idea (not on the problem list)";
    // Prompt the user to enter a sentence
    std::cout << "\nEnter a sentence: ";

    // Read the sentence from the user
    std::string sentence;
    std::getline(std::cin, sentence);

    // Split the sentence into a list of words and store the words in an array
    std::string words3[100];  // initialize an array to hold up to 100 words
    std::string word3;
    int word_count3 = 0;
    for (char words4 : sentence) {
        // If the character is a space,
        // add the current word to the array of words
        // and reset the current word
        if (words4 == ' ') {
            words3[word_count3] = word3;
            word3.clear();
            ++word_count3;
        } else {
            // Otherwise, add the character to the current word
            word3 += words4;
        }
    }
    // If there is a remaining word after the loop, add it to the array of words
    if (!word3.empty()) {
        words3[word_count3] = word3;
        ++word_count3;
    }

    // Shuffle the array of words
    // random device to seed the random number generator
    std::random_device rd;
    std::mt19937 g(rd());                        // random number generator
    std::shuffle(words3, words3 + word_count3, g);  // shuffle the words

    // Print the shuffled sentence
    std::cout << "The shuffled sentence is: ";
    for (int i = 0; i < word_count3; ++i) {
        std::cout << words3[i];
        // Only add a space after the word if
        // it is not the last word in the sentence
        if (i != word_count3 - 1) {
            std::cout << ' ';
        }
    }
    std::cout << std::endl;

    std::cout << "\nThank you for playing";

    // Within the main body, do not place the following after each function
    return 0;
}
