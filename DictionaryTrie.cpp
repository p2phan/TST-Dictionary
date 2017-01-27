#include "util.h"
#include "DictionaryTrie.h"

/* Create a new Dictionary that uses a Trie back end */
DictionaryTrie::DictionaryTrie(){ root=nullptr;}

/** Helper function for insert and find 
 *  that will traverse the tree until either the node 
 *  matches the letter or everything else is null
 *  Return the node with either the same char
 *  or the node in which it's supposed to go
 *  left or right but they are null
 *  
 *  Parameters:
 *        get: this is the node to search through
 *        c: this is the char that we are looking through
 *        the nodes for
 *     
 */
TrieNode* DictionaryTrie::traverseTrie(TrieNode* get, char c) const
{
  
  
  TrieNode* curr = get;
  // We check condition of mid because we don't want to step in yet
  while(curr->mid){
    TrieNode* temp = curr;

    //if and else if updates based on comparision to c
    if(c < curr->letter){
       curr = curr->left;
    }

    else if( curr->letter < c){
      curr = curr->right;
    }

    // If the data is equal to c we are at the node we want
    // and we return it
    else {
      return curr;
    }
    
    // When updating makes curr null we will go back    
    if(curr==NULL){
      curr = temp;
      break;
    }
  }

  //we are at the node we want so we return it
  return curr;
}

/** Helper function for insert 
 *  
 *  Returns the beginning of added subtrie
 *
 *  Parameter:
 *      word: word to made nodes out of
 *      i: position from which to start makin a node chain
 *      freq: frequency to update end of chain
 *
 *  Effect: returns a chain of Nodes from char of the string
 *  from i to the end 
 */

TrieNode* DictionaryTrie::addNode(std::string word, unsigned int i,
                                  unsigned int freq){
  char c = word[i];
  // This is the begging of our Node chain
  TrieNode* begin = new TrieNode(c);
  // We have another node reference cuz we want to return 
  // the beginnig of Node
  TrieNode* add = begin;
  // Increments i to avoid duplicates
  i++;

  for( ;i<word.length(); i++){
    
    // After every node is made, we put that as mid Node
    // and update add Node to new Node
    c = word[i];
    add->mid = new TrieNode(c);
    add = add->mid;
  }
 
  // We want the update at the end 
  add->freq = freq;
  add->isWord = true;
  return begin;
  

}
/* Insert a word with its frequency into the dictionary.
 * Return true if the word was inserted, and false if it
 * was not (i.e. it was already in the dictionary or it was
 * invalid (empty string) 
 * Return true if the word was inserted, and false if it
 * was not (i.e. it was already in the dictionary or it was
 * invalid (empty string) 
 * 
 * Paremters:
 *     word: string to insert
 *     freq: freq of that string
 *
 */
bool DictionaryTrie::insert(std::string word, unsigned int freq)
{
  // null case of root creates the trie
  if(root==NULL){
    root = addNode(word, 0, freq); 
    return true; 
  }


  TrieNode* curr = root;
  char c;


  for(unsigned int i = 0; i<word.length(); i++ ) {
    c =  word[i];
    // Traversal will either return node that in which 
    // the node's data is equal to the current c
    // Or it will return the last node in which we 
    // add nodes left or right 
    TrieNode* check = traverseTrie(curr, c);

    // For if and else if conditions, we check the node
    // we want to go to, if it's null we create a chain
    // and add it to that spot
    // if not go go to that spot
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

    // If the one we want to go is the mid Node
    // We check to see if we reached the end 
    // Otherwise, we have a null check
    else {
      if(i == word.length()-1) {
        curr = check;
        break;
      }
       else if(check->mid){
        curr = check->mid;
      }
      else{
        // we start at i+1 be the one check is on already
        // is the same letter as word[i]
        check->mid = addNode( word, i+1, freq); 
        return true;
      }
    }
  } 

  // We have gone through every node and now
  // we are at the last node
 
  if(curr->isWord){
    // is there is already a word we will update freq and
    // return false
    curr->freq = freq;
    return false;
  }

  curr->isWord = true;
  return true;
}

/* Return true if word is in the dictionary, and false otherwise 
 * Parameters:
 *     word: string to find, this is const so we don't
 *     accidently mess up the string while searching
 */
bool DictionaryTrie::find(std::string word) const
{
  // Null case
  if(!root){ return false;}

  TrieNode* curr = root;
  char c;

  for(unsigned int i = 0; i < word.length() ; i++)
  {
    c = word[i];
  
    // traversal either returns node with same letter
    // or a null pointer
    TrieNode* check = traverseTrie(curr, c);

    //check if node is supposed to go left or right
    if(c < check->letter) {
      curr = check->left;
    }
   
    else if (check->letter < c) {
      curr = check->right;    
    }

    // Checks if we reached the end of our word first
    // otherwise it updates
    else {
      if(i == word.length()-1) {
        curr = check;
        break;
      }
      else {
        curr = check->mid;
      }
    }
 
    // If curr is null at all then it will return false
    // Otherwise, there will be a seg fault
    if(!curr){ return false;}
  } 

  // After we end up at the node with the last letter of the 
  // word, the bool in that node will tell us if it is a word or not
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
 
/** This is a helper function to the destructor
 *  
 *  Parameter: 
 *      n: this is the root of the trie in which we will
 *      delete all nodes
 *
 *
 *  We will do a recursive post-order traversal 
 *  and this will free all memory
 */
void DictionaryTrie::deleteAll(TrieNode* n)
{
  //base case of recursion 
  if(!n){ return; }
  
  // Recursively visits bottom nodes,
  // and deletes it's way upwards to root
  deleteAll(n->left);
  deleteAll(n->mid);
  deleteAll(n->right);

  delete n;

}
/* Destructor */
DictionaryTrie::~DictionaryTrie(){ deleteAll(root);}



