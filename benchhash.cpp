#include<iostream>
#include<fstream>
#include "util.h"
/**
 * File name: benchhash.cpp
 * Date: 9 February 2016
 * Author: Peter Phan, cs100wdh, A13042904
 *
 * Purpose: Benchmarking different 2 types of Hashfunctions
 * and prints out collision, and average number of steps
 * to find a word in the hashtable
 */


using namespace std;
/**
 * Prints out collsions for different implementation of hashtables
 * Also tests for correct implementation of a hashtable
 *
 * Parameters: argc: number of arguments
 *             argv[]: array of passed in string from command line
 */
int main(int argc, char* argv[])
{
    //Checks arguments
    if(argc !=3 ){
        cout << "Invalid input. Form is "
             << "./benchhash dictfile num_words\n"
             << "dictfile: dictionary file\n"
             << "num_words: number of dictionary words to be inserted\n";
    }
    
    
    ifstream dict;
    dict.open(argv[1]);

    //file check    
    if(!dict.is_open())
    {
        cout << "No file was opened. Please try again\n";
        return -1; 
    }

    //uploads dictionary words into a vector
    vector<string> words;     
    int num_words = atoi(argv[2]);
    Utils::load_vector(words, dict, num_words);
    dict.close();

    cout << "Printing the statistics for hashFunction1 with hash table size "
          << num_words*2 << endl;
     
   // The first hash function used is from
   // http://www.cse.yorku.ca/~oz/hash.html
   // it's called djb and the author believes 
   // it's one of the best hash function
   vector<int> collisions1(num_words*2, 0);
    for(string s: words)
    {
        unsigned long key = 5381;
        for( int i = 0; (unsigned int) i < s.length(); i++){
            int c = s[i];
            // key * 33 +c
            // recursively:key(i) = key(i-1)*33 + c
            key = ((key << 5) + key) + c;
	}
            
        key = key % collisions1.size();
        collisions1[key]++;

    }

    // finding max collisions in the vector
    int max = 0;
    for(int i = 0; (unsigned int)i < collisions1.size(); i++)
    {
        if(max < collisions1.at(i))
            max = collisions1.at(i);
    }

    //Goes through int vector and the number at i will be counted
    //towards number of collisions in arr
    int average = 0;
    int arr[max+1];

    //initilize array to 0's
    for(int i =0; i < max + 1; i++)
    {
        arr[i]=0;   
    }  

    for(int i = 0; (unsigned int)i < collisions1.size(); i++)
    {
        arr[collisions1.at(i)]++;           
    }


    //calculates average and prints out the collions
    cout << "#hits\t#slots receiving #hits" << endl;
    for(int i = 0; i < max + 1; i++){

        cout << i << "\t" << arr[i] << endl;
        int colInAStep = 0;

        //follows sum(i to end)*i logic
        for(int j = i; j < max + 1; j++){
            colInAStep += arr[j];
        }
        average += colInAStep*i;

    }
    
    // average is sum(sum(i to end)*i) from 0 to end
    // divided by number of words
    double avg = (double)average / (double)num_words; 
    cout << "The average number of steps for a successful search "
         << "for hash function 1 would be " << avg << endl;
            
    cout << "The worst case steps that would be needed to find a word is "
         << max << endl;


    
    cout << "Printing the statistics for hashFunction2 " << endl;

    //http://www.eternallyconfuzzled.com/tuts/algorithms/jsw_tut_hashing.aspx
    //This is the Shift-Add-XOR hash function 
    vector<int> collisions2(num_words*2, 0);
    for(string s: words)
    {
        unsigned long key = 0;
        for( int i = 0; (unsigned int) i < s.length(); i++){
            unsigned int c = s[i];
            key ^= ((key << 5) + (key >> 2)) + c;
	}
            
        key = key % collisions2.size();
        collisions2[key]++;

    }
     

    //finding max number of collsions
    max = 0;
    for(int i = 0; (unsigned int)i < collisions2.size(); i++)
    {
        if(max < collisions2.at(i))
            max = collisions2.at(i);
    }


    //determining how many of each collsions in hashtab;e
    average = 0;
    int arr2[max+1];
    for(int i =0; i < max + 1; i++)
    {
        arr2[i]=0;
    } 

    //adds up total of certain number of collisions in collisions2
    for(int i = 0; (unsigned int)i < collisions2.size(); i++)
    {
        arr2[collisions2.at(i)]++;
           
    }

    //caluclating average and printing out collisions results
    cout << "#hits\t#slots receiving #hits" << endl;
    for(int i = 0; i < max + 1; i++){
        cout << i << "\t" << arr2[i] << endl;
        int colInAStep = 0;
        for(int j = i; j < max + 1; j++){
            colInAStep += arr2[j];
        }
        average += colInAStep*i;
    }
    
    avg = (double)average / (double)num_words; 
    cout << "The average number of steps for a successful search "
         << "for hash function 1 would be " << avg << endl;
            
    cout << "The worst case steps that would be needed to find a word is "
         << max << endl;
 

    /*Tests for hashfunction*/
    vector<string> v;
    v.push_back("to");
    v.push_back("and");
    v.push_back("Or");
    cout << "Testing hash function1" << endl;
    
    for( string s: v){
        unsigned long key = 5381;
        for( int i = 0; (unsigned int) i < s.length(); i++){
            int c = s[i];
            //key * 33 +c
            key = ((key << 5) + key) + c;
        }
        //keys will be printed so that viewer can compare with their own answer   
        cout << "The hash value for " << s << " is " << key << endl;

    }
    

    cout << "Testing hash function2" << endl;
    for(string s: v)
    {
        unsigned long key = 0;
        for( int i = 0; (unsigned int) i < s.length(); i++){
            unsigned int c = s[i];
            key ^= ((key << 5) + (key >> 2)) + c;
	}
            
        cout << "The hash value for " << s << " is " << key << endl;

    }
}
