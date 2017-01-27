#include "util.h"
#include "DictionaryHashtable.h"

/* Create a new Dictionary that uses a Hashset back end */
DictionaryHashtable::DictionaryHashtable(){}

/* Insert a word into the dictionary. */
bool DictionaryHashtable::insert(std::string word)
{
  // Insert returns a pair 
  // We want the bool which is in the second part
  auto in = HASHDict.insert(word);
  return in.second;
}

/* Return true if word is in the dictionary, and false otherwise */
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
