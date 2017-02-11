#include<iostream>
#include<fstream>
#include "util.h"
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"

/**
 * File name: benchdict.cpp
 * Date: 9 February 2016
 * Author: Peter Phan, cs100wdh, A13042904
 *
 * Purpose: Benchmarks DictionaryTrie/BST/HashTable for 
 * running times of find function and prints out results 
 */


using namespace std;

/**
 * Prints out runtime of find function for each dictionary 
 * with different sizes each time
 *
 * Parameters: argc: number of arguments
 *             argv[]: array of passed in string from command line
 */
int main(int argc, char* argv[])
{
    //Checks argument
    if(argc != 5) {
        cout << "Invalid number of arguments.\n" 
             << "Usage: ./benchdict min_size step_size num iterations dictfile"
             << "\nminsize: minimum size of dictionary\n"
             << "step_size: how much to inc dictionary each iteration\n"
             << "num_iterations: number of times to increase"
             << " dictionary size \n"
             << "dictfile: name of dictionary file\n";
         return -1;
     }

     DictionaryBST* my_bst;
     DictionaryHashtable* my_ht;
     DictionaryTrie* my_t;

     std::ifstream dict;
     dict.open(argv[4]);
 
     //file check    
     if(!dict.is_open())
     {
         cout << "No file was opened. Please try again\n";
         return -1;
         

     }
     
     
     int NUM = 100;  //number of words not in dictionary to find
     int min_size = atoi(argv[1]); //start size of Dictionary 
     int step_size = atoi(argv[2]);//incrementation of Dictionary
     int num_iterations = atoi(argv[3]);//number of times Dictionary increases
     //max size of Dictionary storage
     int repeat = min_size + num_iterations*step_size; 

     //benchmarking BST
     std::cout << "DictionaryBst" << std::endl;
     for(int i = min_size; i < repeat; i+=step_size) 
     {

         my_bst = new DictionaryBST();
      
         if(!dict.is_open()){dict.open(argv[4]);}

         Utils::load_dict(*my_bst, dict, i);
         std::vector<string> v;
         //after inserting into the tree, we load the next 100
         //words into a vector that will be searched for in the BST
         Utils::load_vector(v, dict, NUM);
         
         //repeat searches to make sure the average is reliable
         long average = 0;
         for(int i = 0; i < 100; i++)
         {
             for( string &search : v)
             {
                 Timer t;
                 t.begin_timer();
                 my_bst->find(search);
                 average += t.end_timer();
             }

         }

         std::cout << i << "\t" << average / (100*v.size()) << std::endl;
         delete my_bst;
         //close dictionary to start over from the beginning of file
         dict.close();
     }

     //benchmark for DictionaryHasTable follows same logic as BST
     std::cout << "DictionaryHashtable" << std::endl;
     for(int i = min_size; i < repeat; i+=step_size) 
     {
         my_ht = new DictionaryHashtable();

         //open file check
         if(!dict.is_open()){dict.open(argv[4]);}

         Utils::load_dict(*my_ht, dict, i);
         std::vector<string> v;
         Utils::load_vector(v, dict, NUM);
         
         long average=0;
         for(int i = 0; i < 100; i++)
         {
             Timer t;
             for( string &search : v)
             {
                 t.begin_timer();
                 my_ht->find(search);
                 average += t.end_timer();      
             }

         }

         std::cout << i << "\t" << average / (100*v.size()) << std::endl;
         delete my_ht;
         dict.close();
     }

     //benchmarking DictionaryTrie follows same logic as other two
     std::cout << "DictionaryTrie" << std::endl;
     for(int i = min_size; i < repeat; i+=step_size) 
     {
         my_t = new DictionaryTrie();

         //open file check
         if(!dict.is_open()){dict.open(argv[4]);}

         Utils::load_dict(*my_t, dict, i);
         std::vector<string> v;
         Utils::load_vector(v, dict, NUM);
         
         long average = 0;
         for(int i = 0; i < 100; i++)
         {
             Timer t;
             for( string &search : v)
             {
                 t.begin_timer();
                 my_t->find(search);
                 average += t.end_timer();      
             }

         }

         std::cout << i << "\t" << average / (100*v.size()) << std::endl;
         delete my_t;
         dict.close();
     }

}
