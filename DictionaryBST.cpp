#include "util.h"
#include "DictionaryBST.h"

/* Create a new Dictionary that uses a BST back end */
DictionaryBST::DictionaryBST(){
}


/* Insert a word into the dictionary. 
 * 
 * Parameters: 
 *           word: word to insert to BST
 * */
bool DictionaryBST::insert(std::string word)
{
  // Insert returns a pair, the second value is bool
  // So we return that
  auto in = BSTDict.insert(word);
  return in.second;
}

/* Return true if word is in the dictionary, and false otherwise 
 *
 * Parameters:
 *           word: string to find in BST
 * */
bool DictionaryBST::find(std::string word) const
{
  std::set<std::string>::iterator get = BSTDict.find(word);
  // If the iterator return what is not the word or
  // If it reaches out of Bounds then it is false
  if(get==BSTDict.end() || *get != word){
    return false;
  }
  
  return true;

}

/* Destructor */
DictionaryBST::~DictionaryBST(){/* delete BSTDict;*/ }
