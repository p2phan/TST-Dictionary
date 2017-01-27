/**
 *  CSE 100 PA3 C++ Autocomplete
 *  Authors: Jor-el Briones, Christine Alvarado
 *  Edited by Peter Phan A13042904 cs100wdh
 */

#ifndef DICTIONARY_TRIE_H
#define DICTIONARY_TRIE_H

#include <vector>
#include <string>

class TrieNode;
/**
 *  The class for a dictionary ADT, implemented as a trie
 *  You may implement this class as either a mulit-way trie
 *  or a ternary search trie, but you must use one or the other.
 *
 */
class DictionaryTrie
{
public:

  /* Create a new Dictionary that uses a Trie back end */
  DictionaryTrie();

  /* Insert a word with its frequency into the dictionary.
   * Return true if the word was inserted, and false if it
   * was not (i.e. it was already in the dictionary or it was
   * invalid (empty string) */
  bool insert(std::string word, unsigned int freq);

  /* Return true if word is in the dictionary, and false otherwise */
  bool find(std::string word) const;

  /* Return up to num_completions of the most frequent completions
   * of the prefix, such that the completions are words in the dictionary.
   * These completions should be listed from most frequent to least.
   * If there are fewer than num_completions legal completions, this
   * function returns a vector with as many completions as possible.
   * If no completions exist, then the function returns a vector of size 0.
   * The prefix itself might be included in the returned words if the prefix
   * is a word (and is among the num_completions most frequent completions
   * of the prefix)
   */
  std::vector<std::string>
  predictCompletions(std::string prefix, unsigned int num_completions);

  /* Destructor */
  ~DictionaryTrie();

private:
  // Add your own data members and methods here
  //This will be the root of the ternary tree
  TrieNode* root;
  TrieNode* traverseTrie(TrieNode* get, char c) const;
  TrieNode* addNode(std::string word, int i, unsigned int freq);
  static void deleteAll(TrieNode* n);
};

class TrieNode
{
public:
  /** default constructor 
   *  Node's default is false and set Char
   */
  TrieNode(const char c) : mid(nullptr), left(nullptr),
                           right(nullptr), letter(c),
                           isWord(false), freq(0){}
   
  //the three nodes are part of the structure of the ternary search tree
  TrieNode* mid; 
  TrieNode* left;
  TrieNode* right;  
  char const letter; // this will hold the letter of the word
  bool isWord; 
  unsigned int freq;
};


#endif // DICTIONARY_TRIE_H
