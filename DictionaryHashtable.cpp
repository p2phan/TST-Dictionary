#include "util.h"
#include "DictionaryHashtable.h"

/**
 *  File: DictionaryHashtable.cpp
 *  
 *  Purpose: Implements a hashtable using an unordered set
 *
 *  CSE 100 PA3 C++ Autocomplete
 *  Authors: Jor-el Briones, Christine Alvarado
 *  Peter Phan, cs100wdh, A13042904
 *
 */

/* Create a new Dictionary that uses a Hashset back end */
DictionaryHashtable::DictionaryHashtable(){}

/* Insert a word into the dictionary. 
 *
 * Parameters: 
 *             word: string to insert to hashtable
 * */
bool DictionaryHashtable::insert(std::string word)
{
  // Insert returns a pair 
  // We want the bool which is in the second part
  auto in = HASHDict.insert(word);
  return in.second;
}

/* Return true if word is in the dictionary, and false otherwise 
 *
 * Parameter:
 *           word: word to find in hashtable
 *
 */
bool DictionaryHashtable::find(std::string word) const
{
  auto get = HASHDict.find(word);

  // If the find returns an iterator out of bounds
  // or if the word returned is not what we want
  // we return false
  if(get == HASHDict.end() || *get != word){
    return false;
  }

  return true;
}

/* Destructor */
DictionaryHashtable::~DictionaryHashtable(){}
