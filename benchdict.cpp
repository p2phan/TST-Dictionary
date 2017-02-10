#include<iostream>
#include<fstream>
#include "util.h"
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"

using namespace std;

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
     
     if(!dict.is_open())
     {
         cout << "No file was opened. Please try again\n";
         return -1;
         

     }
     
     int NUM = 100;
     int min_size = atoi(argv[1]);
     int step_size = atoi(argv[2]);
     int num_iterations = atoi(argv[3]);
     int repeat = min_size + num_iterations*step_size;
     std::cout << "DictionaryBst" << std::endl;
   /*  for(int i = min_size; i <= repeat; i+=step_size) 
     {
         my_bst = new DictionaryBST();
         if(!dict.is_open()){dict.open(argv[4]);}
         Utils::load_dict(*my_bst, dict, i);
         std::vector<string> v;
         Utils::load_vector(v, dict, NUM);
         
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
         dict.close();
     }
*/
     std::cout << "DictionaryHashtable" << std::endl;
     for(int i = min_size; i <= repeat; i+=step_size) 
     {
         my_ht = new DictionaryHashtable();
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
/*
     std::cout << "DictionaryTrie" << std::endl;
     for(int i = min_size; i <= repeat; i+=step_size) 
     {
         my_t = new DictionaryTrie();
         dict.open(argv[4]);
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
*/


}
