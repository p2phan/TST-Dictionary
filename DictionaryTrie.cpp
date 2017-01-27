#include "util.h"
#include "DictionaryTrie.h"

/* Create a new Dictionary that uses a Trie back end */
DictionaryTrie::DictionaryTrie(){ root=nullptr;}


TrieNode* DictionaryTrie::traverseTrie(TrieNode* get, char c) const
{
  
  TrieNode* curr = get;
  while(curr->mid){
    TrieNode* temp = curr;
    if(c < curr->letter){
       curr = curr->left;
    }

    else if( curr->letter < c){
      curr = curr->right;
    }

    else {
      return curr;
    }
    
    if(curr==NULL){
      curr = temp;
      break;
    }
  }
  return curr;
}

TrieNode* DictionaryTrie::addNode(std::string word, int i,
                                  unsigned int freq){
  char c = word[i];
  TrieNode* begin = new TrieNode(c);
  TrieNode* add = begin;
  i++;
  for( ;i<word.length(); i++){
    char c = word[i];
    add->mid = new TrieNode(c);
    add = add->mid;
  }
  
  add->freq = freq;
  add->isWord = true;
  return begin;
  

}
/* Insert a word with its frequency into the dictionary.
 * Return true if the word was inserted, and false if it
 * was not (i.e. it was already in the dictionary or it was
 * invalid (empty string) */
bool DictionaryTrie::insert(std::string word, unsigned int freq)
{
  if(root==NULL){
    root = addNode(word, 0, freq); 
    return true; 
  }

  TrieNode* curr = root;
  char c;

  for(int i = 0; i<word.length(); i++ ) {
    c =  word[i];
    TrieNode* check = traverseTrie(curr, c);
    if(c < check->letter){
      if(check->left){
        curr = check->left;
      }
      else{
        check->left = addNode( word, i, freq);
        return true; 
      }
    }

    else if(check->letter < c) {
      if(check->right){
        curr = check->right;
      }
      else {
        check->right = addNode(word, i, freq);
        return true;
      }

    }
    else {
      if(i == word.length()-1) {
        curr = check;
        break;
      }
       else if(check->mid){
        curr = check->mid;
      }
      else{
        check->mid = addNode( word, i+1, freq); 
        return true;
      }
    }
  } 


  if(curr->isWord){
    curr->freq = freq;
    return false;
  }

    curr->isWord = true;
    
      
  

  return true;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryTrie::find(std::string word) const
{
  if(!root){ return false;}

  TrieNode* curr = root;
  char c;

  for(int i = 0; i < word.length() ; i++)
  {
    c = word[i];
    TrieNode* check = traverseTrie(curr, c);
    if(c < check->letter) {
      curr = check->left;
    }
   
    else if (check->letter < c) {
      curr = check->right;    
    }

    else {
      if(i == word.length()-1) {
        curr = check;
        break;
      }
      curr = check->mid;

    }
    
    if(!curr){ return false;}
  } 

  return curr->isWord;
}

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
std::vector<std::string> DictionaryTrie::predictCompletions(std::string prefix, unsigned int num_completions)
{
  std::vector<std::string> words;
  return words;
}

void DictionaryTrie::deleteAll(TrieNode* n)
{
  if(!n){ return; }
  
  deleteAll(n->left);
  deleteAll(n->mid);
  deleteAll(n->right);

  delete n;

}
/* Destructor */
DictionaryTrie::~DictionaryTrie(){ deleteAll(root);}



