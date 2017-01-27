#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<cstdlib>
#include "util.h"
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"
#define LETTERS 26
using namespace std;


int main(int argc, char** argv)
{

  //Initialize words
  vector<std::string> words;
  vector<string>::iterator wit;
  vector<string>::iterator wen;
  //initialize nonwords
  vector<string> nope;
  vector<string>::iterator nit;
  vector<string>::iterator nen;

  //Initialize data structures
  DictionaryBST d_bst;
  DictionaryHashtable d_ht;
  DictionaryTrie dt;
  int t_bst, t_ht, tt;

  words.push_back("harry");
  words.push_back("sriram");
  words.push_back("cse");
  words.push_back("crucio");
  words.push_back("autocomplete");

  nope.push_back("harr");
  nope.push_back("s");
  nope.push_back("srit");
  nope.push_back("arira");
  nope.push_back("autocar");
  nope.push_back("csr");
  nope.push_back("cr");
  nope.push_back("cru");
  nope.push_back("hca");
  nope.push_back("hcau");
  nope.push_back("cse100");
  
  cout << "Inserting into Dictionaries..." << endl;

  wit = words.begin();
  wen = words.end();
  for(; wit != wen; ++wit)
    {
      cout << "Inserting: \"" << *wit << "\"... ";
      t_bst = d_bst.insert(*wit);
      t_ht = d_ht.insert(*wit);
      tt = dt.insert(*wit, 1);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
      if(!t_bst)
	{
	  cout << "failed for DictionaryBST... ";
	}
      if(!t_ht)
	{
	  cout << "failed for DictionaryHashset... ";
	}
      if(!tt)
	{
	  cout << "failed for DictionaryTrie... ";
	}
      if(t_bst && t_ht && tt)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
    }

  cout << endl << "Re-inserting elements that were just inserted into Dictionaries..." << endl;

  wit = words.begin();
  wen = words.end();
  for(; wit != wen; ++wit)
    {
      cout << "Inserting: \"" << *wit << "\"... ";
      t_bst = d_bst.insert(*wit);
      t_ht = d_ht.insert(*wit);
      tt = dt.insert(*wit, 0);
      if(t_bst)
        {
          cout << "failed for DictionaryBST... ";
        }
      if(t_ht)
        {
          cout << "failed for DictionaryHashset... ";
        }
      if(tt)
        {
          cout << "failed for DictionaryTrie... ";
        }
      if(!t_bst && !t_ht && !tt)
        {
          cout << "PASSED! :D ";
        }
      cout << endl;
    }

  cout << endl;

  
/*You are supposed to add more test cases in this file */
  cout << "Finding words not in dictionary" << endl;
  nit = nope.begin();
  nen = nope.end();
  for(; nit != nen; ++nit)
    {
      cout << "Finding: \"" << *nit << "\"... ";
      t_bst = d_bst.find(*nit);
      t_ht = d_ht.find(*nit);
      tt = dt.find(*nit);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
      if(t_bst)
	{
	  cout << "failed for DictionaryBST... ";
	}
      if(t_ht)
	{
	  cout << "failed for DictionaryHashset... ";
	}
      if(tt)
	{
	  cout << "failed for DictionaryTrie... ";
	}
      if(!t_bst && !t_ht && !tt)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
    }   

  cout << endl;
 

  /* My own testssss*/
  //Initialize words
  vector<std::string> my_words;
  vector<string>::iterator my_wit;
  vector<string>::iterator my_wen;
  //initialize nonwords
  vector<string> my_nope;
  vector<string>::iterator my_nit;
  vector<string>::iterator my_nen;

  //Initialize data structures
  DictionaryBST my_d_bst;
  DictionaryHashtable my_d_ht;
  DictionaryTrie my_dt;
  int my_t_bst, my_t_ht, my_tt;

  //words used from worksheet
  my_words.push_back("apple");
  my_words.push_back("ape");
  my_words.push_back("applet");
  my_words.push_back("cape");
  my_words.push_back("tall");
  my_words.push_back("tap");
  my_words.push_back("tape");
  my_words.push_back("applier");
  my_words.push_back("appliance");
  my_words.push_back("tanline");

  //these words are border and out-of bounds cases
  my_nope.push_back("apes");
  my_nope.push_back("application");
  my_nope.push_back("act");
  my_nope.push_back("acape");
  my_nope.push_back("cap");
  my_nope.push_back("taller");
  my_nope.push_back("talpe");
  my_nope.push_back("applie");
  my_nope.push_back("applian");
  my_nope.push_back("apa");
  my_nope.push_back("capt");
  my_nope.push_back("tapt");

  my_wit = my_words.begin();
  my_wen = my_words.end();


  
  cout << "Inserting into Dictionaries..." << endl;

  for(; my_wit != my_wen; ++my_wit)
    {
      cout << "Inserting: \"" << *my_wit << "\"... ";
      my_t_bst = my_d_bst.insert(*my_wit);
      my_t_ht = my_d_ht.insert(*my_wit);
      my_tt = my_dt.insert(*my_wit, 1);
      //cout << my_t_bst << " " << my_t_ht << " "<< my_tt << "... ";
      if(!my_t_bst)
	{
	  cout << "failed for DictionaryBST... ";
	}
      if(!my_t_ht)
	{
	  cout << "failed for DictionaryHashset... ";
	}
      if(!my_tt)
	{
	  cout << "failed for DictionaryTrie... ";
	}
      if(my_t_bst && my_t_ht && my_tt)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
    }
  
  

  cout << endl << "Re-inserting elements that were just inserted";
  cout << " into Dictionaries..." << endl;

  my_wit = my_words.begin();
  my_wen = my_words.end();
  for(; my_wit != my_wen; ++my_wit)
    {
      cout << "Inserting: \"" << *my_wit << "\"... ";
      my_t_bst = my_d_bst.insert(*my_wit);
      my_t_ht = my_d_ht.insert(*my_wit);
      my_tt = my_dt.insert(*my_wit, 0);
      if(my_t_bst)
        {
          cout << "failed for DictionaryBST... ";
        }
      if(my_t_ht)
        {
          cout << "failed for DictionaryHashset... ";
        }
      if(my_tt)
        {
          cout << "failed for DictionaryTrie... ";
        }
      if(!my_t_bst && !my_t_ht && !my_tt)
        {
          cout << "PASSED! :D ";
        }
      cout << endl;
    }

  cout << endl;

  cout << "Finding words in dictionary" << endl;
  my_wit = my_words.begin();
  my_wen = my_words.end();
  for(; my_wit != my_wen; ++my_wit)
    {
      cout << "Finding: \"" << *my_wit << "\"... ";
      my_t_bst = my_d_bst.find(*my_wit);
      my_t_ht = my_d_ht.find(*my_wit);
      my_tt = my_dt.find(*my_wit);
      //cout << my_t_bst << " " << my_t_ht << " "<< my_tt << "... ";
      if(!my_t_bst)
	{
	  cout << "failed for DictionaryBST... ";
	}
      if(!my_t_ht)
	{
	  cout << "failed for DictionaryHashset... ";
	}
      if(!my_tt)
	{
	  cout << "failed for DictionaryTrie... ";
	}
      if(my_t_bst && my_t_ht && my_tt)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
    }
 
  cout << endl;
 
 
  cout << "Finding words not in dictionary" << endl;
  my_nit = my_nope.begin();
  my_nen = my_nope.end();
  for(; my_nit != my_nen; ++my_nit)
    {
      cout << "Finding: \"" << *my_nit << "\"... ";
      my_t_bst = my_d_bst.find(*my_nit);
      my_t_ht = my_d_ht.find(*my_nit);
      my_tt = my_dt.find(*my_nit);
      //cout << my_t_bst << " " << my_t_ht << " "<< my_tt << "... ";
      if(my_t_bst)
	{
	  cout << "failed for DictionaryBST... ";
	}
      if(my_t_ht)
	{
	  cout << "failed for DictionaryHashset... ";
	}
      if(my_tt)
	{
	  cout << "failed for DictionaryTrie... ";
	}
      if(!my_t_bst && !my_t_ht && !my_tt)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
    }   






  
  return 0;
}
