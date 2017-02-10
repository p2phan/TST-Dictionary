#include<iostream>
#include<fstream>
#include "util.h"
//
//


using namespace std;

int main(int argc, char* argv[]){

    if(argc !=3 ){
        cout << "Invalid input. Form is "
             << "./benchhash dictfile num_words\n"
             << "dictfile: dictioanry file\n"
             << "num_words: number of dictionary words to be inserted\n";
    }
    
    ifstream dict;
    dict.open(argv[1]);
    
    if(!dict.is_open())
    {
        cout << "No file was opened. Please try again\n";
        return -1; 
    }

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
   // most of the code will be copied

   vector<int> collisions1(num_words*2, 0);
    for(string s: words)
    {
        unsigned long key = 5381;
        for( int i = 0; (unsigned int) i < s.length(); i++){
            int c = s[i];
            //key * 33 +c
            key = ((key << 5) + key) + c;
	}
            
        key = key % collisions1.size();
        collisions1[key]++;

    }

    int max = 0;
    for(int i = 0; (unsigned int)i < collisions1.size(); i++)
    {
        if(max < collisions1.at(i))
            max = collisions1.at(i);

    }


    
    int average = 0;
    int arr[max+1] = {0};
    for(int i = 0; (unsigned int)i < collisions1.size(); i++)
    {
        arr[collisions1.at(i)]++;
           
    }

    cout << "#hits\t#slots receieving #hits" << endl;


    for(int i = 0; i < max + 1; i++){
        cout << i << "\t" << arr[i] << endl;
        int colInAStep = 0;
        for(int j = i; j < max + 1; j++){
            colInAStep += arr[j];
        }
        average += colInAStep*i;
    }
    
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
     
    max = 0;
    for(int i = 0; (unsigned int)i < collisions2.size(); i++)
    {
        if(max < collisions2.at(i))
            max = collisions2.at(i);

    }


    
    average = 0;
    int arr2[max+1] = {0};
    for(int i = 0; (unsigned int)i < collisions2.size(); i++)
    {
        arr2[collisions2.at(i)]++;
           
    }

    cout << "#hits\t#slots receieving #hits" << endl;

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
 
}
