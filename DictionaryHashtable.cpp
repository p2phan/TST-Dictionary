#include "util.h"
#include "DictionaryHashtable.h"

/* Create a new Dictionary that uses a Hashset back end */
DictionaryHashtable::DictionaryHashtable(){}

/* Insert a word into the dictionary. */
bool DictionaryHashtable::insert(std::string word)
{
  auto in = HASHDict.insert(word);
  return in.second;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryHashtable::find(std::string word) const
{
  auto got = HASHDict.find(word);
  if(*got==word){
    return true;
  }

  return false;
}

/* Destructor */
DictionaryHashtable::~DictionaryHashtable(){}
